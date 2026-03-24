#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
// 课程表
// 化简为图中是否存在环的问题
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {   
        int count = 0;
        //入度
        vector<int> inDegree(numCourses, 0);
        for(const auto &pre : prerequisites){
            inDegree[pre[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses;i++){
            if(inDegree[i] == 0){
                q.push(i);
                count++;
            }
        }
        while(!q.empty()){
            int course = q.front();
            q.pop();
            for(const auto &pre : prerequisites){
                if(pre[1] == course){
                    inDegree[pre[0]]--;
                    if(inDegree[pre[0]]==0){
                        q.push(pre[0]);
                        count++;
                    }
                }
            }
        }

        return count == numCourses;
    }
};