/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        //首先获取两个链表的长度
        int lenA = 0, lenB = 0;
        ListNode *pA = headA, *pB = headB;
        while(pA)
        {
            lenA++;
            pA = pA->next;
        }
        while(pB)
        {
            lenB++;
            pB = pB->next;
        }
        if(lenA > lenB)
        {
            //如果链表A更长，则将指针pA移动到与链表B等长的位置
            pA = headA;
            for(int i = 0; i < lenA - lenB; i++)
            {
                pA = pA->next;
            }
            pB = headB;
        }
        else
        {
            //如果链表B更长，则将指针pB移动到与链表A等长的位置
            pB = headB;
            for(int i = 0; i < lenB - lenA; i++)
            {
                pB = pB->next;
            }
            pA = headA;
        }
        while(pA && pB){
            if(pA == pB) return pA;
            pA = pA->next;
            pB = pB->next;
        }
        return NULL;
    }
};