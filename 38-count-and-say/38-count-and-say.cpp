class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        if(n==2) return "11";
        
        string s = "11";
        
        for(int i=3;i<=n;i++){
            string temp="";
            s=s+'&';//to consider last element of the string in the count
            int cnt=1;
            
            for(int j=1;j<s.size();j++){
                if(s[j]==s[j-1]){
                    cnt++;
                }
                else{
                    temp+=to_string(cnt)+s[j-1];
                    cnt=1;
                }
            }
            
            s=temp;
        }
        
        return s;
    }
};