class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        dp[0] = 0;
        for(int i=0;i<n+1;i++){
            dp[i]=i%2+dp[i/2];
        }
        return dp;
    }
};