2685. Count the Number of Complete Components

You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.

Return the number of complete connected components of the graph.

A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

A connected component is said to be complete if there exists an edge between every pair of its vertices.
Example 1:
Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
Output: 3
Explanation: From the picture above, one can see that all of the components of this graph are complete.

APPROACH: USING DFS
TC: O(V+E) and SC: (V+E)

class Solution {
public:
    void dfs(int node, vector<int>&vis,  vector<vector<int>>&adj, int &vertices, int &degree){
        vis[node] =1;
        vertices++;

        degree += adj[node].size();
        
         for(auto it: adj[node]){

            if(vis[it] == 0){
                dfs(it,vis, adj, vertices, degree);
            }
         }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        //Declaring adjacency list
        // vector<int>adj[n];
        vector<vector<int>>adj(n);

        //initializing adjacency list  //this is completely wrong this we don;t when we have to construct adj list from matrix, right now undirected graph -> adj list
        // for(int u =0; u<edges.size(); u++){
        //     for(int v =0; v<edges[0].size(); v++){

        //         adj[u].push_back(v);
        //         adj[v].push_back(u);
        //     }
        // }


        //initializing adj list
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        //declare a vis array
        vector<int>vis(n, 0);

        //storing the final ans
        // vector<vector<int>>ans;
        int countComponents =0;

        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                int vertices =0;
                int degree =0;

                dfs(i, vis, adj, vertices, degree);

                int actualedges = degree/2;  //this is verifying how many degrees each vertex have, if complete then each vertex should have 2 degree

                int expectededges = vertices*(vertices - 1)/2;  //this is the formula to check completeness

                if(actualedges == expectededges){
                    countComponents++;

                }
         }
     } 
        return countComponents;
    }
};
