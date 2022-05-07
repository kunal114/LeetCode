class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        if(numRows==0){
            return ans;
        }
        
        for(int i=0;i<numRows;i++){
            vector<int> dp(i+1);
            dp[0]=1;
            dp[i]=1;
            int k =1;
            while(k<i){
                dp[k] = ans[i-1][k-1]+ans[i-1][k];
                k++;
            }
            
    ans[i]=dp;
        }
        return ans;
    }
};