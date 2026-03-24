#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int size = height.size();
        int left = 0, right = size - 1;
        int maxArea = 0;
        while(left < right){
            int currentArea = min(height[left], height[right]) *(right - left);
            maxArea = max(maxArea, currentArea);
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxArea;
    }
};

int main(){

    Solution solution;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout<<solution.maxArea(height)<<endl;
    return 0;
}