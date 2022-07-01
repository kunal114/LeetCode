class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        int i=0,j=0;
        int n1=version1.length(),n2=version2.length();
        int num1,num2;//to fetch each no. before and after '.'
        
        while(i<n1 || j<n2){
            num1=0;
            num2=0;
            
            //fetching no from V1 before '.'
            while(i<n1 and version1[i]!='.'){
                num1 = num1*10 + (version1[i]-'0');
                i++;
            }
            
            //fetching no from V2 before '.'
            while(j<n2 and version2[j]!='.'){
                num2 = num2*10 + (version2[j]-'0');
                j++;
            }
            
            if(num1>num2) return 1;
            else if(num1<num2) return -1;
            
            //skip next '.'
            i++;
            j++;
        }
        return 0;
    }
};