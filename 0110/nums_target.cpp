/**
 * 两个数之和，一个数组和一个目标值
 * 返回两个元素和为target的下标
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
   /*
    vector<int> twoSum(vector<int>& nums, int target) {
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = i + 1; j < nums.size(); ++j)
            {
                sum = nums.at(i) + nums.at(j);
                if( sum == target)
                {
                    return {i,j};
                }
            }
        }
        return {};
    }
   */

    /**hash*/
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        for(int i = 0; i < nums.size(); ++i)
        {
            auto it = hash.find(target-nums[i]);
            if(it!= hash.end()) //找到了另外一个元素
            {
                return {it->second,i};
            }
            hash[nums[i]] = i;
        }
        return {};
    }

};

int main()
{
    Solution obj;
    vector<int> arr{3,2,4};
    vector<int> t = obj.twoSum(arr, 6);
    cout << t.size() << endl;


}