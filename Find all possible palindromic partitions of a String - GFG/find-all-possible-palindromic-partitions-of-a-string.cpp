// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  bool isPal(string s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void rec(string s,int i,vector<string> v,vector<vector<string>> &ans){
        if(i==s.length()){
            ans.push_back(v);
            return;
        }
        
        for(int ind=i;ind<s.length();++ind){
            if(isPal(s,i,ind)){
                v.push_back(s.substr(i,ind-i+1));
                rec(s,ind+1,v,ans);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string s) {
        // code here
        vector<vector<string>> ans;
        vector<string> v;
        rec(s,0,v,ans);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends