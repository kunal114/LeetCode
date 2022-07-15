class Solution {
public:
    int dfs(vector<vector<int>>& grid,vector<vector<bool>> &vis,int i,int j){
        int m=grid.size(),n=grid[0].size();
        
        int ans=1;//singular island
        vis[i][j]=true;
        
        //top,bottom,left,right
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        
        for(int k=0;k<4;k++){
            int x = i+dx[k];
            int y = j+dy[k];
            
            if(x>=0&&x<m and y>=0&&y<n and !vis[x][y] and grid[x][y]==1){
                ans += dfs(grid,vis,x,y);
            }
        }
        
        return ans;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int mx=0;
        
        vector<vector<bool>> vis(m,vector<bool> (n,false));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] and grid[i][j]==1){
                    int island = dfs(grid,vis,i,j);
                    mx = max(mx,island);
                }
            }
        }
        
        return mx;
    }
};