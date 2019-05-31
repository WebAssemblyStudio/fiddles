#define WASM_EXPORT __attribute__((visibility("default")))
#include <queue>
#include <vector>
#include <cstdio>


typedef uint8_t byte_t;

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

void add_order(int price, int quantity, int side){
  Order order(price, quantity, side == 0 ? SELL_SIDE : BUY_SIDE);
  if(order.side == SELL_SIDE){
    sell_queue.push(order);
  } else{
    buy_queue.push(order);
  }
}

WASM_EXPORT
int main() {
    add_order(8000, 1, 0);
    add_order(7000, 2, 1); 
    return sell_queue.top().price + buy_queue.top().price;
}

