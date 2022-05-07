class Solution {
public:
    int solve(int n){
        int dp[n+1];
        
        if(n==0 || n==1){
            return n;
        }
        dp[0]=0;
        dp[1]=1;
        
        for(int i=2;i<n+1;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int fib(int n) {
        return solve(n);
    }
};