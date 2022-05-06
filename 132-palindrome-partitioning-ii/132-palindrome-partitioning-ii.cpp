// static int dp[2001][2001];
class Solution {
public:
    int dp[2001][2001];
    bool isPallindrome(string &str, int i, int j)
    {
        while(i<j)
        {
            if(str[i]!=str[j]) return false;
            i++; j--;
        }
        return true;
        
    }
    int MCM(string &str, int i, int j)
    {
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(isPallindrome(str,i,j)) return 0;
        int ans = INT_MAX;
        int left,right;
        for(int k = i; k<=j-1; k++)
        {
            if(isPallindrome(str,i,k))
            {
                if(dp[i][k]!=-1)
                {
                    left = dp[i][k];
                }
                else
                {
                    left = MCM(str,i,k);
                    dp[i][k] = left;
                }

                if(dp[k+1][j]!=-1)
                {
                    right = dp[k+1][j];
                }
                else
                {
                    right = MCM(str,k+1,j);
                    dp[k+1][j] = right;
                }
                int temp = 1 + left + right;
                ans = min(ans,temp);
            }
        }
        
        return dp[i][j] = ans;
    }
    int minCut(string s) {
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        return MCM(s,0,n-1);
        
    }
};