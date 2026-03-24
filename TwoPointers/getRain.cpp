#include <vector>
#include <iostream>

using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int size = height.size();
        int max_index = 0;
        for (int i = 0; i < size; i++)
        {
            if (height[i] > height[max_index])
                max_index = i;
        }
        int left = 0;
        int right = size - 1;
        int result = 0;
        int left_index = 1;
        int right_index = size - 2;
        while (left_index <= max_index){
            
            if(height[left]>height[left_index]){
                left_index++;
            }
            else{
                result += height[left] * (left_index - left-1);
                for (int i = left+1; i < left_index; i++){
                    result -= height[i];
                }
                left = left_index;
                left_index++;
            }
        }
        while(right_index >= max_index){
            if(height[right]>height[right_index]){
                right_index--;
            }
            else{
                result += height[right] * (right-right_index-1);
                for (int i = right-1; i > right_index; i--){
                    result -= height[i];
                }
                right = right_index;
                right_index--;
            }
        }
        return result;
    }
};

int main(){
    Solution solution;
    vector<int> height = {2,0,2};
    cout << solution.trap(height) << endl;
    return 0;
}