class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();//rows
        int m = matrix[0].size();//columns
        cout<<m<<" "<<n;
        int dp[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||j==0){
                    dp[i][j] = matrix[i][j];
                }
                else if(matrix[i][j]==0){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                    dp[i][j]++;
                    
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans += dp[i][j];
            }
        }
        return ans;
    }
};