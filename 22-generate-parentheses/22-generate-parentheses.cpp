class Solution {
public:
    
    void solve(int n,int open,int close,vector<string> &s,string str){
        
        if(size(str)==2*n){
            s.push_back(str);
        }
        if(open<n){
            solve(n,open+1,close,s,str+'(');
        }
        if(close<open){
            solve(n,open,close+1,s,str+')');
        }
    }
    vector<string> generateParenthesis(int n){
        vector<string> s;
        solve(n,0,0,s,"");//close,open==0
        return s;
    }
};