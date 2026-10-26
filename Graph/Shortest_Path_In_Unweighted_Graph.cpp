GFG: Shortest Path in Unweighted Graph
Given an undirected graph with V vertices numbered from 0 to V-1 and E edges, where edges[i] = [u, v] denotes an undirected edge between vertex u and vertex v, given two vertices src and dest, find the length of the shortest path from src to dest. If there is no path between src and dest, return -1.

Note: All edges have a unit weight of 1.

Examples :

Input: V = 9, edges[][] = [[0, 1], [0, 3], [1, 2], [3, 4], [4, 5], [2, 6], [5, 6], [6, 7], [6, 8], [7, 8]], src = 0, dest = 8
Output: 4
Explanation: One of the shortest paths from vertex 0 to vertex 8 is 0 -> 1 -> 2 -> 6 -> 8, which contains 4 edges.

Input: V = 4, edges[][]= [[0, 3], [1, 3]], src = 3, dest = 2
Output: -1
Explanation: There is no path between vertices 3 and 2.

APPROACH: BFS
TC: O(V+E) and SC: O(V+E)

Time Complexity: \(O(V+E)\)
Building the adjacency list takes \(O(V+E)\) time. BFS visits each vertex at most once and examines each edge at most twice, so traversal also takes \(O(V+E)\) time. Therefore, the overall time complexity is \(O(V+E)\).

Space Complexity: \(O(V)\) auxiliary space, excluding the adjacency list.
The distance array and BFS queue each require at most \(O(V)\) space. The adjacency list requires an additional \(O(V+E)\) space, so the total extra space used by this implementation is \(O(V+E)\).

class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // code here
        
        //must take care if the path does not exist
        vector<int>dist(V, -1);
        dist[src] =0;
        
        //declaring the adj list
        vector<vector<int>>adj(V);
        
        //initializing
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<int>q;
        q.push(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it : adj[node]){
                
                if(dist[it] == -1){
                    dist[it] = dist[node]+1;
                    q.push(it);
                }
            }
        }
        
        return dist[dest];
    }
};




