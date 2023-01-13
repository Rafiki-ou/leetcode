#include "../common/common.h"

/**
 * 找出数组中重复的数字。
 * 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
 * 数组中某些数字是重复的，但不知道有几个数字重复了，
 * 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
*/
class Solution {
public:
#if 0
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> set;
        for(int& val : nums)
        {
            // 找到重复的元素
            if(set.count(val) != 0)
                return val;
            // 遍历过后就将其插入的集合中
            set.insert(val);
        }
        return 0;
    }
#endif 

    // 原地交换法 充分利用n个数的大小在0~n-1范围内
    int findRepeatNumber(vector<int>& nums)
    {
        int i = 0;
        int len = nums.size();
        while(i < len)
        {
            // 如果索引和值相等，不用交换
            if(nums[i] == i)
            {
                ++i;
                continue;
            }
            // 如果对应索引位值和当前遍历的值相等，说明重复值出现了，返回nums[i]
            if(nums[nums[i]] == nums[i])
                return nums[i];
            // 对应对应索引位置的值不一样，则交换
            swap(nums[i], nums[nums[i]]);
        }
        return -1;
    }
};
