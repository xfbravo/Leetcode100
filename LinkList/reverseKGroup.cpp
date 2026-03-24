struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    //prev->next=head
    ListNode* reverseK(ListNode* prev,ListNode *head,int k){
        int count = 0;
        ListNode *curr = head;
        while(curr){
            curr = curr->next;
            count++;
        }
        if(count < k) return head;
        curr = head;

        for (int i = 0; i < k;i++){
            ListNode *next= curr->next;
            curr->next = prev->next;
            prev->next = curr;
            curr = next;
        }
        head->next = curr;
        return head;
    }
    ListNode* reverseKGroup(ListNode *head,int k){
        ListNode *Head = new ListNode(0,head);
        ListNode *prev = Head;
        while(head->next){
            prev = reverseK(prev,head,k);
            //如果反转后prev->next仍然是head，说明剩余的节点不足k个，不需要继续反转，直接跳出循环
            if(prev->next == head) break;
            head = prev->next;
            if(!head) break;
        }
        return Head->next;
    }
};