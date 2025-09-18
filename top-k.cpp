#include <iostream>
#include <vector>
using namespace std;

// 父亲索引
int parent(int i)
{
    return (i - 1) / 2;
}

// 左节点索引
int left(int i)
{
    return i * 2 + 1;
}

// 右节点索引
int right(int i)
{
    return i * 2 + 2;
}

void siftDown(vector<int> &nums, int i, int size)
{
    while (true)
    {
        int l = left(i), r = right(i), min = i;
        if (l < nums.size() && nums[l] < nums[min])
            min = l;
        if (r < nums.size() && nums[r] < nums[min])
            min = r;
        if (min == i)
            break;
        i = min;
    }
}

void siftUp(vector<int> &nums, int i, int size)
{
    while (true)
    {
        int p = parent(i);
        if (p < 0 || nums[p] <= nums[i])
            break;
        swap(nums[i], nums[p]);
        i = p;
    }
}

int pop(vector<int> &nums, int size)
{
    swap(nums[0], nums[size - 1]);
    size--;
    siftDown(nums, 0, size);
    return size;
}
int push(vector<int> &nums, int i, int size)
{
    size++;
    nums[size - 1] = i;
    siftUp(nums, size - 1, size);
    return size;
}

vector<int> topKSolution(vector<int> &nums, int k)
{
    int size = k;
    for (int i = parent(size - 1); i >= 0; i--)
    {
        siftDown(nums, i, size);
    }

    for (int j = k; j < nums.size(); j++)
    {
        if (nums[j] > nums[0])
        {
            size = pop(nums, size);
            size = push(nums, nums[j], size);
        }
    }
    vector<int> res(k);
    for (int j = k - 1; j >= 0; j--)
    {
        res[j] = nums[0];
        pop(nums, k);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> res = topKSolution(nums, 2);
    for (int &num : res)
        cout << num << ' ';
    cout << endl;
}