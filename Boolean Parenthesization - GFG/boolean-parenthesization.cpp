// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution{
public:
    
   unordered_map<string,int>mp;
   int mod=1003;
   int solve(string s,int i,int j,bool isTrue){
       if(i>j)
       return 0;
       if(i==j){
           if(isTrue==true)
               return s[i]=='T';
           else
               return s[i]=='F';
       }   
       int ans=0;
       string temp=to_string(i)+' '+to_string(j)+' '+to_string(isTrue);
       
       if(mp.find(temp)!=mp.end())
           return mp[temp];
       
       for(int k=i+1;k<=j-1;k+=2){
           int lt=solve(s,i,k-1,true);
           int lf=solve(s,i,k-1,false);
           int rt=solve(s,k+1,j,true);
           int rf=solve(s,k+1,j,false);
           
           
           if(s[k]=='&'){
               if(isTrue==true)
               ans=ans+(lt*rt);
               else
               ans=ans+(lf*rf)+(lt*rf)+(lf*rt);
           }
          else if(s[k]=='|'){
               if(isTrue==true)
               ans=ans+(lt*rt)+(lt*rf)+(lf*rt);
               else
               ans=ans+(lf*rf);
               
               
           }
           else if(s[k]=='^'){
               if(isTrue==true)
               ans=ans+(lt*rf)+(lf*rt);
               else
               ans=ans+(lf*rf)+(lt*rt);
           }
       }    
       return mp[temp]=ans%mod;
       
   }
   int countWays(int N, string S){
       mp.clear();
       return solve(S,0,N-1,true)%mod;
   }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends