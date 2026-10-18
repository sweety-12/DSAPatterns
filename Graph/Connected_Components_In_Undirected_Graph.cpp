GFG : Connected Components in an Undirected Graph
Given an undirected graph with V vertices numbered from 0 to V-1 and E edges, represented as a 2D array edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v.

Your task is to return a list of all connected components. Each connected component should be represented as a list of its vertices, with all components returned in a collection where each component is listed separately.

Note: You can return the components in any order, driver code will print the components in sorted order.

Examples :

Input: V = 5, edges[][] = [[0, 1], [2, 1], [3, 4]]
Output: [[0, 1, 2], [3, 4]]
Explanation:

APPROACH : USING DFS
TC: O( V+ E) AND SC: O(V+E)

class Solution {
  public:
    void dfs(int node, vector<int>&vis, vector<int>&temp, vector<vector<int>>&adj){
        
        vis[node] =1;
        
        for(auto it : adj[node]){
            if(vis[it] == 0){
                dfs(it, vis, temp, adj);
                 temp.push_back(it);
            }
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        
        //declaring the adjacency list
        vector<vector<int>>adj(V);
        
        //initializing the adj list
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        //declare the vis vector
        vector<int>vis(V);
        
        //declare the ans vec;
        vector<vector<int>>ans;
        
        //call the dfs function
        for(int i=0; i<V;i++){
            
            vector<int>temp;
            if(vis[i] == 0){
                temp.push_back(i);
                dfs(i, vis, temp, adj);
                ans.push_back(temp);
            }
        }
        
        return ans;
        
    }
};

