#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
#if 0
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            if (abs(nums[right]) > abs(nums[left])) {
                ans.push_back(pow(nums[right--], 2));
            }
            else if (abs(nums[right]) < abs(nums[left])) {
                ans.push_back(pow(nums[left++], 2));
            }
            else {
                ans.push_back(pow(nums[left++], 2));
                --right;
            }
        }
        return vector<int>(ans.rbegin(), ans.rend());
    }
#else
 vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            if (abs(nums[right]) > abs(nums[left])) {
                ans.push_back(pow(nums[right--], 2));
            }
            else {
                ans.push_back(pow(nums[left++], 2));
            }
        }
        return vector<int>(ans.rbegin(), ans.rend());
    }
#endif
};

int main()
{
    Solution s;
    vector<int> v{-7,-3,2,3,11};
    s.sortedSquares(v);
}