class Solution {
public:
    int myAtoi(string s) {
        if(s.length()==0) return 0;
        int i=0;
        
        //Removing leading spaces
        while(i<s.size() and s[i]==' '){
            i++;
        }
        
        //saving rest of the string
        s = s.substr(i);
        
        //sign of the ans
        int sign = +1;//default
        if(s[0]=='-') sign = -1;
        
        //start traversing the meaningful string        
        long ans=0;
        int MAX = INT_MAX, MIN = INT_MIN;
        i = (s[0]=='+' || s[0]=='-')?1:0;//updating the starting of the string
        while(i<s.length()){
            if(s[0]==' ' || !isdigit(s[i])) break;
            
            ans = ans*10 + (s[i]-'0');
            if(sign==-1 && -1*ans<MIN) return MIN;
            if(sign==+1 && ans>MAX) return MAX;
            
            i++;
        }
        return (int)(sign*ans);
    }
};