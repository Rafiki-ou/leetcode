#include "../common/common.h"

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int lo = 0, hi = numbers.size() - 1;
        while(lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if(mid && numbers[mid] < numbers[mid - 1])
                return numbers[mid];
            else
                lo = mid + 1;
        }
        return numbers[0];
    }
};

int main()
{
    Solution s;
    vector<int> v{3,1,1,1,1};
    cout << s.minArray(v);
}