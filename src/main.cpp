#define WASM_EXPORT __attribute__((visibility("default")))
#include <queue>
#include <vector>
#include <cstdio>
#include <string>

using namespace std;

// void putc_js(char c){
//     printf("%c", c);
// }
// void puts_js(char* c){
//     char * t; // first copy the pointer to not change the original
//     for (t = c; *t != '\0'; t++) {
//         putc_js(*t);
//     }
//     putc_js('\n');
// }

typedef uint8_t byte_t;
extern "C" byte_t* alloc_mem(int);
extern "C" byte_t* get_storage(byte_t*);
extern "C" void set_storage(byte_t*, byte_t*);
extern "C" void print_bytes(int, byte_t*);

//////////// inline implementation
// map<string, byte_t*> lookupTable;
// byte_t* get_storage(string key){
//     return lookupTable[key];
// }

// void set_storage(string key, byte_t* value){
//     lookupTable[key] = value;
// }

///////////

enum OrderSide { SELL_SIDE=0, BUY_SIDE};

inline byte_t* strbytes(const char *s){
  byte_t* ret = alloc_mem(32);
  memcpy(ret, s, 32);
  return ret;
}

void emit(int price, int quantity, OrderSide side){
    char log[32];
    sprintf(log, "match %d %d %s", price, quantity, side == BUY_SIDE ? "buy" : "sell");
    print_bytes(0, strbytes(log));

}

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


class OrderBook { 
private: 
  priority_queue<Order, vector<Order>, OrderComparator> sell_queue;
  priority_queue<Order, vector<Order>, OrderComparator> buy_queue;   
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

    int size(){
        return sell_queue.size() + buy_queue.size();
    }
    
    Order popAny(){
        if(!sell_queue.empty()){
            Order order = sell_queue.top();
            sell_queue.pop();
            return order;
        } else{
            Order order = buy_queue.top();
            buy_queue.pop();
            return order;
        }
    }

    byte_t* to_bytes();
}; 


byte_t* int_to_bytes(int n){
    byte_t* bytes = alloc_mem(4);
    memcpy(bytes, (byte_t*)&n, 4);
    return bytes;
}

int int_from_bytes(byte_t* bytes){
  if(bytes==0){
    return 0;
  }
  return *(int *)bytes;
}

byte_t* order_to_bytes(Order order){
    byte_t* bytes = alloc_mem(sizeof(Order));
    int side = order.side == SELL_SIDE ? 0 : 1;
    memcpy(bytes, (byte_t*)&(order.price), 4);
    memcpy(&bytes[4], (byte_t*)&(order.quantity), 4);
    memcpy(&bytes[8], (byte_t*)&(side), 4);
    return bytes;
}

Order order_from_bytes(byte_t* bytes){
    int price = *(int *)bytes;
    int quantity = *(int *)&bytes[4];
    int side_n = *(int *)&bytes[8];
    OrderSide side = side_n == 0 ? SELL_SIDE : BUY_SIDE;
    return Order(price, quantity, side);
}

byte_t* OrderBook::to_bytes(){
    int size = this->size();
    int jump_size = sizeof(Order);
    byte_t* bytes = alloc_mem(size*jump_size);
    for(int i=0; i<size*jump_size; i+=jump_size){
        Order order = this->popAny();
        memcpy(&bytes[i], order_to_bytes(order), jump_size);
    }
    return bytes;
}

OrderBook get_book(){
    int book_size = int_from_bytes(get_storage(strbytes("book_size")));
    byte_t* serialized_book = get_storage(strbytes("order_book"));
    int jump_size = sizeof(Order);

    OrderBook book;

    for(int i=0; i<book_size*jump_size; i+=jump_size){
        Order order = order_from_bytes(&serialized_book[i]);
        book.add(order);
    }
    return book;
}

void set_book(OrderBook book){
    int book_size = book.size();
    byte_t* bytes = book.to_bytes();
    set_storage(strbytes("book_size"), int_to_bytes(book_size));
    set_storage(strbytes("order_book"), bytes);
}

OrderBook book;

WASM_EXPORT
extern "C" int add_order(int price, int quantity, int side){
    Order order(price, quantity, side == 0 ? SELL_SIDE : BUY_SIDE);
    OrderBook book = get_book();
    book.add(order);
    set_book(book);
    return book.size();
}
