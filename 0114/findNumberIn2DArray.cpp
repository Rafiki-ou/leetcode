#include "../common/common.h"

/**
 * 
*/

class Solution {
public:
#if 0
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        // 先来个暴力
        for(int i = 0; i < matrix.size(); ++i)
        {
            for(int j = 0; j < matrix[i].size();++j)
                if(target == matrix[i][j])
                    return true;
        }      
        return false;
    }
#endif

     bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) 
     {
        int n = matrix.size();
        for(int i = 0; i < n; ++i)
        {
            int size = matrix[i].size();
            int lo = 0, hi = size - 1;
            while(lo <= hi)
            {
                int mid = lo + (hi - lo) / 2;
                if(target < matrix[i][mid])
                {
                    hi = mid - 1;
                }   
                else if(target > matrix[i][mid])
                {
                    lo = mid + 1;
                }
                else
                {
                    return true;
                }
            }
        }
        return false;
     }

};