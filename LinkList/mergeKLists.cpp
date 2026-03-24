#include <vector>
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
    ListNode *merge(ListNode *list1, ListNode *list2)
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
        // If list1 is exhausted, append the remaining nodes of list2
        while (list2)
        {
            list1->next = list2;
            list2 = list2->next;
            list1 = list1->next;
        }
        return head->next;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists,int left, int right)
    {
        if (lists.empty())
            return nullptr;
        int n = right - left + 1;
        if(n == 1) return lists[left];
        ListNode *result;
        int mid = left + (right - left) / 2;
        ListNode* l1 = mergeKLists(lists, left, mid);
        ListNode * l2 = mergeKLists(lists, mid + 1, right);
        result = merge(l1, l2);
        return result;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        return mergeKLists(lists, 0, lists.size() - 1);
    }
};

int main()
{
    Solution s;
    vector<ListNode *> lists(3);
    lists[0] = new ListNode(1);
    lists[0]->next = new ListNode(4);
    lists[0]->next->next = new ListNode(5);
    lists[1] = new ListNode(1);
    lists[1]->next = new ListNode(3);
    lists[1]->next->next = new ListNode(4);
    lists[2] = new ListNode(2);
    lists[2]->next = new ListNode(6);
    ListNode *result = s.mergeKLists(lists);
    while (result)
    {
        std::cout << result->val << " ";
        result = result->next;
    }
    std::cout << std::endl;
    return 0;
}