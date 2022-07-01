class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp1,mp2;
        if(s.size()!=t.size()) return false;
        for(int i=0;i<s.size();i++){
            mp1[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            mp2[t[i]]++;
        }
        
        for(int i=0;i<t.size();i++){
            if(mp1[t[i]]!=mp2[t[i]]) return false;
        }
        return true;
    }
};