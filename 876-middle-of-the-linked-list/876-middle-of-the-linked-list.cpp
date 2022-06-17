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
    ListNode* middleNode(ListNode* head) {
        
        ListNode *temp = head;
        if(temp==NULL || temp->next==NULL){
            return head;
        }
        int cnt = 0;
        while(temp!=NULL){
            temp=temp->next;
            cnt++;
        }
        cnt = cnt/2;
        int k=0;
        while(k<cnt){
            head=head->next;
            k++;
        }
        return head;
    }
};