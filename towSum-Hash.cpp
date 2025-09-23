#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> numToIndex;
        numToIndex[nums[0]] = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (numToIndex.find(target - nums[i]) != numToIndex.end())
            {
                return {numToIndex[target-nums[i]],i};
            }
            numToIndex[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    vector<int> nums = {2, 3, 11, 15};
    int target = 6;
    Solution s;
    vector<int> res;
    res = s.twoSum(nums, target);
    cout << res[0] << ' ' << res[1];
}