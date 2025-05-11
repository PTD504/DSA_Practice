#include <iostream>
#include <vector>
#include <utility>

class MinStack {
private:
    
    std::vector<std::pair<int, int> > container;
    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (container.size() == 0) {
            container.push_back({val, val});
        }
        else {
            int mn = container.back().second;
            container.push_back({val, std::min(mn, val)});
        }
    }
    
    void pop() {
        container.pop_back();
    }
    
    int top() {
        return container.back().first;
    }
    
    int getMin() {
        return container.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */