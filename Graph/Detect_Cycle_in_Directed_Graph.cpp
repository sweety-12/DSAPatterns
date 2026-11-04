Directed Graph Cycle
Given a directed graph with V vertices, numbered from 0 to V - 1, represented by an adjacency list adj[][], where adj[u] contains all vertices reachable from vertex u through a directed edge, check whether the graph contains a cycle.

Note: The graph may have multiple connected components. Self-loops are allowed, but repeated edges are not allowed.

Examples:

Input: adj = [[1], [2], [0, 3], []]
Output: true
Explanation: The diagram clearly shows a cycle 0 -> 1 -> 2 -> 0

APPROACH : Kahn's Algo
TC: 
Calculate indegree	 O(V+E)      //I got confused here with O(V*E) but if we notice we are not traversing every edges for all node, one node is connected with certain edge and next node with other 
Push all zero-indegree vertices into queue	O(V)
Process queue and traverse adjacency lists	O(V+E)
Total TC: O(V+E)

SC:
Indegree vector	O(V)
Answer vector	O(V)
Queue	O(V)
Total SC:  O(V) auxiliary space (excluding the input graph).


// Using Kahn's Algorithm
// 1. Calculate the indegree of every vertex.
// 2. Push all vertices with indegree 0 into a queue.
// 3. Process the queue:
//   - Pop a vertex.
//   - Increment a counter of processed vertices.
//   - Reduce the indegree of its neighboring vertices.
//   - If a neighbor's indegree becomes 0, push it into the queue.
// 4. At the end, compare the processed count with the total number of vertices.

class Solution {
  public:
    bool isCyclic(vector<vector<int>>& adj){
        // code here
        int n = adj.size();
        vector<int>indegree(n, 0);
        
//  Current vertex	Neighbor (it)	Updated indegree
// 	0	              1	            indegree[1] = 1
// 	0                 2         	indegree[2] = 1
// 	1                 3         	indegree[3] = 1
// 	2	              1         	indegree[1] = 2

//this basically calculates with the help of adj list, 
//adj list stores outdegree , so its neighbouring must have indegree,
//hence indegree[neighbours]++;
        
        for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }
        
        queue<int>q;
        
        vector<int>ans;
        
        for(int i=0; i<n ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(auto it : adj[node]){
                
                indegree[it]--;
                
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        
        if(ans.size() != n) return true;  //this represents all other nodes are depended on each other and atleast one node indegree cannot become 0. hence there must be some nodes whose indegree never 0, if it was an acyclic graph all nodes must have been traversed.
        
        // This means at least one vertex could not be processed by Kahn's Algorithm.
        // Why does that happen?
        // - In a DAG, there is always at least one vertex with indegree 0.
        // - Removing that vertex and its outgoing edges eventually allows every vertex to be processed.
        // - In a graph with a directed cycle, the vertices in the cycle cannot become indegree 0 because they depend on one another.
        // - Consequently, fewer than n vertices are processed.
        
        return false;
    }
};
