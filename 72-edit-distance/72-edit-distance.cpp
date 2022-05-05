// #include<bits/stdc++.h>
class Solution {
public:
    int minDistance(string s, string t) {
        int n1 = s.length(), n2 = t.length();
        int dp[n1+1][n2+1];
        if(n1==0 and n2!=0 || n1!=0 and n2==0){
            return 1;
        }
        
        for(int j=0;j<n2+1;j++){
            dp[0][j] = j ;
        }
        
        for(int i=0;i<n1+1;i++){
            dp[i][0] = i;
        }
        
        for(int i=1;i<n1+1;i++){
            for(int j=1;j<n2+1;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                
                else{
                    dp[i][j] = min(dp[i-1][j-1]+1,min(dp[i-1][j]+1,dp[i][j-1]+1));
                }
            }
        }
        return dp[n1][n2];
    }
};