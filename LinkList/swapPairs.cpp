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
    ListNode *swapPairs(ListNode *head){
        if(!head || !head->next){
            return head;
        }
        ListNode *Head = new ListNode(0,head);
        ListNode *pre = Head;
        ListNode *curr = head;
        while(curr && curr ->next){
            ListNode *next = curr->next;
            curr->next=next->next;
            next->next = curr;
            pre->next = next;
            pre = curr;
            curr = curr->next;
        }
        return Head->next;
    }
};