# Algorithm-Exercises
A place to restore my code for Algorithm


## 25-9-16
```C++
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
在快速排序的“哨兵划分”中，i和j的移动顺序不能随意变换，和基准的选取有关
比如在选择左边第一个元素为基准后，j要先移动，即先找到第一个小于基准的元素
这样的话最好循环结束时是j移动到i上，而i是小于或等于基准的元素的索引，所以和基准元素交换后满足划分要求；
而如果先找第一个大于基准的元素，最后是i移动到j上，是一个大于或等于基准的元素，交换后，如果左边第一个元素大于基准元素，不满足划分要求。