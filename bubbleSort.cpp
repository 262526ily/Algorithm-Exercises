#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] > nums[j + 1])
                swap(nums[j], nums[j + 1]);
        }
    }
}

void bubbleSortWithFlag(vector<int> &nums)
{
    int n = nums.size();
    for (int i = n - 1; i > 0; i--)
    {
        bool flag = false;
        for (int j = 0; j < i; j++)
        {
            if (nums[j] > nums[j + 1])
                swap(nums[j], nums[j + 1]);
            flag = true;
        }
        if (!flag)
            break;
    }
}

int main()
{
    vector<int> nums1 = {3, 5, 3, 2, 6, 9, 1};
    vector<int> nums2 = {9, 3, 6, 1, 4, 2};
    bubbleSort(nums1);
    bubbleSortWithFlag(nums2);
    for (int &num : nums1)
    {
        cout << num << ' ';
    }
    cout << endl;
    for (int &num : nums2)
    {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}