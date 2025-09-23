
#include <vector>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        vector<int> nums;
        if (x < 0)
            return false;
        while (x > 0)
        {
            nums.push_back(x % 10);
            x /= 10;
        }
        int n = nums.size();
        for (int i = 0; i < (n + 1) / 2; i++)
        {
            if (nums[i] != nums[n - 1 - i])
                return false;
        }
        return true;
    }
    bool betterIsPalindrome(int x)
    {
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;
        int halfReverse = 0;
        while (x > halfReverse)
        {
            halfReverse = halfReverse * 10 + x % 10;
            x /= 10;
        }
        return halfReverse == x || x == halfReverse / 10;
    }
};
