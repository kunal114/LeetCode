class Solution {
public:
    
    bool dfs(vector<int>& matchsticks,vector<int> &sides, int side,int ind){
        if(ind==matchsticks.size()){
            if(sides[0]==sides[1] and sides[1]==sides[2] and sides[2]==sides[3])
                return true;
            
            return false;
        }
        
        for(int i=0;i<4;i++){
            if(sides[i]+matchsticks[ind]>side) continue; //dont add
            int j=i-1;
            while(j>=0){
                if(sides[j]==sides[i]) break;
                j--;
            }
            if(j!=-1) continue;
            sides[i]+=matchsticks[ind];
            if(dfs(matchsticks,sides,side,ind+1)) return true;
            sides[i]-=matchsticks[ind];
        }        
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        int n = matchsticks.size();
        for(int i=0;i<n;i++){
            sum+=matchsticks[i];
        }
        
        if(sum%2!=0) return false;
        int side = sum/4;
        
        vector<int> sides(4,0);
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        
        return dfs(matchsticks,sides,side,0);
    }
};