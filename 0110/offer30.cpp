/**
 * 包含min函数的栈
*/

#include "../common/common.h"
// class MinStack {
// public:
//     /** initialize your data structure here. */
//     MinStack() {
//         m_stack = new stack<int>();
//         m_min = new stack<int>();
//         m_min->push(INT_MAX);
//     }

//     ~MinStack() {
//         delete m_stack;
//     }
    
//     void push(int x) {
//         m_stack->push(x);
//         //int min = m_min->top() < x ? m_min->top() : x;
//         //m_min->push(min);
//         if(x < m_min->top())
//             m_min->push(x);
//     }
    
//     void pop() {
//         if(!m_stack->empty())
//         {
//             if(m_stack->top() == m_min->top())
//                 m_min->pop();
//             m_stack->pop();
//         }
//     }
    
//     int top() {
//         return m_stack->top();
//     }
    
//     int min() {
//         return m_min->top();
//     }

// private:
//     stack<int>* m_stack;
//     stack<int>* m_min;
// };


class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        m_stack = new stack<int>();
        m_min = new stack<int>();
    }

    ~MinStack() {
        delete m_stack;
    }
    
    void push(int x) {
        if(m_min->empty())
        {
            m_min->push(x);
        }
        else
        {
            //int min = m_min->top() < x ? m_min->top() : x;
            //m_min->push(min);
            if(x <= m_min->top())
                m_min->push(x);
        }
        m_stack->push(x);
    }
    
    void pop() {
        if(!m_stack->empty())
        {
            if(m_stack->top() == m_min->top())
                m_min->pop();
            m_stack->pop();
        }
    }
    
    int top() {
        return m_stack->top();
    }
    
    int min() {
            return m_min->top();
    }

private:
    stack<int>* m_stack;
    stack<int>* m_min;
};
int main() {
    MinStack* obj = new MinStack();
    obj->push(0);
    obj->push(-1);
    obj->push(2);
    cout << obj->min() << endl;
    obj->push(-5);
    obj->push(6);
    cout << obj->min() << endl;
    delete obj;
    obj = nullptr;
}