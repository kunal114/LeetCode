// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int nums[], int size)
    {
        
        unordered_map<int,int> mp;
        for(int i=0;i<size;i++){
            mp[nums[i]]++;
        }
        
        int  ans=0;
        for(int i=0;i<size;i++){
            if(mp[nums[i]]>size/2){
                ans=nums[i];
                break;
            }
        }
        if(ans==0){
            return -1;
        }
        return ans;
        
    }
};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends