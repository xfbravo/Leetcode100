struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        if (!head || !head->next)
            return head;

        // 找到第一个大于等于x的元素
        ListNode *first = head->next;
        // last表示最后一个小于x的元素，first的前一个，last可能为空，即第一个元素就大于等于x
        ListNode *last = head;
        if (head->val >= x)
        {
            first = head;
            last = nullptr;
        }
        while (first)
        {
            if (first->val >= x)
            {
                break;
            }
            first = first->next;
            last = last->next;
        }
        // 如果first为nullptr，说明没有大于等于x的元素
        if (!first)
        {
            return head;
        }
        // 之后所有小于x的元素都放在last的后面
        ListNode *prev = first;
        ListNode *curr = first->next;
        while (curr)
        {
            // 如果小于x，那么需要移动
            if (curr->val < x)
            {
                prev->next = curr->next;
                // 如果之前没有小于x的元素，直接插在最前面
                if (!last)
                {
                    curr->next = head;
                    // 更新head
                    head = curr;
                    // 更新last
                    last = curr;
                }
                // 如果last存在，那么要放在last后面
                else
                {
                    curr->next = last->next;
                    last->next = curr;
                    // 更新last，保持顺序
                    last = last->next;
                }
                curr = prev->next;
            }
            // 如果大于等于x不需要移动，直接跳过
            else
            {
                curr = curr->next;
                prev = prev->next;
            }
        }
        return head;
    }
};