#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> result(size, 1);
        //计算每个元素的前缀之积
        for (int i = 0; i < size;i++){
            if(i == 0){
                result[i] = 1;
            }else{
                result[i] = result[i-1] * nums[i-1];
            }
        }
        int suffixProduct = 1;
        for (int i = size - 1; i >= 0;i--){
            result[i] = result[i] * suffixProduct;
            suffixProduct *= nums[i];
        }
        return result;
    }
};