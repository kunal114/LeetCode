// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void recursion(int open,int close,int i,int n,string s,vector<string> &ans){
        if(i==2*n){
            ans.push_back(s);
        
            return;
        }
        if(open<n){
            recursion(open+1,close,i+1,n,s+'(',ans);
        }
        if(close<open){
            recursion(open,close+1,i+1,n,s+')',ans);
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string> ans;
        string s="";
        recursion(0,0,0,n,s,ans);
        return ans;
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends