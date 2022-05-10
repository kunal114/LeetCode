class Solution {
public:
    int countSubstrings(string s, string t) {
        int m = s.size();
        int n = t.size();
        
        int dp[m+1][n+1][2];
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0||j==0){
                    dp[i][j][0] = 0;
                }
                else if(s[i-1]!=t[j-1]){
                    dp[i][j][0] = 0;
                }
                else{
                    dp[i][j][0] = dp[i-1][j-1][0]+1;
                }
            }
        }
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0||j==0){
                    dp[i][j][1] = 0;
                }
                else if(s[i-1]==t[j-1]){
                    dp[i][j][1] = dp[i-1][j-1][1];
                }
                else{
                    dp[i][j][1] = dp[i-1][j-1][0]+1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                ans+=dp[i][j][1];
            }
        }
        return ans;
    }
};