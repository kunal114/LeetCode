class Solution {
public:
    int subsetsum(vector<int> &arr,int n,int sum){
        int dp[n+1][sum+1];
        for(int j=0;j<sum+1;j++){
            dp[0][j] = 0;
        }
        for(int i=0;i<n+1;i++){
            dp[i][0] = 1;
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(arr[i-1]<=j){
                    dp[i][j] = dp[i-1][j]+dp[i-1][j-arr[i-1]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        //s1-s2 = target
        //-sum+2s1 = target
        //s1 = (sum+target)/2;
        int sum=0;
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int s1 = (sum+target)/2;
        if(sum<target||(sum+target)%2!=0||(sum+target)<0){
            return 0;
        }
        int ans=subsetsum(nums,nums.size(),s1);
        return ans;
    }
};