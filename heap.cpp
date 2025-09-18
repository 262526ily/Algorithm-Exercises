#include <iostream>
#include <vector>
using namespace std;

// 获取左子节点的索引
int left(int i)
{
    return i * 2 + 1;
}

// 获取右子节点的索引
int right(int i)
{
    return i * 2 + 2;
}

// 获取父结点的索引
int parent(int i)
{
    return (i - 1) / 2;
}

class MaxHeap
{
public:
    void push(int i);
    int pop();
    int peek();
    int size();
    bool isEmpty();
    void siftUp(int i);
    void siftDown(int i);
    MaxHeap(vector<int> nums);
    ~MaxHeap() {}

protected:
    vector<int> maxHeap;
};

void MaxHeap::push(int i)
{
    maxHeap.push_back(i);
    siftUp(size() - 1);
}

int MaxHeap::pop()
{
    int res = peek();
    maxHeap[0] = maxHeap[size() - 1];
    maxHeap.pop_back();
    siftDown(0);
    return res;
}

int MaxHeap::peek()
{
    if (isEmpty())
        throw out_of_range("堆为空");
    return maxHeap[0];
}

int MaxHeap::size()
{
    return maxHeap.size();
}

bool MaxHeap::isEmpty()
{
    return size() == 0;
}

void MaxHeap::siftUp(int i)
{
    while (true)
    {
        int p = parent(i);
        if (p < 0 || maxHeap[p] >= maxHeap[i])
            break;
        swap(maxHeap[p], maxHeap[i]);
        i = p;
    }
}

void MaxHeap::siftDown(int i)
{
    while (true)
    {
        int l = left(i), r = right(i), ma = i;
        if (l < size() && maxHeap[l] > maxHeap[ma])
            ma = l;
        if (r < size() && maxHeap[r] > maxHeap[ma])
            ma = r;
        if (i == ma)
            break;
        swap(maxHeap[i], maxHeap[ma]);
        i = ma;
    }
}

MaxHeap::MaxHeap(vector<int> nums)
{
    maxHeap = nums;
    for (int i = parent(size() - 1); i >= 0; i--)
    {
        siftDown(i);
    }
}

int main()
{
    vector<int> nums = {3, 6, 2, 4, 7, 9, 1, 3};
    MaxHeap m(nums);
    while (!m.isEmpty())
    {
        cout << m.pop() << ' ';
    }
    cout << endl;
}