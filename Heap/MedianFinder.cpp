#include <vector>
#include <queue>
class MedianFinder
{
public:
    std::priority_queue<int,std::vector<int>,std::greater<int>> maxHeap;
    std::priority_queue<int, std::vector<int>, std::less<int>> minHeap;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if(minHeap.empty()||num<=minHeap.top()){
            minHeap.push(num);
            if(maxHeap.size()+1<minHeap.size()){
                int temp = minHeap.top();
                maxHeap.push(temp);
                minHeap.pop();
            }
        }else{
            maxHeap.push(num);
            if(maxHeap.size()>minHeap.size()){
                int temp = maxHeap.top();
                minHeap.push(temp);
                maxHeap.pop();
            }
        }
    }

    double findMedian()
    {
        if((minHeap.size()+maxHeap.size())%2 == 0){
            return (minHeap.top() + maxHeap.top()) / 2.0;
        }else{
            return minHeap.top() / 1.0;
        }
    }
};