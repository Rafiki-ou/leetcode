#include "../common.h"

#if 0
class Solution {
public:
// 消除相邻重复元素
    string removeDuplicates(string s) {
        stack<char> aux;
        for (int i = 0; i < s.size(); ) 
            // 如果栈为空或者栈顶元素和当前元素不相同，直接入栈
            if (aux.empty() || aux.top() != s[i])  aux.push(s[i++]);
            else {
                s.erase(--i, 2);
                aux.pop();
                // 删除之后需要判断栈中的上面两个元素是否相同
                if (aux.size() >1) {
                    char ch = aux.top();
                    aux.pop();
                    if(ch == aux.top()) {
                        s.erase(--i, 2);
                    }
                    else {
                        aux.push(ch);
                    }
                }
            }
        return s;
    }
};

#else
class Solution {
public:
// 消除相邻重复元素
    string removeDuplicates(string s) {
        stack<char> aux;
        for (char ch : s) {
            if (aux.empty() || aux.top() != ch) 
                aux.push(ch);
            else 
                aux.pop();
        }
        string res = "";
        while (!aux.empty()) {
            char ch = aux.top();
            res.insert(0,1,ch);
            aux.pop();
        }
        return res;
    }
};
#endif
int main()
{
    Solution s;
    cout << s.removeDuplicates("azxxzy");
    cout << std::stoi("123");
}