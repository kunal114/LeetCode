class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            sum += arr[i];
        }
        if(sum%2==0){
            sum/=2;
            bool dp[n+1][sum+1];
            for(int j=0;j<sum+1;j++){
                dp[0][j] = false;
            }
            for(int i=0;i<n+1;i++){
                dp[i][0] = true;
            }

            for(int i=1;i<n+1;i++){
                for(int j=1;j<sum+1;j++){
                    if(arr[i-1]<=j){
                        dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                    }
                    else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
            return dp[n][sum];
        }
        else{
        }    return false;
        }
        
};