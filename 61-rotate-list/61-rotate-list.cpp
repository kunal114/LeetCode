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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *temp = head;
        int cnt = 0;
        if(!head){return NULL;}
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        temp = head;
        k = k%cnt;
        cnt = cnt-k;
        ListNode *prev = NULL;
        ListNode *curr = temp;
        ListNode *nxt  = new ListNode();
        while(cnt>0 and curr!=NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            cnt--;
        }
        // temp->next = curr;
        head = prev;
        
        prev = NULL;
        while(curr!=NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        temp->next = prev;
        
        prev = NULL;
        curr = head;
        while(curr!=NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        return prev;
    }
};