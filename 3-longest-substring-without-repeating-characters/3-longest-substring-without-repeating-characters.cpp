class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx = INT_MIN;
          unordered_set < int > ss;
          int l = 0;
          for (int r = 0; r < s.length(); r++)
          {
            if (ss.find(s[r]) != ss.end()) //if duplicate element is found
            {
              while (l < r && ss.find(s[r]) != ss.end()) {
                ss.erase(s[l]);
                l++;
              }
            }
            ss.insert(s[r]);
            mx = max(mx, r - l + 1);
          }
        if(s.length()==0||s.length()==1){
            return s.length();
        }
          return mx;
    }
};