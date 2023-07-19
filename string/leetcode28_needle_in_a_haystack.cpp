#include "../common.h"

// 经典KMP算法
class Solution {
public:
// 干草堆 缝衣针 needle in a haystack大海捞针
    int strStr(string haystack, string needle) {
        // i指向文本串中下一个待比较的字符
        // j指向模式串中下一个待比较的字符
        int haystackLen = haystack.size();
        int needleLen = needle.size();
        int j = 0;
        // 模式串为空串，刚匹配位置就是0
        if (needleLen == 0) return 0;
        vector<int> next = getNext(needle);
        for (int i = 0; i < haystackLen; ++i) {
            // 当前字符不匹配，指向模式串的指针回退
            while (j > 0 && needle[j] != haystack[i])
                j = next[j - 1];
            if (needle[j] == haystack[i]) {
                // 模式串指针后移
                ++j;
                if (j == needleLen)
                    return i - needleLen + 1;
            }
        }
        return -1;
    }

private:
    vector<int> getNext(const string& needle) {
        int len = needle.size();
        vector<int> next(len);
        next[0] = 0;
        int j = 0;  //j表示最长前缀的下一个位置
        // i表示最长相同前后缀中后缀的下一个位置
        for (int i = 1; i < len; ++i) {
            // 前后缀末尾不相同，前缀回退，后缀不变
            // j=0说明回退到了模式串的最开头  
            while (j > 0 && needle[i] != needle[j]) {
                j = next[j - 1];
            }
            // 找到相同前后缀
            if (needle[i] == needle[j]) ++j;
            //以下标为i的字符结尾的字符串的相同前后缀的长度（也是前缀的下一个位置的下标）
            next[i] = j;
        }
        return next;
    }
};