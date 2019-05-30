#define WASM_EXPORT __attribute__((visibility("default")))
#include <queue>
#include <vector>
#include <cstdio>


extern "C" void putc_js(char c);

void puts_js(char* c){
    char * t; // first copy the pointer to not change the original
    for (t = c; *t != '\0'; t++) {
        putc_js(*t);
    }
    putc_js('\n');
}


enum OrderSide { SELL_SIDE=0, BUY_SIDE};

class Order { 
    public: 
    int price, quantity;  
    OrderSide side;
      
    Order(int o_price, int o_quantity, OrderSide o_side){ 
        price = o_price;
        quantity = o_quantity;
        side = o_side;
    } 
}; 


class OrderComparator
{
public:
    bool operator() (Order const& o1, Order const& o2)
    {
        //assuming both orders in the same side
        if(o1.side == BUY_SIDE){
          return o1.price < o2.price;
        } else{
          return o1.price > o2.price;
        }
    }
};


std::priority_queue<Order, std::vector<Order>, OrderComparator> sell_queue;
std::priority_queue<Order, std::vector<Order>, OrderComparator> buy_queue;

int best_bid(){
    if(buy_queue.empty()){
      return 0;
    } else{
      return buy_queue.top().price;
    }
}

int best_ask(){
    if(sell_queue.empty()){
      return 0;
    } else{
      return sell_queue.top().price;
    }
}    

int best_bid_qty(){
    if(buy_queue.empty()){
      return 0;
    } else{
      return buy_queue.top().quantity;
    }
}

int best_ask_qty(){
    if(sell_queue.empty()){
      return 0;
    } else{
      return sell_queue.top().quantity;
    }
}        

void add_order(int price, int quantity, int side){
  Order order(price, quantity, side == 0 ? SELL_SIDE : BUY_SIDE);
  char log[32];
  if(order.side == SELL_SIDE){
    sell_queue.push(order);
  } else{
    buy_queue.push(order);
  }
  sprintf(log, "add %d %d %s", order.price, order.quantity, order.side == BUY_SIDE ? "buy" : "sell");
  puts_js(log);
  sprintf(log, "chk %d %d %d %d %d %d", sell_queue.size(), best_ask(), best_ask_qty(), buy_queue.size(), best_bid(), best_bid_qty());
  puts_js(log);
}
  
WASM_EXPORT
int main() {
    add_order(8000, 1, 0);
    add_order(7000, 2, 1); 
    return 0;
}

