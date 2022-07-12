// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    bool cycle(vector<int> adj[],vector<bool> &vis,vector<bool> &self,int node){
        vis[node] = 1;
        self[node] = 1;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it] = true;
                self[it] = true;
                if(cycle(adj,vis,self,it)) return true;
            }
            else if(vis[it] and self[it]) return true;
        }
        self[node] = false;
        return false;
        
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> vis(V,0);
        vector<bool> self(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(cycle(adj,vis,self,i)) return true;
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends