string keypad[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
class Solution {
public:
    void rec(string digits,int i,string s,vector<string> &ans){
        if(digits[i]=='\0'){
            ans.push_back(s);
            return;
        }
        int current_digit = digits[i]-'0';
        if(current_digit==0 || current_digit==1){
            rec(digits,i+1,s,ans);
        }
        for(int j=0;j<keypad[current_digit].size();++j){
            rec(digits,i+1,s+keypad[current_digit][j],ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        rec(digits,0,"",ans);
        return ans;
    }
};