#include "../common/common.h"

/**
 * 序列中不同最大公约数的数目
 * url:https://leetcode.cn/problems/number-of-different-subsequences-gcds/
 * 枚举到某个数时，我们需要不断判断其小于nums数组最大值的倍数是否在nums数组中。
 * 我们继续枚举这个数的倍数，当第一次这个数的某个倍数出现在nums数组中，
 * 我们将最大公约数更新为这个倍数，此后每次有新的倍数出现在nums数组中，
 * 我们只需要求“目前的最大公约数”与“新的倍数”这两个数的最大公约数。
 * 最终将最大公约数与这个数比较，如果相等，就说明这个数是某个子序列的最大公约数。

*/
#if 0 
// 这个算法会超时
class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        vector<vector<int>> subsequence = getSubSequence(nums);
        set<int> gcds;
        for(auto val : subsequence)
        {
            gcds.insert(getGCD(val));
        }
        return gcds.size();
    }

    int getGCD(vector<int> nums)
    {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        int gcd = nums[0];
        for(int i = 0; i < n - 1; ++i)
        {
            gcd = GCD(gcd, nums[i + 1]);
        }
        return gcd;
    }

    int GCD(int a, int b)
    {
        return !b ? a : GCD(b, a % b);
    }

    int Cmn(int m, int n)
    {
       int M = 1, N = 1;
       while(m>=n)
       {
            M *= m;
            --m;
       } 
       while(n > 0)
       {
            N *= n;
            --n;
       }
       return M/N;
    }

    vector<vector<int>> getSubSequence(vector<int> nums)
    {
        int size = nums.size();
        vector<vector<int>> subSequence;
        for(int i = 1; i < (1 << size); ++i)
        {
            vector<int> v;
            for(int j = 0; j < size; ++j)
                if((i >> j) & 1 == 1)
                    v.push_back(nums[j]);
            subSequence.push_back(v);
        }
        
        return subSequence;
    }

   
};

#endif

class Solution {
public:
#if 0
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<bool> occured(maxVal + 1, false);
        for (int num : nums) {
            occured[num] = true;
        }
        int ans = 0;
        // 枚举最大公约数
        for (int i = 1; i <= maxVal; i++) {
            int subGcd = 0;
            // 在nums数组最大值的范围内枚举当前所认为的公约数倍数，并判断他是否在nums数组中
            for (int j = i; j <= maxVal; j += i) {
                // 判断这个枚举的当前的公约数的倍数是否在nums数组中
                if (occured[j]) {
                    if (subGcd == 0) {
                        subGcd = j;
                    } else {
                        // 找到了公约数的倍数之后，求取他们两个的最大公约数来更新subGcd
                        subGcd = gcd(subGcd, j);
                    }
                    // 最后将这个所认为的最大公约数与我们所枚举的公约数比较，如果两者相等，则可以确定我们所枚举的公约数是nums的某个子序列的最大公约数
                    if (subGcd == i) {
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }

#endif

     int countDifferentSubsequenceGCDs(vector<int> &nums) {
        int ans = 0, mx = *max_element(nums.begin(), nums.end());
        bool has[mx + 1]; memset(has, 0, sizeof(has));
        for (int x : nums)
            if (!has[x]) {
                has[x] = true;
                ++ans; // 单独一个数也算
            }
        for (int i = 1; i <= mx / 3; ++i) { // 优化循环上界
            if (has[i]) continue;
            int g = 0; // 0 和任何数 x 的最大公约数都是 x
            for (int j = i * 2; j <= mx && g != i; j += i) // 枚举 i 的倍数 j
                if (has[j]) // 如果 j 在 nums 中
                    g = gcd(g, j); // 更新最大公约数
            if (g == i) ++ans; // 找到一个答案
        }
        return ans;
    }

    int gcd(int a, int b)
        {
            while(b != 0)
            {
                int tmp = a;
                a = b;
                b = tmp % b;
            }
            return a;
        }
};

int main()
{
   Solution s;
   vector<int> v{6,6,6};
   
   cout << s.countDifferentSubsequenceGCDs(v);
    
}
