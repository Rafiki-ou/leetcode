#include "../common.h"

#if 0
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < size; ++i) {
            // 如果当前的数大于0，则后面的所有数也大于0，不可能存在3个数和为0
            if(nums[i] > 0)    return ans;
            // nums[i] == nums[i - 1]因为数组已经排序，所以当我们访问一个数时，决断是否是前面已经访问过的数值，因为要求结果是不重复的
            if(i > 0 && nums[i] == nums[i - 1])    continue;
            // 这就是双指针的核心应用，目的在于不断缩小寻找范围
            int left = i + 1, right = size - 1;
            while(left < right) {
                if(nums[i] + nums[left] + nums[right] > 0)  --right;
                else if(nums[i] + nums[left] + nums[right] < 0)  ++left;
                else {
                    ans.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // 找到至少一组元组之后，为了避免发生重复的元素，我们还需要继续对nums[left]与nums[right]去重
                    while(left < right && nums[right] == nums[right - 1])   --right;
                    while(left < right && nums[left] == nums[left + 1]) ++left;

                    //找到一组答案之后继续缩小right与left的范围,上面两个while的目的是为了去重，下面的才是缩小范围
                    --right;
                    ++left;
                }
            }
        }
        return ans;
    }
};
#else
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for (int i = 0; i < nums.size(); ++i) {
            // 如果当前元素已经大于0，后面的自然全部大于0
            if (nums[i] > 0)    return ret;
            // 去重  避免返回重复的结果
            if (i > 0 && nums[i] == nums[i - 1])    continue;
            int left = i + 1, right = nums.size() - 1;
            while (right > left) {
                if (nums[i] + nums[left] + nums[right] > 0) --right;
                else if (nums[i] + nums[left] + nums[right] < 0) ++left;
                else {
                    ret.push_back({nums[i], nums[left], nums[right]});
                    // 对b和c去重
                    while (right > left && nums[right] == nums[right - 1])  --right;
                    while (right > left && nums[left] == nums[left + 1]) ++left;
                    ++left;
                    --right;
                }   
            }
        }
        return ret;
    }
};
#endif