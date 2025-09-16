#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &nums, int left, int right)
{
    int i = left, j = right;
    while (i < j)
    {
        //i和j的移动顺序不能变，和基准的选择有关
        while (i < j && nums[j] >= nums[left])
            j--;
        while (i < j && nums[i] <= nums[left])
            i++;
        swap(nums[i], nums[j]);
    }
    swap(nums[left], nums[i]);
    return i;
}

void quickSort(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return;
    int pivot = partition(nums, left, right);
    quickSort(nums, left, pivot - 1);
    quickSort(nums, pivot + 1, right);
}

int main()
{
    vector<int> nums = {2, 5, 2, 1, 3, 7, 6, 4};
    quickSort(nums, 0, nums.size() - 1);
    for (int &num : nums)
    {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}