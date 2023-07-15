#include "../common.h"
#if 0
class Solution {
public:
    bool isHappy(int n) {
       unordered_set<int> s;
       while(true) {
           // 各位数之和为1
           if( (n = getSum(n)) == 1)   return true;
           // 各位数之和不和1，并且再次出现已经存在集合中的数的话，说明开始了无限循环，说明这个数不是快乐数
           if(s.find(n) != s.end()) return false;
           else s.insert(n);
       }
    }
private:
    int getSum(int n) {
        int sum = 0;
        while(n) {
            sum += pow(n % 10, 2);
            n /= 10;
        }
        return sum;
    }
};
#else

#endif