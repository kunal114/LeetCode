class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        if(strs.size()==0) return ans;
        
        for(int i=0;i<strs[0].size();i++){
            char ch = strs[0][i]; //first word ka iTH alphabet
            
            //now match ch with ith alphabet of all other words
            bool match=true;
            
            //jTH word ka iTH alphabet
            for(int j=0;j<strs.size();j++){
                if(strs[j][i] != ch){
                    match = false;
                    break;
                }
            }
            if(match==false) break;
            else ans+=ch;
        }
        return ans;
    }
};