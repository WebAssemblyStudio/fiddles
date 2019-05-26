#define WASM_EXPORT __attribute__((visibility("default")))
#include <queue>
#include <vector>

struct Person { 
    int age;    
    Person(int age) : age(age)
    { 
    } 
}; 
  
struct ComparePerson { 
    bool operator()(Person const& p1, Person const& p2) 
    { 
        return p1.age > p2.age; 
    } 
}; 
  
WASM_EXPORT
int main() {
    std::priority_queue<Person, std::vector<Person>, ComparePerson> q; 
    q.push(Person(12)); 
    q.push(Person(16)); 
    return q.top().age;
}
