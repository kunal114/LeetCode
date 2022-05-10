// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nCr(int n, int r){
        // code here
        int dp[r+1][n+1];
        int m = 1000000007;
        for(int i=0;i<r+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || i==j){
                    dp[i][j] = 1;
                }
                else if(i>j){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = (dp[i][j-1]+dp[i-1][j-1])%m; //(n+1)Cr = nCr+nC(r-1)
                }
            }
        }
        return dp[r][n]%m;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends