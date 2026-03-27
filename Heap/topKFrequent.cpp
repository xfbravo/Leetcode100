#include <vector>
#include <unordered_map>
#include <algorithm>
class Solution
{
public:
    void swap(int& a,int& b){
        int temp = a;
        a = b;
        b = temp;
    }
    void heapify(std::vector<int> &heap,std::unordered_map<int,int> &map,int i ,int k){
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if(left<k&&map[heap[smallest]]>map[heap[left]]){
            smallest = left;
        }
        if(right<k&&map[heap[smallest]]>map[heap[right]]){
            smallest = right;
        }
        if(smallest!=i){
            swap(heap[smallest], heap[i]);
            heapify(heap, map, smallest, k);
        }
    }
    std::vector<int> topKFrequent(std::vector<int> &nums, int k)
    {
        if (k <= 0)
            return {};

        std::unordered_map<int, int> map;
        std::vector<int> set;

        for (int x : nums)
        {
            if (map.find(x) == map.end())
            {
                set.push_back(x);
            }
            map[x] += 1;
        }

        int size = static_cast<int>(set.size());
        if (k > size)
            k = size;

        std::vector<int> heap(k);
        for (int i = 0; i < k; ++i)
        {
            heap[i] = set[i];
        }

        for (int i = k / 2 - 1; i >= 0; --i)
        {
            heapify(heap, map, i, k);
        }

        for (int i = k; i < size; ++i)
        {
            if (map[set[i]] > map[heap[0]])
            {
                heap[0] = set[i];
                heapify(heap, map, 0, k);
            }
        }

        return heap;
    }
};