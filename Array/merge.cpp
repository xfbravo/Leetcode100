#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    static bool compare(const vector<int> &a, const vector<int> &b)
    {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> result;
        int size = intervals.size();
        if(intervals.empty()){
            return result;
        }
        //按照起始位置对区间进行排序
        sort(intervals.begin(), intervals.end(), compare);
        result.push_back(intervals[0]);
        //merge 合并
        for (int i = 1; i < size;i++){
            vector<int> lastInterval = result.back();
            if(lastInterval[1]< intervals[i][0]){
                result.push_back(intervals[i]);
            }else{
                result.back()[1] = max(lastInterval[1], intervals[i][1]);
            }
            
        }
        return result;
    }
};

int main(){
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    Solution s;
    vector<vector<int>> result = s.merge(intervals);
    for (const vector<int> &interval : result)
    {
        cout << "[" << interval[0] << "," << interval[1] << "]" << endl;
    }
    return 0;
}