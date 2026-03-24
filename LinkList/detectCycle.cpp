#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* detectCycle(ListNode *head)
    {
        int pos = 0;
        bool hasCycle = false;
        if (!head)
            hasCycle = false;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                hasCycle = true;
                break;
            }
        }
        if (hasCycle)
        {
            fast = head;
            while (fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
                pos++;
            }
            return fast; // 返回环入口节点
        }
        // if(hasCycle){
        //     cout<<"环入口节点的索引为: "<<pos<<endl;
        // }
        return NULL;
    }
};
