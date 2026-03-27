#include <vector>
#include <algorithm>
class Solution
{
public:
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    void heapify(std::vector<int> &heap, int i, int k)
    {
        int smallest = i;
        int left = 2 * i + 1;
        int right = left + 1;
        if (left < k && heap[left] < heap[smallest])
        {
            smallest = left;
        }
        if (right < k && heap[right] < heap[smallest])
        {
            smallest = right;
        }
        if (smallest != i)
        {
            swap(heap[i], heap[smallest]);
            heapify(heap, smallest, k);
        }
    }
    int findKthLargest(std::vector<int> &nums, int k)
    {
        std::vector<int> minHeap(k, INT_MIN);
        for (int i = 0; i < k; i++)
        {
            minHeap[i] = nums[i];
        }
        for (int i = k / 2 - 1; i > 0; i--)
        {
            heapify(minHeap, i, k);
        }
        int size = nums.size();
        for (int i = k; i < size; i++)
        {
            if (minHeap[0] < nums[i])
            {
                minHeap[0] = nums[i];
                heapify(minHeap, 0, k);
            }
        }
        return minHeap[0];
    }
};