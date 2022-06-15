// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void swap(int *a,int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    void sort012(int a[], int n)
    {
        // code here 
        int i = 0,mid = 0,j=n-1;
        while(mid<=j){
            if(a[mid]==0){
                swap(&a[mid],&a[i]);
                mid++;
                i++;
            }
            else if(a[mid]==2){
                swap(&a[mid],&a[j]);
                j--;
            }
            else{
                mid++;
            }
        }
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends