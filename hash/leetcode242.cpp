#include "../common.h"

#if 0
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())    return false;
        // 使用一个数组来存储对应位置字母的出现次数
        int array[26];
        memset(array, 0, sizeof(array));
        // 如果互为字母异位词的话 最终array中全为0
        for(int i = 0; i < s.size(); ++i) {
            array[s[i] - 97] += 1;
            array[t[i] - 97] -= 1;
        }
        for(int i = 0; i < 26; ++i)
            if(array[i] != 0)   return false;
        return true;
    }
};
#else

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> count;
        for(int i = 0; i < s.size(); ++i)
            if (count.find(s[i]) != count.end())
                count[s[i]] += 1;
            else
                count[s[i]] = 1;

        for (int i = 0; i < t.size(); ++i)
            if (count.find(t[i]) == count.end())    return false;
            else    count[t[i]] -= 1;
        
        for (auto it = count.begin(); it != count.end(); ++it)
            if (it->second != 0)  return false;

        return true;
    }
};
#endif