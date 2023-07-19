#include "../common.h"

#if 0
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // 枚举
        int n = s.size();
        for (int i = 1; i * 2 <= n; ++i) {
            if (n % i == 0) {
                bool match = true;
                for (int j = i; j < n; ++j) {
                    if (s[j] != s[j - i]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    return true;
                }
            }
        }
        return false;
    }
};
#if 0
class Solution {
public:
// 移动匹配
    bool repeatedSubstringPattern(string s) {
        string ss = s + s;
        // 删除前后，避免在查找的时候直接找到原本的s
        ss.erase(ss.begin());
        ss.erase(ss.end() - 1);
        if (ss.find(s) != string::npos) return true;
        return false;
    }
};
#endif
#else
// kmp
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.size() == 0)  return false;
        vector<int> next = getNext(s);
        int len = s.size();
        if (next[len - 1] != 0 && (len % ( len - next[len - 1])) == 0) return true;
        return false;
    }

private:
    vector<int> getNext(const string& needle) {
        int n = needle.size();
        vector<int> next(n);
        next[0];
        // i代表后缀尾部元素
        // j代表前缀尾部元素
        int j = 0;
        for (int i = 1; i < n; ++i) {
            while (j > 0 && needle[i] != needle[j])
                j = next[j - 1];
            if (needle[i] == needle[j]) ++j;
            next[i] = j;
        }
        return next;
    }
};
#endif
