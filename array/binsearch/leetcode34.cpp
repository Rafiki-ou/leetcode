#include <vector>
#if 0
在有序数组上的二分查找就只有下面几种情况
它们之间可以转化
原                              等价
>= target                      >= target
> target                       >= (target + 1)
<= target                      (> target) -1    ==> >= (target + 1) - 1(这里减1表示当前数的前面一个位置)
< target                       (>= target) - 1 前 1 位
#endif

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // 先找大于等于target的位置
        int start = lower_bound(nums, target);
        // target在数组区间范围内，但没有找到或者是整个数组中的元素都比target小，所以查到最右边
        if (start == nums.size() || nums[start] != target)
        // if (nums[start] != target || start == nums.size())
            return {-1, -1};
        // 再查找小于target的位置 可以转换成查找大于target的位置的左边一个元素
        // 且start存在 end一定存在
        int end = lower_bound(nums, target + 1) - 1;
        return {start, end};
    }

private:
    // 查找大于等于target的数
    int lower_bound(vector<int>& nums, int target) {
        int left = 0, right = (int)nums.size() - 1;
        while (left <= right) {// 区间不为空
            int mid = left + (right - left) / 2;
            // 小于在[mid + 1, right]区间查找
            if (nums[mid] < target)
                left = mid + 1;
            // 大于等于在[left， mid -1]
            else
                right = mid - 1;
        }
        return left;
    }
};