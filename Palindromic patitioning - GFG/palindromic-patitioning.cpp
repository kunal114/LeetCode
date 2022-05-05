// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
static int dp[1000][1000];
class Solution{
public:
    bool isPalindrome(string s,int i,int j){
        while(i <=j)
        {
          if(s[i] != s[j])
            return false; 
          i++;
          j--;
        }
        return true;
    }
    int solve(string s,int i,int j){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(isPalindrome(s,i,j)==true){
            return 0;
        }
        int ans = INT_MAX,left,right;
        for(int k=i;k<j;k++){
            if(dp[i][k]!=-1){
                left = dp[i][k];
            }
            else{
                left = solve(s,i,k);
                dp[i][k] = left;
            }
            
            if(dp[k+1][j]!=-1){
                right = dp[k+1][j];
            }
            else{
                right = solve(s,k+1,j);
                dp[k+1][j] = right;
            }
            
            int temp = left+right+1;
            ans = min(ans,temp);
        }
        return dp[i][j]=ans;
    }
    int palindromicPartition(string str)
    {
        // code here
        memset(dp,-1,sizeof(dp));
        int n= str.length();
        return solve(str,0,n-1);
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends