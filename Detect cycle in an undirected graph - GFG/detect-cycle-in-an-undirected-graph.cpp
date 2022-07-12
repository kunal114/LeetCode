// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    bool bfsCheck(vector<int> adj[],vector<bool> &vis,int V,int node){
        queue<pair<int,int>> q; //curr_node,parent_node
        q.push({node,-1});
        vis[node]=true;
        
        while(!q.empty()){
            int curr = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto it:adj[curr]){
                if(!vis[it]){
                    vis[it]=true;
                    q.push({it,curr});
                }
                else if(parent!=it){
                    return true;
                }
            }
        }
        
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(bfsCheck(adj,vis,V,i)) return true;
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends