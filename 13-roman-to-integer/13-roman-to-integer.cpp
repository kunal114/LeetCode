class Solution {
public:
    int priority(char c){
        if(c=='I') return 1;
        else if(c=='V') return 2;
        else if(c=='X') return 3;
        else if(c=='L') return 4;
        else if(c=='C') return 5;
        else if(c=='D') return 6;
        else if(c=='M') return 7;
        else return -1;
    }
    int fetch(char c){
        if(c=='I') return 1;
        else if(c=='V') return 5;
        else if(c=='X') return 10;
        else if(c=='L') return 50;
        else if(c=='C') return 100;
        else if(c=='D') return 500;
        else if(c=='M') return 1000;
        else return -1;
    }
    int romanToInt(string s) {
        
        int ans = 0;
        for(int i=0;i<s.length();){
            if(i==s.length()-1 || priority(s[i])>=priority(s[i+1])){
                ans += fetch(s[i]);
                i++;
            }
            else{
                ans += fetch(s[i+1])-fetch(s[i]);
                i+=2;
            }
        }
        return ans;
    }
};