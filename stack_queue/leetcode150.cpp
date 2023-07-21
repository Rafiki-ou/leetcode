#include "../common.h"

#if 1
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> aux;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                long long rop = aux.top();
                aux.pop();
                long long lop = aux.top();
                aux.pop();
                if (tokens[i] == "+") aux.push(lop+rop);
                else if (tokens[i] == "-") aux.push(lop - rop);
                else if (tokens[i] == "*") aux.push(lop * rop);
                else aux.push(lop / rop);
            }
            else {
                
                aux.push(std::stoll(tokens[i]));
            }
        }
        return aux.top();
    }
};

#else
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // 力扣修改了后台测试数据，需要用longlong
        stack<long long> st; 
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                if (tokens[i] == "+") st.push(num2 + num1);
                if (tokens[i] == "-") st.push(num2 - num1);
                if (tokens[i] == "*") st.push(num2 * num1);
                if (tokens[i] == "/") st.push(num2 / num1);
            } else {
                st.push(stoll(tokens[i]));
            }
        }

        int result = st.top();
        st.pop(); // 把栈里最后一个元素弹出（其实不弹出也没事）
        return result;
    }
};

#endif

int main()
{
    Solution s;
    vector<string> v{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << s.evalRPN(v);
}