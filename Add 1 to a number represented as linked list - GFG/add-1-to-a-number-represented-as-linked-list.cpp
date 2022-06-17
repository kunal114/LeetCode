// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverseLinkedList (Node* head) {
	Node* previous = NULL;
	Node* current = head;
	Node* next;
	while (current != NULL) {
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	return previous;
}
    Node* addOne(Node *head) 
    {
        head = reverseLinkedList(head);
        Node* currNode = head;
    	Node* prev = NULL;
    	int carry = 1;
    	while (currNode != NULL) {
    		currNode->data = currNode->data + carry;
    		carry = (currNode->data) / 10;
    		currNode->data = (currNode->data) % 10;
    		prev = currNode;
    		currNode = currNode->next;
    	}
    	if (carry != 0) {
    		Node* newNode = new Node(carry);
    		prev->next = newNode;
    	}
    	return reverseLinkedList(head);
        
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends