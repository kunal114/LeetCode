// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

bool isValid(bool graph[101][101],int v,int color[], int c,int V) {    //check whether putting a color valid for v
   for (int i = 0; i < V; i++)
      if (graph[v][i] && c == color[i])
         return false;
   return true;
}
bool graphColoring(bool graph[101][101],int colors, int color[], int vertex,int V) {
   if (vertex == V)    //when all vertices are considered
      return true;

   for (int col = 1; col <= colors; col++) {
      if (isValid(graph,vertex,color, col,V)) {     //check whether color col is valid or not
         color[vertex] = col;
         if (graphColoring (graph,colors, color, vertex+1,V) == true)    //go for additional vertices
            return true;
                   
         color[vertex] = 0;
      }
   }
   return false; //when no colors can be assigned
}
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour
bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    int *color = new int[n];    //make color matrix for each vertex
    for (int i = 0; i < n; i++) 
       color[i] = 0;      //initially set to 0

    return graphColoring(graph,m, color, 0 ,n);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends