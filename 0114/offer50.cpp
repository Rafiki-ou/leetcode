#include "../common/common.h"

class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char,int> map;
        for(int i = 0; i < s.size(); ++i)
        {
            if(map.find(s[i]) == map.end())
                map[s[i]] = 1;
            else
                map[s[i]] = map[s[i]] + 1;
        }
        for(int i = 0; i < s.size(); ++i)
        {
            if(map[s[i]] == 1)
                return s[i];
        }
        return ' ';
    }
};

int main()
{
    Solution s;
    cout << s.firstUniqChar("leetcode");
}