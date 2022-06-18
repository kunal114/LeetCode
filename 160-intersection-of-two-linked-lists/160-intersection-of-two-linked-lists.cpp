/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        int l1=0,l2=0;
        while(temp1!=NULL){
            l1++;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            l2++;
            temp2=temp2->next;
        }
        temp1= headA;
        temp2= headB;
        if(l1<l2){
            int left = l2-l1;
            while(left>0){
                temp2=temp2->next;
                left--;
            }
        }
        if(l1>l2){
            int left = l1-l2;
            while(left>0){
                temp1=temp1->next;
                left--;
            }
        }
        while(temp1!=NULL and temp2!=NULL){
            if(temp1==temp2){
                return temp1;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return NULL;
    }
};