// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
  
     Node *middleNode(Node *head)
   {
       Node *ptr = head;
       Node *q = head->next;
       while(q != NULL && q->next != NULL)
       {
           ptr = ptr->next;
           q = q->next->next;
       }
       return ptr;
   }
    Node *merge(Node *a,Node *b)
    {
        Node *head,*tail;
        if(a==NULL)
        {
            return b;
        }
        if(b==NULL)
        {
            return a;
        }
        if(a->data<=b->data)
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
            if(a->data<=b->data)
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
    Node* mergeSort(Node* head) {
        // your code here
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        Node *middle=middleNode(head);
        Node *right=middle->next;
        middle->next=NULL;
        Node *l=mergeSort(head);
        Node *r=mergeSort(right);
        Node *ans=merge(l,r);
        return ans;
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends