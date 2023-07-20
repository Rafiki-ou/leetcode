#include "../common.h"

#if 1
class Solution {
public:
//在已有基础上删除能组成队的
    bool isValid(string s) {
        stack<char> aux;
        aux.push(s[0]);
        for (int i = 1; i < s.size(); ++i) {    
            if (!aux.empty() && (s[i] == ']' && aux.top() == '[' || s[i] == ')' && aux.top() == '(' || s[i] == '}' && aux.top() == '{')) aux.pop();
            else
                aux.push(s[i]);
        }
        return aux.empty();
    }
};
#else

#endif

int main()
{
    Solution s;
    s.isValid("()[]{}");
}