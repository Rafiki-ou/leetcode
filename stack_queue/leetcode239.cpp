#include "../common.h"

class Solution {
    private:
    struct MyQueue{
        // 定义自己的单调队列，默认前面大，为队头
        deque<int> aux;
        void pop(int value) {
            if (!aux.empty() && value == aux.front()) aux.pop_front();
        }

        void push(int value) {
            while (!aux.empty() && aux.back() < value)  aux.pop_back();
            aux.push_back(value);
        }

        int getMaxValue() {
            return aux.empty() ? INT_MIN : aux.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue q;
        int popIndex = 0;
        vector<int> res;
        // 先将前面k个元素放入队列
        for (int i = 0; i< k; ++i)  q.push(nums[i]);
        res.push_back(q.getMaxValue());
        for (int i = k; i < nums.size(); ++i) {
            // 先移除窗口队头元素
            q.pop(nums[i - k]);
            // 再添加元素
            q.push(nums[i]);
            // 取最大值放入结果集
            res.push_back(q.getMaxValue());
        }
        return res;
    }
};