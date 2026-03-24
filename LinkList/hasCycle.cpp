#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    bool hasCycle(ListNode *head){
        int pos = 0;
        bool hasCycle = false;
        if(!head)
            hasCycle = false;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                hasCycle=true;
                break;
            }
        }
        if(hasCycle){
            fast=head;
            while(fast!=slow){
                fast=fast->next;
                slow=slow->next;
                pos++;
            }
        }
        // if(hasCycle){
        //     cout<<"环入口节点的索引为: "<<pos<<endl;
        // }
        return hasCycle;
    }
};
// 快慢指针法：m表示链表头到环入口的距离，n表示环的长度，j表示快慢指针相遇时慢指针在环内走过的距离
// fast: s1=m+kn+j
// slow: s2=m+j
// s1=2s2 -> m+kn+j=2m+2j ->m=kn-j
// fast回到0
// fast->0->m
// slow->m+j+m=m+kn 此时两个指针在m位置（环入口）相遇，

int main(){
    Solution s;
    ListNode *head = new ListNode(3);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(0);
    ListNode *node3 = new ListNode(-4);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node1; // 创建一个环，环入口为node1
    bool result = s.hasCycle(head);
    cout << (result ? "true" : "false") << endl;
    return 0;
}