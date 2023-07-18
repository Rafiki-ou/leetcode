#include "../common.h"

class Solution {
public:
    string reverseStr(string s, int k) {
        int cnt = 1;
        for (int i = 0; i < s.length(); i += (2 * k)) {
           // 每隔2k个字符前k个字符进行反转
           // 剩于<=2k || ==k  反转前k个
            if (i + k <= s.size())  
                reverse(s.begin()+i, s.begin() + i + k);
            else
            // 剩下全部反转
                reverse(s.begin() + i, s.end());
        }
        return s;
    }
};