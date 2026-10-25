GFG: Undirected Graph Cycle
Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

Note: The graph can have multiple component.

Examples:

Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
Output: true
Explanation: 

1 -> 2 -> 0 -> 1 is a cycle.
Input: V = 4, E = 3, edges[][] = [[0, 1], [1, 2], [2, 3]]
Output: false
Explanation: 

No cycle in the graph.
Constraints:
1 ≤ V, E ≤ 105
0 ≤ edges[i][0], edges[i][1] < V

APPROACH: DFS

//USING DFS

class Solution {
  public:
    bool dfs(int start, int parent, vector<int>&vis, vector<vector<int>>&adj){
        
        //mark the first index as visited
        vis[start] =0;
        
        for(auto it : adj[start]){
            
            if(vis[it] == -1){
                bool isCycle = dfs(it, start, vis, adj);
                if(isCycle) return true;
            }
            else{
                if(it != parent){
                    return true;
                }
            }
        }
        
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        //decalaring the adj list
        vector<vector<int>>adj(V);
        
        //initializing
        for(auto it : edges){
            
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>vis(V, -1);
        
        for(int i=0; i<V; i++){
            
            if(vis[i] == -1){
                
                bool isCycle = dfs(i, -1, vis, adj);
                if(isCycle)  return true;
            }
        }
        
        return false;
        
    }
};

