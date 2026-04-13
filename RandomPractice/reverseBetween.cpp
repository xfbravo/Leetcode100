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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;
        ListNode *start = head;
        ListNode *prev = nullptr;
        // 找到反转起点
        for (int i = 1; i < left; i++)
        {
            prev = start;
            start = start->next;
        }
        ListNode *curr = start->next;
        // tempHead 记录反转部分的头，start是反转前的头，反转后变成尾部
        // curr 一直移动，直到移动到反转部分的下一个
        ListNode *tempHead = start;
        for (int i = left; i < right; i++)
        {
            ListNode *temp = curr;
            curr = curr->next;
            temp->next = tempHead;
            tempHead = temp;
        }
        // 连接反转部分与前置链表
        if (prev)
        {
            prev->next = tempHead;
        }
        else
        {
            head = tempHead;
        }
        // 连接反转部分与后置链表，start是反转部分的尾部，curr是后置链表的开头
        start->next = curr;
        return head;
    }
};