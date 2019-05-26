#define WASM_EXPORT __attribute__((visibility("default")))

#include <queue>
WASM_EXPORT
int main() {
    std::priority_queue<int> q;
    q.push(12);
    return q.top();
}
