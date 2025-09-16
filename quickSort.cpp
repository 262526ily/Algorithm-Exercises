#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &nums, int left, int right)
{
    int i = left, j = right;
    while (i < j)
    {
        // i和j的移动顺序不能变，和基准的选择有关
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

/*基准数优化*/
int medianThree(vector<int> &nums, int left, int right)
{
    int mid = left + (right - left) / 2;
    int res = left;
    if (nums[res] > nums[mid])
    {
        if (nums[mid] <= nums[right])
            res = mid;
        else
            res = right;
    }
    return res;
}

int partition2(vector<int> &nums, int left, int right)
{
    int i = left, j = right;
    int med = medianThree(nums, left, right);
    swap(nums[left], nums[med]);
    while (i < j)
    {
        // i和j的移动顺序不能变，和基准的选择有关
        while (i < j && nums[j] >= nums[left])
            j--;
        while (i < j && nums[i] <= nums[left])
            i++;
        swap(nums[i], nums[j]);
    }
    swap(nums[left], nums[i]);
    return i;
}

void quickSort2(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return;
    int pivot = partition2(nums, left, right);
    quickSort2(nums, left, pivot - 1);
    quickSort2(nums, pivot + 1, right);
}

/*递归深度优化*/
void quickSort3(vector<int> &nums, int left, int right)
{
    while (left < right)
    {
        int pivot = partition2(nums, left, right);
        // 快速排序较短的子数组
        if (pivot - left < right - pivot)
        {
            quickSort3(nums, left, pivot - 1);
            left = pivot + 1;
        }
        else
        {
            quickSort3(nums, pivot + 1, right);
            right = pivot - 1;
        }
    }
}

int main()
{
    vector<int> nums = {2, 5, 2, 1, 3, 7, 6, 4};
    quickSort3(nums, 0, nums.size() - 1);
    for (int &num : nums)
    {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}