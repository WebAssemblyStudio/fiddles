#include <stdio.h>
#include <experimental/coroutine>
#include <thread>

#include <iostream>
#include <utility>
#include <optional>

#include <thread>

#include <emscripten.h>

namespace std {
  using namespace std::experimental;
}

struct timer_task {
  int milliSeconds;
};

template <class T>
struct task {
  struct promise_type {
    T value_;

    auto get_return_object() { return task{*this}; }
    auto initial_suspend() { return std::suspend_never{}; }
    auto final_suspend() noexcept { return std::suspend_always{}; }
    void return_value(T x) { value_ = x; }
    void yield_value(T x) { value_ = x; }
    void unhandled_exception() { std::terminate(); }

    auto await_transform(timer_task _task)
    {
      struct awaiter {
        struct await_callback {
          std::experimental::coroutine_handle<> co;
          awaiter& waiter;

          await_callback(std::experimental::coroutine_handle<> _co, awaiter& _waiter) : 
            co(_co),
            waiter(_waiter)
          {}

          static void awake_and_delete(void* that)
          {
            auto awaker = static_cast<await_callback*>(that);
            awaker->awake_internal();
            delete awaker;
          }
        private:
          void awake_internal()
          {
            co.resume();
          }
        };

        awaiter(timer_task _timer) :
          timer(_timer) {}

        bool await_ready() { return false; }
        void await_suspend(std::experimental::coroutine_handle<> co) {
          emscripten_async_call(&await_callback::awake_and_delete, new await_callback(co, *this), timer.milliSeconds);
        }
        void await_resume() {}

      private:
        timer_task timer;
      };
      return awaiter{ _task };
    }
  };

  task(task const&) = delete;
  task(task&& rhs)
    : coro_(std::exchange(rhs.coro_, nullptr)) {}

private:
  explicit task(promise_type& p)
    : coro_(std::coroutine_handle<promise_type>::from_promise(p)) {}

  std::coroutine_handle<promise_type> coro_;
};

task<int> f()
{
  std::cout << "beginning of coroutine" << std::endl;
  const std::thread::id main_tid = std::this_thread::get_id();
  co_await timer_task { 1500 };
  std::cout << "thread id (in f):" << main_tid << std::endl;
  co_return 0;
}

int main()
{
  auto c = f();
  std::cout << "main" << std::endl;
  const std::thread::id main_tid = std::this_thread::get_id();
  std::cout << "thread id (in main):" << main_tid << std::endl;
}