#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    void moveZeroes(vector<int> &nums)
    {
        int size = nums.size();
        int zeroIndex = 0;
        if(size <=1) return;
        while(nums[zeroIndex]!=0 && zeroIndex<size){
            zeroIndex++;
        }
        for(int i=zeroIndex+1;i<size;i++){
            if(nums[i]!=0){
                swap(nums[zeroIndex],nums[i]);
                while (nums[zeroIndex] != 0 && zeroIndex < size)
                {
                    zeroIndex++;
                }
            }
        }
    }
};

int main(){
    Solution solution;
    vector<int> nums = {1};
    solution.moveZeroes(nums);
    for(int num:nums){
        cout<<num<<" ";
    }
}