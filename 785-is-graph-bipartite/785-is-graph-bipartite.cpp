class Solution {
public:
    bool bfsCheck(vector<vector<int>> graph,vector<int> &color,int node){
        
        queue<int> q;//node,colour
        q.push(node);
        color[node] = 1;//starting color=1
        
        while(!q.empty()){
            int curr = q.front(); //curr:it1,it2.....
            q.pop();
            
            for(auto it:graph[curr]){
                if(color[it]==-1){
                    color[it] = 1-color[curr];//0 if 1 &&& 1 if 0
                    q.push(it);
                }
                else if(color[curr]==color[it]){
                    return false;
                }
            }
            
            
        }
        
        return true;
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(!bfsCheck(graph,color,i)) return false;
            }
        }
        return true;
    }
};