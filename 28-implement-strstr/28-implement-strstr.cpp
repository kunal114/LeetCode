class Solution {
public:
    /*int simple(string s,string pat){
        int m = pat.size();
        int n = s.size();
        for(int i=0;i<n-m+1;i++){
            if(pat==s.substr(i,m)){
                return i;
            }
        }
        return -1;
    }
    */
    /*vector<int> computeLPSArray(string needle) {
        int m = needle.size();
        vector<int> lps(m);
        lps[0] = 0;

        int i = 1;
        int len = 0;

        while(i < m) {
            if(needle[i] == needle[len]) {
                lps[i] = len + 1;
                len++;
                i++;
            } else {
                if(len == 0) {
                    i++;
                } else {
                    len = lps[len - 1];
                }
            }
        }

        return lps;
    }
    int kmp(string haystack, string needle){
        vector<int> lps = computeLPSArray(needle);

        int n = haystack.size(), m = needle.size();

        int i = 0;
        int j = 0;

        while(i < n) {
            if(haystack[i] == needle[j]) {
                i++, j++;
            } else {
                if(j == 0) {
                    i++;
                } else {
                    j = lps[j-1];
                }
            }
            if(j == m) {
                return i - j;
            }
        }

        return -1;
    }*/
    int Z_algo(string s,string pat){
        int m = pat.size();
        int n = s.size();
        int ans;
        string str = pat+"#"+s;
        vector<int> z;
        
        int i=0;
        while(i<str.size()){
            if(i<=m) z.push_back(0);
            else{
                int left = 0,right = 0;
                if(str[left]==str[i]){
                    right=i;
                    while(str[left]==str[right] and right<str.length()){
                        left++;
                        right++; 
                    }
                }
                z.push_back(left);                
            }
            i++;
        }
        for(int i=0;i<z.size();i++){
            if(z[i]==m) return i-m-1;
        }
        return -1;
    }
    int strStr(string haystack, string needle) {
        
        // int ans = simple(haystack, needle);
        // int ans = kmp(haystack, needle);        
        // int ans = RabinKarp(string haystack, string needle);
        int ans = Z_algo(haystack,needle);
        
        return ans;

    }
};