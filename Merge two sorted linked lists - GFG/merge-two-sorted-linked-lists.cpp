// { Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends
Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    Node *l1=head1,*l2=head2;
    if(l1 == NULL) return l2; 
    if(l2 == NULL) return l1;
        if(l1->data > l2->data) std::swap(l1,l2);
        Node* res = l1;
        while(l1 != NULL && l2 != NULL) {
            Node* temp = NULL;
            while(l1 != NULL && l1->data <= l2->data) {

                temp = l1; 
                l1 = l1->next;
            }
            temp->next = l2;
            std::swap(l1,l2);
        }
        return res;
}  