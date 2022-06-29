class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m=grid.size(),n=grid[0].size(),total=0,rotten_count=0,days=0;
        queue<pair<int,int>> rotten;
        
        //Initial rotten apples and total no of apples
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0) total++;
                if(grid[i][j]==2) rotten.push({i,j});
            }
        }
        
        //Directions(up,down,right,left)(y==x and x==y in our case)
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = { 0, 0, 1,-1};
        
        //Now start popping elements from queue and checking in all directions for fresh apples
        while(!rotten.empty()){
            int k = rotten.size();
            rotten_count += k;
            
            while(k--){
                //store coordinates and pop front of the queue
                int x = rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();
                //now check four directions for fresh apples 
                for(int i=0;i<4;i++){
                    int newx = x+dx[i];
                    int newy = y+dy[i];
                    //if index not possible and apple is not fresh
                    if(newx<0 || newy<0 || newx>=m || newy>=n ||grid[newx][newy]!=1)
                    {
                        continue;
                    }
                    // else
                    grid[newx][newy] = 2;
                    rotten.push({newx,newy});
                }
            }
            if(!rotten.empty()) days++  ;
        }
        
        return total==rotten_count?days:-1;
    }
};