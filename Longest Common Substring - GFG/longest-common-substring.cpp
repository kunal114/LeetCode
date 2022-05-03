// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string str1, string str2, int N, int M)
    {
        // your code here
        int LCSuff[N + 1][M + 1];
        int mx = 0;    
        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= M; j++)
            {
                  if (i == 0 || j == 0){
                    LCSuff[i][j] = 0;
                  }
     
                else if (str1[i - 1] == str2[j - 1]) {
                    LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                    mx = max(mx, LCSuff[i][j]);
                }
                else
                    LCSuff[i][j] = 0;
            }
        }
        return mx;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends