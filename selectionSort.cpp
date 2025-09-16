#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &arr)
{
    int k;
    int n=arr.size();
    for (int i = 0; i < n-1; i++)
    {
        k = i;
        for (int j = i + 1; j < n; j++)
        {
            k = arr[k] > arr[j] ? j : k;
        }
        swap(arr[k], arr[i]);
    }
}

void selectionSort2(vector<int> &nums)
{
    int n = nums.size();
    for (int i = n - 1; i > 0; i--)
    {
        int k = i;
        for (int j = 0; j < i; j++)
        {
            if (nums[j] > nums[k])
                k = j;
        }
        swap(nums[i], nums[k]);
    }
}

int main()
{
    vector<int> nums = {3, 6, 4, 2, 1};
    vector<int> arr = {2, 4, 6, 2, 7, 9};
    selectionSort(arr);
    selectionSort2(nums);
    for (int &num : arr)
    {
        cout << num << ' ';
    }
    cout << endl;
    for (int &num : nums)
    {
        cout << num << ' ';
    }
    cout << endl;
}