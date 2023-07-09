#if 0
给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 true 。# 代表退格字符。
注意：如果对空文本输入退格字符，文本继续为空
#endif
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        #if 0
        使用双指针从后往前判断，有以下三种情况
        is，it分别指向s和t的末位字符，skipS skipT 表示#的数量
        1、当前字符为'#',skip++
        2、当前字符不为'#'且skip!=0,skip--
        3、当前字符不为'#'且skip=0,当前字符就是不能消除，需要比较的字符
        #endif
        int is = s.length() - 1, it = t.length() - 1;
        int skipS = 0, skipT = 0;
        while (is >= 0 || it >= 0) {
            while (is >= 0) {
                if (s[is] == '#') {
                    --is; ++skipS;
                }
                else if (skipS > 0) {
                    --is; --skipS;
                }
                else
                    break;
            }

            while (it >= 0) {
                if (t[it] == '#') {
                    --it; ++skipT;
                }
                else if (skipT > 0) {
                    --it; --skipT;
                }
                else
                    break;
            }
            // s和t是否都不为0
            if (is >= 0 && it >= 0) {
                if (s[is] != t[it]) 
                    return false;
            }
            else 
                if (is >= 0 || it >= 0) return false;
            --is; --it;
        }
        return true;
    }
};