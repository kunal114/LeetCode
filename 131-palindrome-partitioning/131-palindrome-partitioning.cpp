
class Solution {
public:
    bool isPal(string s,int i,int j){
    // int i=0,j=s.length();
    while(i<=j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
    void func(int index, string s, vector < string > & path,vector < vector < string > > & res) {
        if (index == s.size()) {
          res.push_back(path);
          return;
        }
        for (int i = index; i < s.size(); ++i) {
          if (isPal(s, index, i)) {
            path.push_back(s.substr(index, i - index + 1));//0,1
            func(i + 1, s, path, res);
            path.pop_back();
          }
        }
      }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> str;
        func(0,s,str,ans);
        return ans;
    }
};