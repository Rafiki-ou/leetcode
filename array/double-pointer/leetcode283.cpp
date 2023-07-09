#if 0
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。
#endif
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int slow = 0, fast = 0;
        while (fast < size) {
            if (nums[fast] != 0)
                swap(nums[fast++], nums[slow++]);
            else ++fast;
        }
    }
};