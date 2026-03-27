#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        const vector<int> *A = &nums1;
        const vector<int> *B = &nums2;

        // 保证在更短数组上二分
        if (A->size() > B->size())
        {
            swap(A, B);
        }

        int m = (int)A->size();
        int n = (int)B->size();
        int totalLeft = (m + n + 1) / 2;

        int left = 0, right = m;
        while (left <= right)
        {
            int i = left + (right - left) / 2;
            int j = totalLeft - i;

            int ALeft = (i == 0) ? INT_MIN : (*A)[i - 1];
            int ARight = (i == m) ? INT_MAX : (*A)[i];
            int BLeft = (j == 0) ? INT_MIN : (*B)[j - 1];
            int BRight = (j == n) ? INT_MAX : (*B)[j];

            if (ALeft <= BRight && BLeft <= ARight)
            {
                if (((m + n) & 1) == 1)
                {
                    return max(ALeft, BLeft);
                }
                return (max(ALeft, BLeft) + min(ARight, BRight)) / 2.0;
            }
            else if (ALeft > BRight)
            {
                right = i - 1;
            }
            else
            {
                left = i + 1;
            }
        }

        return 0.0;
    }
};