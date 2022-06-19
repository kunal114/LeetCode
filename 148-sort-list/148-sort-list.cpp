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
    
    
     ListNode *middleNode(ListNode *head)
   {
       ListNode *ptr = head;
       ListNode *q = head->next;
       while(q != NULL && q->next != NULL)
       {
           ptr = ptr->next;
           q = q->next->next;
       }
       return ptr;
   }
    ListNode *merge(ListNode *a,ListNode *b)
    {
        ListNode *head,*tail;
        if(a==NULL)
        {
            return b;
        }
        if(b==NULL)
        {
            return a;
        }
        if(a->val<=b->val)
        {
            head=a;
            tail=head;
            a=a->next;
        }
        else
        {
            head=b;
            tail=head;
            b=b->next;
        }
        while(a!=NULL && b!=NULL)
        {
            if(a->val<=b->val)
            {
                tail->next=a;
                a=a->next;
                tail=tail->next;
            }
            else
            {
                tail->next=b;
                b=b->next;
                tail=tail->next;
            }
        }
        if(a!=NULL)
        {
            tail->next=a;
        }
        else if(b!=NULL)
        {
            tail->next=b;
        }
        return head;
    }
    ListNode* sortList(ListNode* head) {
        // your code here
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode *middle=middleNode(head);
        ListNode *right=middle->next;
        middle->next=NULL;
        ListNode *l=sortList(head);
        ListNode *r=sortList(right);
        ListNode *ans=merge(l,r);
        return ans;
    }
};