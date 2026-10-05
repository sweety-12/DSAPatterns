Number of provinces:
Given an undirected graph with V vertices. Two vertices u and v belong to a single province if there is a path from u to v or v to u. 
Find the number of provinces. The graph is given as an n x n matrix adj where adj[i][j] = 1 if the ith city and the jth city are directly connected, 
and adj[i][j] = 0 otherwise.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

Example 1:
Input: adj=[[1, 0, 0, 1], [0, 1, 1, 0], [0, 1, 1, 0], [1, 0, 0, 1]]


Approach: THIS IS A NORMAL TRAVERSAL PROBLEM AND CAN BE SOLVED USING DFS OR BFS BOTH. Below is solved with DFS.

TC: Exponential and SC : O(n) <- ASS

class Solution{
public:
    void dfs(int node, vector<int>&visited, vector<int>adj_list[]){

        visited[node] = 1;

        for(auto it : adj_list[node]){
            if(visited[it] == -1){
                dfs(it, visited, adj_list);
            }
        }

    }
    int numProvinces(vector<vector<int>> adj) {

        int r = adj.size();
        int c = adj[0].size();

        vector<int>adj_list[r];
        int provinces =0;

        //create an adjancency list
        for(int i=0; i<r; i++){
            for(int j =0; j<c; j++){

                if(adj[i][j] == 1 && i != j){

                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);
                }
                
            }
        }

        //declare one visited vector
        vector<int>visited(r, -1);

       for(int i=0; i<r; i++){
             if(visited[i] == -1){

                dfs(i, visited, adj_list);
                provinces++;
             }
       }
        
       return provinces;
    }
};

