#include <iostream>
using namespace std;
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode* head = l1;
        int carry = 0;
        while(l1 || l2 || carry){
            int sum =carry;
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            sum+= l1->val;
            l1->val = sum % 10;
            carry = sum / 10;
            if(l1->next == nullptr && (l2 || carry)){
                l1->next = new ListNode();
            }
            l1 = l1->next;
        }
        return head;
    }
};

int main(){
    Solution s;
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* result = s.addTwoNumbers(l1, l2);
    while(result){
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}