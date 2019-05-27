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

void emit(int price, int quantity, OrderSide side){
    char log[50];
    sprintf(log, "%d %d %s", price, quantity, side == BUY_SIDE ? "buy" : "sell");
    puts_js(log);
}

class OrderBook { 

private:
    std::priority_queue<Order, std::vector<Order>, OrderComparator> sell_queue;
    std::priority_queue<Order, std::vector<Order>, OrderComparator> buy_queue;
public: 
    void add(Order order){
        if(order.side == SELL_SIDE){
            while(!buy_queue.empty() && order.quantity>0 && order.price <= buy_queue.top().price){
                Order matched_order = buy_queue.top();
                buy_queue.pop();
                int matched_quantity = order.quantity < matched_order.quantity ? order.quantity : matched_order.quantity;
                order.quantity -= matched_quantity;
                matched_order.quantity -= matched_quantity;
                emit(order.price, matched_quantity, order.side);
                if(matched_order.quantity > 0){
                    buy_queue.push(matched_order);
                }
                // printf("status: %d %d %d\n", buy_queue.empty(), order.quantity, buy_queue.top().price);
            }
            if(order.quantity > 0){
                sell_queue.push(order);
            } 
        } else{
            while(!sell_queue.empty() && order.quantity>0 && order.price >= sell_queue.top().price){
                Order matched_order = sell_queue.top();
                sell_queue.pop();
                int matched_quantity = order.quantity < matched_order.quantity ? order.quantity : matched_order.quantity;
                order.quantity -= matched_quantity;
                matched_order.quantity -= matched_quantity;
                emit(order.price, matched_quantity, order.side);
                if(matched_order.quantity > 0){
                    sell_queue.push(matched_order);
                }
            }
            if(order.quantity > 0){
                buy_queue.push(order);
            }
        }
    }

    Order best_bid(){
        return buy_queue.top();
    }
}; 



  
WASM_EXPORT
int main() {
    OrderBook book;
    book.add(Order(8000, 1, SELL_SIDE));
    book.add(Order(7000, 2, BUY_SIDE)); 
    book.add(Order(7500, 2, BUY_SIDE)); 
    book.add(Order(7500, 1, SELL_SIDE)); 
    book.add(Order(7000, 2, SELL_SIDE)); 
    return book.best_bid().quantity;
}
