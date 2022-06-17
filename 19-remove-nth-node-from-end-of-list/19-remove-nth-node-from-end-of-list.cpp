/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){
            return head;
        }
        int cnt =0 ;
        ListNode *temp = head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        
        cnt = cnt-n;
        if(cnt==0){
            return head->next;
        }
        
        ListNode *cur = head;
        ListNode *prev = NULL;
        
        while(cnt>0){
            prev = cur;
            cur = cur->next;
            cnt--;
        }
        
        prev->next = cur->next;
        cur->next = NULL;
        delete cur;
        
        return head;
    }
};