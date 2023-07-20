#include "../common.h"

class MyStack {
public:
    MyStack() {

    }
    
    void push(int x) {
        orginal.push(x);
    }
    
    int pop() {
        while (orginal.size() > 1) {
            backup.push(orginal.front());
            orginal.pop();
        }
        int tmp = orginal.front();
        orginal.pop();
        while (!backup.empty()) {
            orginal.push(backup.front());
            backup.pop();
        }
        return tmp;
    }
    
    int top() {
        int tmp = pop();
        orginal.push(tmp);
        return tmp;
    }
    
    bool empty() {
        return orginal.empty();
    }
private:    
    queue<int> orginal;
    queue<int> backup;
};