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
    void rec(int n,int i,int open,int close,string s,vector<string> &ans){
        if(i==2*n){
            ans.push_back(s);
            return;
        }
        
        //if open bracket are more it means we can add a closing bracket
        if(open>close){
            rec(n,i+1,open,close+1,s+')',ans);
        }
        //if open brackets are less than n i.e. open brackets are available so we can add it
        if(open<n){
            rec(n,i+1,open+1,close,s+'(',ans);
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here
        vector<string> ans;
        string s="";
        int open=0,close=0,i=0;
        rec(n,i,open,close,s,ans);
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