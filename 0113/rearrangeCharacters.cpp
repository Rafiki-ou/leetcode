#include "../common/common.h"

/**
 leetcode 2287 重排字符形成目标字符串
 url:https://leetcode.cn/problems/rearrange-characters-to-make-target-string/
*/

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int cnt = 0;
        int pos = -1;
        bool flag = true;
        while(flag)
        {
            for(int i = 0; i < target.size(); ++i)
            {
                pos = s.find(target[i]);
                if(pos != string::npos)
                {
                    s.erase(pos,1);
                }
                else
                {
                    flag = false;
                    break;
                }
                if(i == (target.size() - 1))
                    ++cnt;
            }
        }
        return cnt;
    }
};

int main()
{
    Solution s;
    cout << s.rearrangeCharacters("ilovecodingonleetcode","code") << endl;;
}