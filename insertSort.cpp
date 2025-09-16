#include <iostream>
#include <vector>
using namespace std;

void insertSort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        int base = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > base)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = base;
    }
}

int main()
{
    vector<int> nums = {2, 2, 1, 6, 3, 5, 4, 8};
    insertSort(nums);
    for (int num : nums)
    {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}