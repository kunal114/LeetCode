// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

int binary_search(int arr[],int n,int x,int index){
    int low=0;
    int high=n-1;
    int ans = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]>x){
            high = mid-1;
        }
        else if(arr[mid]<x){
            low = mid+1;
        }
        else{
            ans = mid;
            //if we want first occurence, we need to shift high towards left
            if(index==-1){
                high = mid+index;
            }
            else{
                low = mid+index;
            }
        }
    }
    return ans;
}
vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int> ans;
    int first=-1,last=-1;
    first = binary_search(arr,n,x,-1);
    last = binary_search(arr,n,x,1);
    ans.push_back(first);
    ans.push_back(last);
    return ans;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends