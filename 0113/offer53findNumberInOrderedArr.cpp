#include "../common/common.h"

/**
 * 统计一个数字在排序数组中出现的次数
*/

class Solution {
public:
#if 0
    int search(vector<int>& nums, int target) {
        int cnt = 0;
        for(int &val: nums)
        {
            if(val == target)
                ++cnt;
        }
        return cnt;
    }
#endif

#if 0
    // 考虑数组有序
    int search(vector<int>& nums, int target)
    {
        int cnt = 0;
        int lo = 0, hi = nums.size() - 1;
        int mid = 0;
        // 搜索右边界
        while(lo <= hi)
        {
            // 这样写法是为了避免在lo很大是造成数据溢出
            mid = lo + (hi - lo) >> 1;
            if(target >= nums[mid])
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        int right = lo;
        // 若数组中无target，提前返回
        if(hi >= 0 && nums[hi] != target) return 0;
        //搜索左边界
        lo = 0;
        hi = nums.size() - 1;
        while(lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if(nums[mid] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        int left = hi;
        return right - left - 1;

        return cnt;
    }
    #endif

    /**
     * 二分查找
     * 寻找数组中第一个等于target的位置left，第一个大于target的位置-1为right
     * 当target在数组中存在时，结果为right-left+1
     * 第一个大于等于的target的下标
     * 第一个大于target的下标-1
    */
    int search(vector<int>& nums, int target)
    {
        int left = binarySearch(nums,target, true);   
        int right = binarySearch(nums,target, false) - 1;
        if(left <= right && right < nums.size() && nums[left] == target && nums[right] == target)
            return   right - left + 1;
        return 0; 
    }

    int binarySearch(vector<int>& nums, int target, bool lower)
    {
        int lo = 0, hi = nums.size() - 1, ans = nums.size(), mid = 0;
        while(lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if(nums[mid] > target || (lower && nums[mid] >= target))
            {
                hi = mid - 1;
                ans = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int>v{5,7,7,8,8,10};
    s.search(v,8);
}
