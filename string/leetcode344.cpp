#include "../common.h"

class Solution {
public:
// 原地反转字符
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (right > left) {
            char ch = s[right];
            s[right--] = s[left];
            s[left++] = ch;
        }
    }
};