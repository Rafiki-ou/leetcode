#include "../common.h"

#if 0
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set; // 存放结果，之所以用set是为了给结果集去重
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int num : nums2) {
            // 发现nums2的元素 在nums_set里又出现过
            if (nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};
#else
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set;
        vector<int> ans;
        for (int i = 0; i < nums1.size(); ++i)
            if (set.find(nums1[i]) == set.end())
                set.insert(nums1[i]);

        for(int i = 0; i < nums2.size(); ++i)
            if (set.find(nums2[i]) != set.end()) {
                set.erase(nums2[i]);
                ans.push_back(nums2[i]);
            }

        return ans;
    }
};
#endif