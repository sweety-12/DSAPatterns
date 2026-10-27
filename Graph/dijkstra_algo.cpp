GFG: Dijkstra Algorithm
Given a connected, weighted, undirected graph with V vertices and no negative edge weights, represented by an adjacency list adj[][][], and a source vertex src, calculate the shortest distance from src to every vertex in the graph.

Each adj[u] contains pairs [v, wt], where v is an adjacent vertex and wt is the weight of the edge connecting vertices u and v.

Return an array of integers where the ith element represents the shortest distance from the source vertex src to vertex i.

Note: It is guaranteed that all the shortest distance will fit in a 32-bit integer.

Examples:

Input: adj[][][] = [[[1, 1], [2, 6]], [[0, 1], [2, 3]], [[0, 6], [1, 3]]], src = 2
Output: [4, 3, 0]
Explanation:

Shortest Paths:
For 2 to 0 minimum distance will be 4. By following path 2 -> 1 -> 0
For 2 to 1 minimum distance will be 3. By following path 2 -> 1
For 2 to 2 minimum distance will be 0. By following path 2 -> 2
Input: adj[][][] = [[[1, 4], [2, 8]], [[0, 4], [4, 6]], [[0, 8], [3, 2]], [[2, 2], [4, 10]], [[1, 6], [3, 10]]], src = 0
Output: [0, 4, 8, 10, 10]
Explanation: 

Shortest Paths: 
For 0 to 1 minimum distance will be 4. By following path 0 -> 1
For 0 to 2 minimum distance will be 8. By following path 0 -> 2
For 0 to 3 minimum distance will be 10. By following path 0 -> 2 -> 3 
For 0 to 4 minimum distance will be 10. By following path 0 -> 1 -> 4

TC: o(V+E) and SC: O(V)

//need to go through the TC and SC of this question before interview
  
//TC:
// Operation	Total time
// Heap pushes	\(O(E\log V)\)
// Heap pops	\(O(E\log V)\)
// Neighbor traversal and relaxation checks	\(O(V+E)\)
// Overall	\(O((V+E)\log V)\)
// For a connected graph, this is often simplified to \(O(E\log V)\).
  
// 3. Space complexity, step by step
// Your statement "dist stores \(V\) nodes, so SC is \(O(V)\)" correctly accounts for only the distance array. We must also account for the other data structures.
// Data structure	Space
// dist array	\(O(V)\)
// Adjacency list	\(O(V+E)\)
// Priority queue	\(O(E)\) worst case for lazy Dijkstra
// Total space	\(O(V+E)\)


class Solution {
  public:
    vector<int> dijkstra(vector<vector<vector<int>>> &adj, int src) {
        // Code here
        
        int n = adj.size();
        vector<int>dist(n, INT_MAX);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
        
        dist[src] =0;
        pq.push({0, src});
        
        
        while(!pq.empty()){
            
            auto [d, node] = pq.top();
            pq.pop();
            
            if(d > dist[node]) continue;
            
            for(auto &it : adj[node]){
                
                int adj_node = it[0];
                int adj_wt = it[1];
                
                if(dist[node] + adj_wt  < dist[adj_node]){
                    dist[adj_node] = dist[node] + adj_wt;
                    
                    pq.push({dist[adj_node], adj_node});
                }
            }
        }
        
        return dist;
    }
};
