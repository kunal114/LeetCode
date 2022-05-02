// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int A[], int n1)  { 
	    // Your code goes here
	    int range=0;
    for(int i=0;i<n1;i++){
        range+=A[i];
    }

    int dp[n1+1][range+1];
    for(int j=0;j<range+1;j++){
        dp[0][j] = false;
    }
    for(int i=0;i<n1+1;i++){
        dp[i][0] = true;
    }

    for(int i=1;i<n1+1;i++){
        for(int j=1;j<range+1;j++){
            if(A[i-1]<=j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-A[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    vector<int> ans ;
    for(int i=0;i<=range/2;i++)
    {
        if(dp[n1][i] == true)
        {
            ans.push_back(i);
        }
    }
    int sum=INT_MAX;
    for(int j=0;j<ans.size();j++){
        sum = min(range-2*ans[j], sum);
    }
    return sum;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends