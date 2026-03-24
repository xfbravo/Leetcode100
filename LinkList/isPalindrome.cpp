#include <iostream>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = nullptr;
        if (!curr)
            return head;
        while (curr)
        {
            ListNode *nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
    bool isPalindrome(ListNode *head)
    {
        // 寻找中间节点的方法可以用快慢指针优化
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
            else
            {
                break;
            }
        }
        slow = reverseList(slow);
        ListNode *curr1 = head;
        while (slow)
        {
            if (curr1->val != slow->val)
                return false;
            curr1 = curr1->next;
            slow = slow->next;
        }
        return true;
        // int length = 0;
        // ListNode *curr1 = head;
        // while(curr1){
        //     length++;
        //     curr1 = curr1->next;
        // }
        // if(length <= 1) return true;
        // int mid = length / 2 ;
        // curr1 = head;
        // ListNode *curr2 = head;
        // for (int i = 0; i < mid; i++)
        // {
        //     curr2 = curr2->next;
        // }

        // if(length % 2 == 1){
        //     curr2 = curr2->next;
        // }
        // curr2 = reverseList(curr2);
        // while(curr2){
        //     if(curr1->val != curr2->val) return false;
        //     curr1 = curr1->next;
        //     curr2 = curr2->next;
        // }

        // return true;
    }
};

int main()
{
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    bool result = s.isPalindrome(head);
    cout << (result ? "true" : "false") << endl;
    return 0;
}