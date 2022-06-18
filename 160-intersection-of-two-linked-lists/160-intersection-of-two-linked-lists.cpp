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
        unordered_set<ListNode*> s;
        
        while(temp1!=NULL && temp2!=NULL){
            if(temp1==temp2){
                return temp1;
            }
            else if(s.find(temp1)!=s.end()){
                return temp1;
            }
            else if(s.find(temp2)!=s.end()){
                return temp2;
            }
            else{
                s.insert(temp1);
                s.insert(temp2);
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
        while(temp1!=NULL){
            if(s.find(temp1)!=s.end()){
                return temp1;
            }
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            if(s.find(temp2)!=s.end()){
                return temp2;
            }
            temp2=temp2->next;
        }
        return NULL;
    }
};