#include "../common/common.h"

/**
 * 无重复字符的最长子串
*/

class Solution{
public:
    int lengthOfLongestSubstring(string s)
    {
        string minstr;
        int pos = -1;
        int max = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if((pos = minstr.find(s[i])) == string::npos)
            {
                minstr+= s[i];
            }
            else
            {
                minstr = minstr.substr(pos+1, minstr.size()- pos - 1) + s[i];
            }
            max = max > minstr.size() ? max : minstr.size();
                
        }
        return max;
    }
};

int main()
{
    Solution s;
    s.lengthOfLongestSubstring("nfpdmpi");
}