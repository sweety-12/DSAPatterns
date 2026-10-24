785. Is Graph Bipartite?
There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.
Example 1:
Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.
Example 2:
Input: graph = [[1,3],[0,2],[1,3],[0,2]]
Output: true
Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.

APPROACH: BFS
TC: O(V+E) and SC: O(V+E)

class Solution {
public:
    bool bfs(int node, vector<vector<int>>&graph, vector<int>&color){
       
        int clr = 0;

        queue<int>q;
        q.push(node);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : graph[node]){

                //if the adjacent node is not colored, color it with opposite color
                if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);
                }

                //means the adjacent node is already colored
                else{

                        if(color[it] == color[node]){
                            return false;
                        }
                }
            }
        }
        return true; 
    }
    bool isBipartite(vector<vector<int>>& graph) {

      int n = graph.size();

      vector<int>color(n, -1);

      for(int i=0; i<n; i++){
        if(color[i] == -1){
            bool ans = bfs(i, graph, color);
            if(ans == false)  return false;
        }
      }

      return true;
    }
};

