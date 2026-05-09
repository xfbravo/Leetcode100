// LeetCode 1052. Grumpy Bookstore Owner
#include <vector>

class Solution
{
public:
    int maxSatisfied(std::vector<int> &customers, std::vector<int> &grumpy, int minutes)
    {
        int n = customers.size();
        int satisfied = 0;
        //如果老板不控制自己，得到的满意客户数
        for (int i = 0; i < n;++i){
            if(grumpy[i] == 0){
                satisfied += customers[i];
            }
        }
        //滑动窗口，找到一个长度为minutes的窗口，使得grumpy[i] == 1的customers[i]的和最大
        int maxControlSatisfied = 0;
        // int left = 0, right = 0;
        int currentControlSatisfied = 0;
        // while(right<n){
        //     if (grumpy[right] == 1)
        //     {
        //         currentControlSatisfied += customers[right];
        //     }
        //     if(right - left +1 > minutes){
        //         if(grumpy[left] == 1){
        //             currentControlSatisfied -= customers[left];
        //         }
        //         left++;
        //     }
        //     maxControlSatisfied = std::max(maxControlSatisfied, currentControlSatisfied);
        //     right++;
        // }
        for (int i = 0; i < n;i++){
            if(grumpy[i] == 1){
                currentControlSatisfied += customers[i];
            }
            if(i >= minutes){
                if(grumpy[i - minutes] == 1){
                    currentControlSatisfied -= customers[i - minutes];
                }
            }
            maxControlSatisfied = std::max(maxControlSatisfied, currentControlSatisfied);
        }
        return satisfied + maxControlSatisfied;
    }
};