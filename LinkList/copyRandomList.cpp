class Node{
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val){
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution{
public:
    Node* copyRandomList(Node* head){
        Node *curr = head;
        Node *copyHead = new Node(0);
        Node *copyCurr = copyHead;
        //先复制链表的结构，不处理random指针
        while(curr){
            copyCurr->next = new Node(curr->val);
            copyCurr = copyCurr->next;
            curr = curr->next;
        }
        //复制random指针
        curr = head;
        copyCurr = copyHead->next;
        while(curr){
            if(curr->random){
                Node *randomCurr = head;
                Node *copyRandomCurr = copyHead->next;
                while(randomCurr){
                    if(randomCurr == curr->random){
                        copyCurr->random = copyRandomCurr;
                        break;
                    }
                    randomCurr = randomCurr->next;
                    copyRandomCurr = copyRandomCurr->next;
                }
            }
            curr = curr->next;
            copyCurr = copyCurr->next;
        }
        return copyHead->next;
    }
};