// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

unordered_map<string,int> dp; //dp map

class Solution
{
public:

    int solve(string a,vector<string> &b){
        int n = a.size();
        if(n==0) return 1;
        if(dp[a]!=0) return dp[a];
        
        //starting from i=1 bcoz of substr
        for(int i=1;i<=n;i++){
            int f=0; //flag
            string s = a.substr(0,i);//starting_index,length
            for(int j=0;j<b.size();j++){
                if(s.compare(b[j])==0){
                    f=1;
                    break;
                }
            }
            
            if(f==1 and solve(a.substr(i,n-i),b)==1) return dp[a]=1;
        }
        return dp[a] = -1;
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        if(solve(A,B)==1) return 1;
        return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends