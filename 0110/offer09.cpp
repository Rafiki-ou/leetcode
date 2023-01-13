/**
 * 用2个栈实现队列
*/

#include "../common/common.h"
class CQueue {
public:
    CQueue() {
        first_stack = new stack<int>();
        second_stack = new stack<int>();
    }

    ~CQueue() {
        delete first_stack;
        delete second_stack;
        first_stack = nullptr;
        second_stack = nullptr;
    }
    
    void appendTail(int value) {
        first_stack->push(value);
    }
    
    int deleteHead() {
        if(second_stack->empty())
        {
            if (first_stack->empty())
            {
                return -1;
            }
            else 
            {
                while (!first_stack->empty())
                {
                    second_stack->push(first_stack->top());
                    first_stack->pop();
                }
                int tmp = second_stack->top();
                second_stack->pop();
                return tmp;
            } 
        }
        else
        {
            int tmp = second_stack->top();
            second_stack->pop();
            return tmp;
        } 
    }

private:
    stack<int>* first_stack;
    stack<int>* second_stack;
};

int main()
{
    CQueue* obj = new CQueue();
    obj->appendTail(1);
    obj->appendTail(2);
    obj->appendTail(3);
    cout << obj->deleteHead() << endl;
    obj->appendTail(4);
    delete obj;
    obj = nullptr;

}