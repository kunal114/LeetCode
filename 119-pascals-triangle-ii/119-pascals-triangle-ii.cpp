class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans(rowIndex+1);
        
        for(int i=0;i<rowIndex+1;i++){
            vector<int> dp(i+1);
            dp[0]=1;
            dp[i]=1;
            int k=1;
            while(k<i){
                dp[k]=ans[i-1][k-1]+ans[i-1][k];
                k++;
            }
            ans[i]=dp;
        }
        return ans[rowIndex];
    }
};