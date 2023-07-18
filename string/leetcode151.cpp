#include "../common.h"

class Solution {
public:
    string reverseWords(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) if (s[i] != ' ') { start = i; break;}
        for (int i = s.size() - 1; i > 0; --i) if (s[i] != ' ') { end = i; break;}
        string tmp = "";
        for (int i = end; i >= start; --i) {
            if (s[i] != ' ' && i != start)    continue;
            if ( i == start)
                tmp += s.substr(i, end - i);
            else
                tmp += s.substr(i + 1, end - i);
            if (i != start) tmp += " ";
            end = i - 1;
        }

        for (int i = 0; i < tmp.size(); ++i) {
            if ( i > 0 && tmp[i] == ' ' && tmp[i - 1] == ' ')
                tmp.erase(i--, 1);
        }
        return tmp;
    }
};

int main()
{
    Solution s;
    s.reverseWords("the sky   is blue");
}
