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

APPROACH: BFS

class Solution {
  public:
    bool bfs(int node, int parent, vector<vector<int>>&adj, vector<int>&vis){
        
        vis[node] = 0;
        queue<pair<int, int>>q;
        
        //pushing the first element
        q.push({node, parent});
        
        
        //run this untill queue is empty
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            //traverse the neighbours
            for(auto it : adj[node]){
                if(vis[it] == -1){
                    q.push({it, node});
                    vis[it] = 0;
                }
                else{
                    //means the node is already visited by some other node, hence cycle present;
                    if(parent != it)
                    return true;
                }
            }
            
        }
        
        return false;
        
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        //decalring and adj list
        vector<vector<int>>adj(V);
        
        //initializing the adj list
         for(auto &it: edges){
             
             int u = it[0];
             int v = it[1];
             
             adj[u].push_back(v);
             adj[v].push_back(u);
         }
        
        //declaring vis array
        vector<int>vis(V, -1);
        
        for(int i=0; i<V; i++){
            if(vis[i] == -1){
                
                bool isCycle = bfs(i, -1, adj, vis);
                if(isCycle) return true;
            }
        }
        
       return false;
    }
};
