#include "../common.h"


class MyQueue {
public:
    MyQueue() {

    }
    
    void push(int x) {
        in_stack.push(x);
    }
    
    int pop() {
        if (out_stack.empty())
            while (!in_stack.empty()) {
                out_stack.push(in_stack.top());
                in_stack.pop();
            }
        int tmp = out_stack.top();
        out_stack.pop();
        return tmp;
    }
    
    int peek() {
      int tmp = pop();
      out_stack.push(tmp);
      return tmp;
    }
    
    bool empty() {
        return out_stack.empty() && in_stack.empty();
    }
private:
    stack<int> in_stack;
    stack<int> out_stack;
};

int main()
{
    MyQueue* obj = new MyQueue();
    obj->push(2);
    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();
}

