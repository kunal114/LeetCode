// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	void dfs(vector<int> adj[],vector<bool> &vis,vector<int> &ans,int node){
	    vis[node] = true;
	    
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            vis[it] = true;
	            dfs(adj,vis,ans,it);
	        }
	    }
	   // s.push(node);
	    ans.insert(ans.begin(),node);
	}
	
	void cal_indegree(vector<int> adj[],int V,vector<int> &indegree){
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	}
	void bfs(vector<int> adj[],vector<int> &indegree,int V,vector<int> &ans){
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0) q.push(i);
	    }
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        
	        for(auto it:adj[node]){
	            indegree[it]--;
	            if(indegree[it]==0) q.push(it);
	        }
	    }
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> ans;
	    vector<bool> vis(V,0);
	   // stack<int> s;
	   
	    vector<int> indegree(V,0);
	    
	    for(int i=0;i<V;i++){
	       // if(!vis[i]) 
	           // dfs(adj,vis,s,i);
	           // dfs(adj,vis,ans,i);
	           
	    }
	   cal_indegree(adj,V,indegree);
	   bfs(adj,indegree,V,ans);
	    
	   // while(!s.empty()){
	   //     ans.push_back(s.top());
	   //     s.pop();
	   // }
	    
	    return ans;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends