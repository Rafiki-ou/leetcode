#include "../common.h"

#if 0
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        return  s.substr(n,s.size() - n) + s.substr(0,n);
    }
};
#else
// 花式反转，再局部反转,原地修改
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int left = 0, right = s.length() - 1;
        reverse(s, left, right);
        left = 0;
        right = s.size() - n - 1;
        reverse(s, left, right);
        left = s.size() - n;
        right = s.size() - 1;
        reverse(s, left, right);
        return s;
    }

private:
    void reverse(string& s, int left, int right) {
        while (right > left) {
            char ch = s[right];
            s[right--] = s[left];
            s[left++] = ch;
        }
    }
};
#endif
