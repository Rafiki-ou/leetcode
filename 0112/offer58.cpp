#include "../common/common.h"

class Solution{
public:
    string reverseLeftWords(string s, int n)
    {
        string leftWords = s.substr(0,n);
        string other = s.substr(n,s.length() - n);
        return other+leftWords; 
    }
};