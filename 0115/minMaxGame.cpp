#include "../common/common.h"
/**
 * 极大极小游戏
 * url:https://leetcode.cn/problems/min-max-game/
*/

class Solution {
public:
#if 0
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        while(n > 1)
        {
            vector<int> newNums(n / 2);
            for(int i = 0; i < n / 2; ++i)
                newNums[i] = i % 2 == 0 ? min(nums[2 * i], nums[2*i + 1]) : max(nums[2*i], nums[2*i + 1]);
            nums = newNums;
            n = nums.size();
        }
        return nums[0];
    }
#endif

    // 原地修改
     int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        while(n > 1)
        {
            for(int i = 0; i < n / 2; ++i)
                nums[i] = i % 2 == 0 ? min(nums[2 * i], nums[2*i + 1]) : max(nums[2*i], nums[2*i + 1]);
            n /= 2;
        }
        return nums[0];
    }

};

int main()
{
   vector<int>v{1,3,5,2,4,8,2,2};
   Solution s;
   cout << s.minMaxGame(v); 
}