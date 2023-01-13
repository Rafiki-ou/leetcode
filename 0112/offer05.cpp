#include "../common/common.h"
/**
 * 写一个方法来替换所有的空格为%20
*/
class Solution{
public:
    string replaceSpace(string s)
    {
        int pos = -1;
        while((pos = s.find(" ")) != string::npos)
        {
            s.replace(pos,1,"%20");
        }
        return s;
    }
};