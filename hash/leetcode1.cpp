#include "../common.h"

#if 0
 vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        for(int i = 0; i < nums.size(); ++i)
        {
            auto it = hash.find(target-nums[i]);
            if(it!= hash.end()) //找到了另外一个元素
            {
                return {it->second,i};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
#else

#endif