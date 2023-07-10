#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // 先开辟空间
        vector<vector<int>> res(n, vector<int>(n, 0));
        // 定义起点
        int startx = 0, starty = 0;
        // 记录循环圈数
        int loop = n / 2;
        // 如果n是奇数，记录中间位置，单独处理
        int mid = n / 2;
        // 当前位置该存放的数
        int count = 1;
        // 控制每一条边的遍历长度，每次循环边界收缩一位
        int offset = 1;
        int i, j;
        while (loop--) {
            i = startx;
            j = starty;
            // 坚持循环不变量原则，每条边都采用左闭右开原则访问
            for (j = starty; j < n - offset; ++j)
                res[startx][j] = count++;
            for (i = startx; i < n - offset; ++i)
                res[i][j] = count++;
            for (; j > starty; --j)
                res[i][j] = count++;
            for (;i > startx; --i) 
                res[i][j] = count++;
            // 更新起点和边界收缩大小
            ++startx;
            ++starty;
            // 更新收缩宽度，第循环完一圈，离外层更远一圈，所以offse+1
            offset += 1;
        }
        // 如果n为奇数，特殊处理中间
        if (n % 2)
            res[mid][mid] = count;
            return res;
    }
};

int main()
{
    Solution s;
    s.generateMatrix(3);
}