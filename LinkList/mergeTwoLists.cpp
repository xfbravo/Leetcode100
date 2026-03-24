#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        ListNode *head = new ListNode(0, list1);
        list1 = head;
        while (list1->next && list2)
        {
            if (list1->next->val <= list2->val)
            {
                list1 = list1->next;
            }
            else
            {
                ListNode *temp = list2->next;
                list2->next = list1->next;
                list1->next = list2;
                list2 = temp;
            }
        }
        if (list2)
        {
            list1->next = list2;
        }
        return head->next;
    }
};