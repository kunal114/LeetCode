class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        int dp[n+1];
        dp[0] = 0;
        ans.push_back(0);
        
        for(int i=1;i<n+1;i++){
            dp[i]=i%2+dp[i/2];
            ans.push_back(dp[i]);
        }
        
        return ans;
    }
};