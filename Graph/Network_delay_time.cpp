743. Network Delay Time
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

Example 1:

Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
 

Constraints:
1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)

APPROACH: DIJIKSTRA
TC: \(O((V+E)\log V)\) — commonly simplified to \(O(E\log V)\) for a connected sparse graph.
SC: \(O(V+E)\) — adjacency list \(O(V+E)\), distance array \(O(V)\), priority queue up to \(O(E)\) with lazy deletion.

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        //adj list

        vector<vector<pair<int, int>>>adj(n+1);
        for(auto it : times){
            
            adj[it[0]].push_back({it[1], it[2]});
        }

        //time vector
        vector<int>min_time(n+1, 1e9);  //if anyone is 1e9 return -1
        min_time[k] =0;

        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while(!pq.empty()){

            int t = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            if(t > min_time[node]) continue;

            for(auto it : adj[node]){

                int adj_node = it.first;
                int adj_time = it.second;

                if(min_time[node]+ adj_time < min_time[adj_node]){

                    min_time[adj_node] = min_time[node]+ adj_time;
                    pq.push({min_time[adj_node], adj_node});
                }

            }
        }

        int ans =0;
        for(int i=1; i<=n; i++){
            if(min_time[i] == 1e9)  return -1;

            ans = max(ans, min_time[i]);
        }

        return ans;
    }
};
