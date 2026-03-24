#include <algorithm>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// bool cmp(ListNode* a, ListNode* b){
//     return a->val < b->val;
// }
// class Solution{
// public:
//     ListNode* sortList(ListNode* head){
//         if(!head || !head->next)
//             return head;
//         vector<ListNode*> nodes;
//         ListNode* curr = head;
//         while(curr){
//             nodes.push_back(curr);
//             curr = curr->next;
//         }
//         sort(nodes.begin(),nodes.end(),cmp);
//         head = nodes[0];
//         for (int i = 0; i < nodes.size() - 1;i++){
//             nodes[i]->next = nodes[i+1];
//         }
//         nodes.back()->next = nullptr;
//         return head;
//     }
// };
class Solution{
public:
    ListNode* sortList(ListNode* head){
        return sortList(head,nullptr);
    }
    ListNode *sortList(ListNode*head,ListNode*tail){
        if(!head){
            return head;
        }
        if(head->next == tail){
            head->next = nullptr;
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast !=tail && fast->next != tail){
            slow=slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow;
        ListNode* list1 = sortList(head,mid);
        ListNode* list2 = sortList(mid,tail);
        return merge(list1,list2);
    }
    ListNode* merge(ListNode* head1,ListNode* head2){
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        while(head1 && head2){
            if(head1->val <head2->val){
                curr->next = head1;
                head1 = head1->next;
                curr = curr->next;
            }else{
                curr->next = head2;
                head2 = head2->next;
                curr = curr->next;
            }
        }
        while(head1){
            curr->next = head1;
            head1 = head1->next;
            curr = curr->next;
        }
        while(head2){
            curr->next = head2;
            head2 = head2->next;
            curr = curr->next;
        }
        return head->next;
    }
};