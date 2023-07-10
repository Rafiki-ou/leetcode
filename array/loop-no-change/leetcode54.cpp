#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       if (matrix.empty() || matrix[0].empty()) return {};
       vector<int>ans;
       int rows = matrix.size(), colums = matrix[0].size();
       int left = 0, right = colums - 1, top = 0, bottom = rows - 1;
       while (left <= right && top <= bottom) {
           // 左闭右闭
            for (int j = left; j <= right; ++j)
                ans.push_back(matrix[top][j]);
            // 上开下闭
            for (int i = top + 1; i <= bottom; ++i)
                ans.push_back(matrix[i][right]);
            if (left < right && top < bottom) {
                // 左开右开
                for (int j = right - 1; j > left; --j)
                    ans.push_back(matrix[bottom][j]);
                // 下闭上开
                
                for (int i = bottom; i > top; i--)
                    ans.push_back(matrix[i][left]);
            }
        ++left; --right; ++top; --bottom;
       }
       return ans;
    }
};

int main()
{
    vector<vector<int>> v{{1,2,3,4},
                          {10,11,12,5},
                          {9,8,7,6}
                        };
    Solution s;
    s.spiralOrder(v);
}
