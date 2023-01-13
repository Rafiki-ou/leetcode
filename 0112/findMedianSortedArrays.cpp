#include "../common/common.h"

class Solution {
public:
    #if 0
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(), nums1.end());
        int size = nums1.size();
        if(size % 2 == 0)
            return (nums1[size / 2] + nums1[size/2 - 1])*1.0 / 2;
        else
            return nums1[size/2];
    }
    #endif

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int n = nums1.size();
        int m = nums2.size();

        // 始终保证数组1一定最短
        if(n > m)   return findMedianSortedArrays(nums2, nums1);

        // Ci为第i个数组的割 LMaxi为第i个数组割后的左元素。RMini为第i个数组割后的右元素。
        // 我们虚加‘#’，所以数组1的长度是2n
        int LMax1,LMax2, RMin1, RMin2, c1, c2, lo = 0, hi = 2 * n;
        while(lo <= hi)
        {
            c1 = (lo+hi) / 2;
            // 因为虚加'#',所以两个数组一个 2m 一个2n  所以总长度为2m+2n  然后中间就是m+n
            c2 = m + n - c1;
            // 数组1整体都在右边，都比中值大
            LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
            // 数组1整体都在左边，都比中值小
            RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[(c1 / 2)]; 
            // 数组2整体都在右边
            LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
            // 数组2整体都在左边
            RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[(c2 / 2)]; 
            // 数组1的割划大了，应该减小
            if(LMax1 > RMin2)
                hi = c1 - 1;
            else if (LMax2 > RMin1) // 数组2的割划大了，应该减小
                lo = c1 + 1;
            else
               break;
        }
        return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
    }
};