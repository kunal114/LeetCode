// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[101][10001];
    int Solve(int eggs, int floors) {
	if (dp[eggs][floors] != -1) // if value is already there in the table then return the value 
		return dp[eggs][floors];

	if (eggs == 1 || floors == 0 || floors == 1) { // base condition
		dp[eggs][floors] = floors;
		return floors;
	}

	int mn = INT_MAX;
	for (int k = 1; k <= floors; k++) {
		int top, bottom;
		if (dp[eggs - 1][k - 1] != -1) // break the temp in sub problemes 
			top = dp[eggs - 1][k - 1];
		else {
			top = Solve(eggs - 1, k - 1);
			dp[eggs - 1][k - 1] = top;
		}

		if (dp[eggs][floors - k] != -1)
			bottom = dp[eggs][floors - k];
		else {
			bottom = Solve(eggs, floors - k);
			dp[eggs][floors - k] = bottom;
		}
		int temp_ans = 1 + max(top, bottom);
		mn = min(mn, temp_ans);
	}

	return dp[eggs][floors] = mn;
}
    int eggDrop(int e, int f) 
    {
        // your code here
        memset(dp,-1,sizeof(dp));
        return Solve(e,f);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends