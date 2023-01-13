#include "../common/common.h"

/**
 * 最长回文串
 * url:https://leetcode.cn/problems/longest-palindromic-substring/
*/

class Solution {
public:
#if 0
    // 方法一，动态规划
    string longestPalindrome(string s) {
        int n = s.size();
        int begin = 0;
        int maxLen = 1;
        // 如果长度小于2一定是回文串
        if(n < 2) return s;
        // dp[i][j]=true 表示s[i]...s[j]是回文串
        vector<vector<bool>> dp(n,vector<bool>(n));
        // 初始化d[i][i]一定是回文串
        for(int i = 0; i < n; ++i)
            dp[i][i] = true;
        // 枚举回文串长度
        for(int L = 2; L <= n; ++L)
        {
            for(int i = 0; i < n; ++i)
            {
                int j = L +i - 1;
                // 右边越界
                if(j >= n)
                    break;
                if(s[i] != s[j])
                    dp[i][j] = false;
                else
                    dp [i][j] = j - i < 3 ? true : dp[i+1][j-1];
                // 如果dp[i][j]=true,则s[i]..s[j]是回文串，此时记录起始长度和回文串长度
                if(dp[i][j] && j - i + 1 > maxLen)
                {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
#endif

    // 中心扩散法
    string longestPalindrome(string s)
    {
        int start = 0, end = 0;
        for(int i = 0; i < s.size(); ++i)
        {   
            // 边界情况，子串长度为1和2
            auto [left1,right1] = expandAroundCenter(s,i,i);
            auto [left2,right2] = expandAroundCenter(s,i,i+1);
            if(right1 - left1 > end - start)
            {
                start = left1;
                end = right1;
            }
            if(right2 - left2 > end - start)
            {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end- start + 1);
    }
    // P(i,j)-->P(i+1,j-1)
    pair<int,int> expandAroundCenter(const string& s, int left, int right)
    {   
        // 扩展边界
        while(left >= 0 && right < s.size() && s[left] == s[right])
        {
            ++right;
            --left;
        }
        return {left+1, right - 1};
    }
};

int main()
{
    Solution s;
    cout << s.longestPalindrome("ababa");
}