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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next!=NULL and fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *p =new ListNode();
        p=slow->next;
        //reverse linked list starting from p
        ListNode *prev = NULL;
        ListNode *curr = p;
        ListNode *nxt = new ListNode();
        while(curr!=NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        slow->next = prev;
        ListNode *temp = head;
        while(prev!=NULL){
            if(prev->val!=temp->val){
                return false;
            }
            temp=temp->next;
            prev=prev->next;
        }
        return true;
        
    }
};