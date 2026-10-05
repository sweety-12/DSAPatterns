# Graph

## What is a Graph?

A Graph is a collection of **nodes (vertices)** connected by **edges**.

Graphs model relationships, dependencies, networks, maps, grids, and connectivity problems.

Unlike arrays and trees, graphs may contain:

* Cycles
* Multiple paths
* Disconnected components
* Directed or undirected edges
* Weighted or unweighted edges

**Core idea:** Almost every graph problem reduces to one of a small set of patterns. Recognizing the pattern is more important than memorizing solutions.

```text
Time Complexity:
DFS/BFS          → O(V + E)
Topological Sort → O(V + E)
DSU              → O(α(N))
Dijkstra         → O(E log V)

Space Complexity:
Usually O(V + E)
```
## Hand Written Graph Patterns Chart.
---

![Hand Written Graph Patterns Chart](Graph%20Patterns.jpeg)

---

> **Progress: 27 problems solved across 7 graph patterns**

---

## The Core Graph Templates

### DFS Template

Use when:

* Exploring a component
* Reachability
* Islands
* Cycle detection (DFS variants)

```cpp
void dfs(int node, vector<vector<int>>&adj, vector<int>&visited){
    visited[node] =1;

    for(const auto &nei : adj[node]){
        if(!visited[nei]){
            dfs(nei, adj, visited);
        }
    }
}
int countComponents(int n, vector<vector<int>&edges){
    vector<vector<int>>adj(n);

    for(auto it : edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);

    }
    
    vector<int>visited(n, 0);
    int components =0;

    for(int i=0; i<n; i++){
        if(!visited){
            dfs(i, adj, visited);
            components++;
        }
    }

    return components
}

```

### BFS Template

Use when:

* Shortest path in unweighted graph
* Level traversal
* Multi-source BFS

```cpp
void bfs(int start,
         vector<vector<int>>& adj,
         vector<int>& visited){

    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(const auto adj_node : adj[node]){
            if(!visited[adj_node]){
                visited[adj_node] = 1;
                q.push(adj_node);
            }
        }
    }
}
```

---

## Pattern Recognition Cheat Code

| Signal                              | Pattern          |
| ----------------------------------- | ---------------- |
| Count islands / components          | Traversal        |
| Is there a path?                    | Traversal        |
| Minimum steps / distance            | Shortest Path    |
| Infection / spread / nearest source | Multi-source BFS |
| Course schedule / dependencies      | Topological Sort |
| Detect loop                         | Cycle Detection  |
| Edge additions over time            | DSU              |
| Matrix with directions              | Grid-as-Graph    |

---

## Patterns & Solved Problems

---

### Pattern 1 — Traversal (DFS / BFS)

#### When to use

* Connected components
* Is there a path?
* count islands/regions
* Reachability
* Flood fill
* Visit every node exactly once

### Tools:

* DFS/BFS
* Visited Array
* Recursion on Queue

#### Key Insight

Traversal is the foundation of graph problems.

If you cannot systematically visit nodes without revisiting them, everything else becomes difficult.

```cpp
for(int i=0;i<n;i++){
    if(!visited[i]){
        dfs(i, adj, visited);
        components++;
    }
}
```

| # | Problem                                   | Difficulty |
| - | ----------------------------------------- | ---------- |
| 1 | Number of Provinces                       | 🟢 Easy    |
| 2 | Number of Islands                         | 🟢 Easy    |
| 3 | Flood Fill                                | 🟢 Easy    |
| 4 | Connected Components in Matrix            | 🟡 Medium  |
| 5 | Rotten Oranges                            | 🟡 Medium  |
| 6 | Distance of Nearest Cell Having 1         | 🟡 Medium  |
| 7 | Surrounded Regions                        | 🟡 Medium  |
| 8 | Number of Enclaves                        | 🟡 Medium  |
| 9 | Bipartite Graph (DFS)                     | 🟡 Medium  |
| 10 | Cycle Detection in Undirected Graph (BFS) | 🔴 Hard    |
| 11 | Detect Cycle in Undirected Graph (DFS)    | 🔴 Hard    |
| 12 | Word Ladder I                             | 🔴 Hard    |
| 13 | Word Ladder II                            | 🔴 Hard    |

---

### Pattern 2 — Shortest Path (Minimize something under movement rules)

#### When to use

* Minimum steps/distance/cost
* Weighted vs unweighted
* Grid With Costs

#### Tools:

* BFS(unweighted)
* Dijkstra (Positive Weights)
* 0-1 BFS
* Bellman Ford (rare but sneaky)

#### Interview Trap: People use Dijkstra when BFS is Enough.

#### Key Insight

Choose algorithm based on edge weights:

```text
Unweighted Graph     → BFS
Positive Weights     → Dijkstra
0/1 Weights          → 0-1 BFS
Negative Weights     → Bellman Ford
```

#### BFS Shortest Path

```cpp
vector<int>shortestPath(int n , vector<vector<int>>&adj, int src){
         vector<int>dist(n, -1);
         queue<int>q;
         q.push(src);
         dist[src] = 0;
         
         while(!q.empty()){
             int node = q.front();
             q.pop();
         
             for(auto neigh : adj[node]){
                 if(dist[neigh] == -1){
                     dist[neigh] = dist[node] + 1;
                     q.push(neigh);
                 }
             }
     }
   return dist;
}
```

### Dijkstra (Positive Weights > 1)

```cpp
vector<int>dijkstra(int n , vector<vector<pair<int, int>>>&adj, int src){
         vector<int>dist(n, INT_MAX);
         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;

         dist[src] =0;
         pq.push({0, src});

         while(!pq.empty()){
         {
            auto[d, node] = pq.top();
            pq.pop();

            if(d > dist[node]) continue;

            for(const auto & [adj_node, wt] : adj[node])
            {
                     if(dist[node] + wt < dist[adj_node])
                           {
                               dist[adj_node] = dist[node] + wt;
                               pq.push({dist[adj_node], adj_node});
                           }
            }
  }
   return dist
}
```


| # | Problem                                        | Difficulty |
| - | ---------------------------------------------- | ---------- |
| 1 | Shortest Path in Undirected Graph (unit weights) | 🔴 Hard  |
| 2 | Shortest Path in DAG                           | 🔴 Hard    |
| 3 | Dijkstra's Algorithm                           | 🔴 Hard    |
| 4 | Shortest Distance in Binary Maze               | 🔴 Hard    |
| 5 | Path with Minimum Effort                       | 🔴 Hard    |
| 6 | Cheapest Flights Within K Stops                | 🔴 Hard    |
| 7 | Network Delay Time                             | 🟡 Medium  |

---

### Pattern 3 — Cycle Detection

#### When to use

* Deadlock detection
* Prerequite Loop
* Infinite Process

#### Tools:

* Visited + Recursion Stack(directed)
* Parent Tracking(Undirected)
* Topological Sort Failure

#### Key Insight

Undirected Graph: Cycle Detection -> DFS + Recursive Stack

```cpp
bool dfsCycle(int node, vector<vector<int>>&adj, vector<int>&visited, vector<int>&pathVis){

    visited[node] =1;
    pathVis[node] =1;

    for(auto &adj_node : adj[node]){
        if(!visited[adj_node]){
            if(dfsCycle(adj_node, adj, visited, pathVis)){
                return true;
            }
            else if(pathVis[adj_node]){
                return true;
            }
        }
    }

    pathVis[node] = 0;
    return false;
}
```

Undirected Graph: DFS with Parent

```cpp
bool dfs(int node, int parent, vector<vector<int>>&adj, vector<int>&visited){
    visited[node] = 1;
    for(auto &adj_node : adj[node]){
        if(!visited[adj_node]){
            if(dfs(adj_node, node, adj, visited)){
                return true;
            }
        }
        else if(adj_node != parent){
            return true;
        }
    }
    return false;
}
```

Directed - Kahn's (Cycle is detected if Topo is Incomplete)



| # | Problem                          | Difficulty |
| - | -------------------------------- | ---------- |
| 1 | Detect Cycle in Undirected Graph (BFS) | 🔴 Hard |
| 2 | Detect Cycle in Undirected Graph (DFS) | 🔴 Hard |
| 3 | Detect Cycle in Directed Graph (DFS)   | 🔴 Hard |

---

### Pattern 4 — Topological Sort (Order Tasks with dependencies)

#### When to use

* Course schedule
* Build order
* Prerequisites

#### Tools:

* Kahn's Algorithm(BFS)
* DFS finishing time

#### Key Insight
* if topo sort exists -> No cycle exists use DAG
* if not -> Cycle exists

```text
Topo Sort Exists
        ⇓
No Cycle
```

#### Kahn's Algorithm (BFS)

```cpp

vector<int>topo (int n, vector<vector<int>>&adj){
    vector<int> indegree(n, 0);

    for(int i =0; i < n; i++){
        indegree[adj_node]++;
    }

    queue<int>q;
    for(int i=0; i<n; i++){
        if(indegree[i] == 0) q.push(i);
    }

    vector<int>order 
    while(!q.empty()){
        int node = q.front();
        q.pop();

        order.push_back(node);

        for(auto &adj_node : adj[node]){
            indegree[adj_node]--;
            if(indegree[adj_node] == 0){
                q.push(adj_node);
            }
        }

        if(order.size() != n) return {};
    }
    return order;
}
```

DFS Fusing Time

```cpp

void dfs(int node, vector<vector<int>>&adj, vector<int>&visited, stack<int>&st){
    visited[node] = 1;
    for(auto &adj_node : adj[node]){
        if(!visited[adj_node]){
            dfs(adj_node, adj, visited, st);
        }
    }
    st.push(node);
}
```

| # | Problem                          | Difficulty |
| - | -------------------------------- | ---------- |
| 1 | Topo Sort (DFS)                  | 🔴 Hard    |
| 2 | Topological Sort / Kahn's Algorithm | 🔴 Hard |
| 3 | Course Schedule I                | 🔴 Hard    |
| 4 | Course Schedule II               | 🟡 Medium  |
| 5 | Alien Dictionary                 | 🔴 Hard    |

---

### Pattern 5 — Multi-Source BFS  (Distance from multiple starting Points)

#### When to use

* Nearest source(x)
* Time for Spread
* Rotting/Infection/Fire

#### Tools:

* Push ALL sources initially.
* Level Order BFS

```cpp

int multiSourceBFS(vector<vector<int>>&grid){

    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int,int>>q;   
    vector<vector<int>>dist(n, vector<int>(m, -1));

    //push all sources
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 1){
                q.push({i,j});
                dist[i][j] = 0;
            }
        }
    }

    int dRow[] = {-1, 0, +1, 0};
    int dCol[] = {0, +1, 0, -1};

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];

            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && dist[nRow][nCol] == -1){
                dist[nRow][nCol] = dist[row][col] + 1;
                q.push({nRow, nCol});
            }
        }
    }

}
```

| # | Problem                           | Difficulty |
| - | --------------------------------- | ---------- |
| 1 | Rotten Oranges                    | 🟡 Medium  |
| 2 | 01 Matrix                         | 🟡 Medium  |
| 3 | Distance of Nearest Cell Having 1 | 🟡 Medium  |
| 4 | Word Ladder I                     | 🔴 Hard    |

---

### Pattern 6 — Union Find (DSU)  - (Dynamic connectivity)

#### When to use

* Number of components after operations 
* Edge additions
* Redundant connections

#### Tools:

* Parent, rank/size
* Path Compression

#### Key Insight

If graph connectivity changes over time:

```text
Think DSU First
```

#### DSU Template

```cpp
class DSU{
    public:
        vector<int>parent, size;

        DSU(int n){
            parent.resize(n);
            size.resize(n, 1);
            for(int i=0; i<n; i++){
                parent[i] = i;
            }
        }

        int find(int node){
            if(node == parent[node]) return node;
            return parent[node] = find(parent[node]);
        }

        void unionBySize(int u, int v){
            int ulp_u = find(u);
            int ulp_v = find(v);

            if(ulp_u == ulp_v) return;

            if(size[ulp_u] < size[ulp_v]){

                swap(ulp_u, ulp_v);

                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
}
```

| # | Problem                                    | Difficulty |
| - | ------------------------------------------ | ---------- |
| 1 | Disjoint Set (Union Find)                  | 🔴 Hard    |
| 2 | Number of Provinces (DSU)                  | 🟡 Medium  |
| 3 | Make Network Connected                     | 🟡 Medium  |
| 4 | Accounts Merge                             | 🔴 Hard    |
| 5 | Number of Islands II                       | 🔴 Hard    |

---

### Pattern 7 — Grid as Graph

#### When to use

* Matrix traversal/2D Grid
* Islands/Obstacles
* Move in directions
* Shortest path in grid
* Flood fill

#### Tools:

* BFS/DFS
* Direction arrays
* Boundary checks

#### Key Insight

A matrix pretending to be a graph.
Convert movement into directions.

```cpp

void dfs(int row, int col, vector<vector<int>>&grid, vector<vector<int>>&visited){

    int n = grid.size();
    int m = grid[0].size();

    visited[row][col] = 1;

    int drow[] = {-1, 0, +1, 0};
    int dcol[] = {0, +1, 0, -1};

    for(int i=0; i<4; i++){
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !visited[nrow][ncol]){
            dfs(nrow, ncol, grid, visited);
        }
    }
}
```

| # | Problem                           | Difficulty |
| - | --------------------------------- | ---------- |
| 1 | Number of Islands                 | 🟢 Easy    |
| 2 | Flood Fill                        | 🟢 Easy    |
| 3 | Surrounded Regions                | 🟡 Medium  |
| 4 | Number of Enclaves                | 🟡 Medium  |
| 5 | Shortest Distance in Binary Maze  | 🔴 Hard    |
| 6 | Path with Minimum Effort          | 🔴 Hard    |

---

## Quick Decision Guide

```text
Need to visit everything?
│
├── Count components?
│   └── Traversal (DFS/BFS)
│
├── Minimum distance?
│   │
│   ├── Unweighted?
│   │   └── BFS
│   │
│   ├── Positive weights?
│   │   └── Dijkstra
│   │
│   └── 0/1 weights?
│       └── 0-1 BFS
│
├── Detect loop?
│   │
│   ├── Directed?
│   │   └── DFS + recursion stack
│   │
│   └── Undirected?
│       └── Parent tracking
│
├── Dependencies?
│   └── Topological Sort
│
├── Multiple starting nodes?
│   └── Multi-source BFS
│
├── Edge additions?
│   └── DSU
│
└── Matrix problem?
    └── Grid-as-Graph
```

---

## Pattern Summary

| Pattern             | Key Technique                    | Solved |
| ------------------- | -------------------------------- | ------ |
| 1. Traversal        | DFS / BFS                        | 13     |
| 2. Shortest Path    | BFS / Dijkstra                   | 7      |
| 3. Cycle Detection  | Parent / Recursion Stack         | 3      |
| 4. Topological Sort | Kahn's Algorithm                 | 5      |
| 5. Multi-source BFS | Push all sources                 | 4      |
| 6. DSU              | Path Compression + Union by Size | 5      |
| 7. Grid as Graph    | Direction Arrays                 | 6      |

| Total Patterns      | 7                       |
| ------------------- | ----------------------- |
| Total Solved        | 27                      |
| Interview Readiness | Strong SDE-1 Foundation |



---

## Striver A-Z Graph Series — Full Tracker

> 27 / 43 solved &nbsp;|&nbsp; 16 remaining

### Traversal (DFS / BFS) — 13 / 13 ✅

| # | Problem | Difficulty | Status |
| - | ------- | ---------- | ------ |
| 1 | Number of Provinces | 🟡 Medium | ✅ Done |
| 2 | Connected Components in Matrix | 🟡 Medium | ✅ Done |
| 3 | Rotten Oranges | 🟡 Medium | ✅ Done |
| 4 | Flood Fill | 🟡 Medium | ✅ Done |
| 5 | Distance of Nearest Cell Having 1 | 🟡 Medium | ✅ Done |
| 6 | Surrounded Regions | 🟡 Medium | ✅ Done |
| 7 | Number of Enclaves | 🟡 Medium | ✅ Done |
| 8 | Number of Islands | 🟡 Medium | ✅ Done |
| 9 | Bipartite Graph (DFS) | 🔴 Hard | ✅ Done |
| 10 | Cycle Detection in Undirected Graph (BFS) | 🔴 Hard | ✅ Done |
| 11 | Detect Cycle in Undirected Graph (DFS) | 🔴 Hard | ✅ Done |
| 12 | Word Ladder I | 🔴 Hard | ✅ Done |
| 13 | Word Ladder II | 🔴 Hard | ✅ Done |

---

### Topo Sort and Problems — 6 / 7

| # | Problem | Difficulty | Status |
| - | ------- | ---------- | ------ |
| 1 | Topo Sort (DFS) | 🔴 Hard | ✅ Done |
| 2 | Topological Sort / Kahn's Algorithm | 🔴 Hard | ✅ Done |
| 3 | Detect Cycle in Directed Graph (DFS) | 🔴 Hard | ✅ Done |
| 4 | Course Schedule I | 🔴 Hard | ✅ Done |
| 5 | Course Schedule II | 🟡 Medium | ✅ Done |
| 6 | Alien Dictionary | 🔴 Hard | ✅ Done |
| 7 | Find Eventual Safe States | 🔴 Hard | ⏳ Pending |

---

### Shortest Path Algorithms — 7 / 13

| # | Problem | Difficulty | Status |
| - | ------- | ---------- | ------ |
| 1 | Shortest Path in Undirected Graph (unit weights) | 🔴 Hard | ✅ Done |
| 2 | Shortest Path in DAG | 🔴 Hard | ✅ Done |
| 3 | Dijkstra's Algorithm | 🔴 Hard | ✅ Done |
| 4 | Shortest Distance in Binary Maze | 🔴 Hard | ✅ Done |
| 5 | Path with Minimum Effort | 🔴 Hard | ✅ Done |
| 6 | Cheapest Flights Within K Stops | 🔴 Hard | ✅ Done |
| 7 | Network Delay Time | 🟡 Medium | ✅ Done |
| 8 | Why Priority Queue in Dijkstra | 🔴 Hard | ⏳ Pending |
| 9 | Number of Ways to Arrive at Destination | 🔴 Hard | ⏳ Pending |
| 10 | Minimum Multiplications to Reach End | 🔴 Hard | ⏳ Pending |
| 11 | Bellman Ford Algorithm | 🔴 Hard | ⏳ Pending |
| 12 | Floyd Warshall Algorithm | 🔴 Hard | ⏳ Pending |
| 13 | Find City with Smallest Number of Neighbors | 🔴 Hard | ⏳ Pending |

---

### MST / Disjoint Set — 4 / 10

| # | Problem | Difficulty | Status |
| - | ------- | ---------- | ------ |
| 1 | Disjoint Set (Union Find) | 🔴 Hard | ✅ Done |
| 2 | Number of Operations to Make Network Connected | 🔴 Hard | ✅ Done |
| 3 | Accounts Merge | 🔴 Hard | ✅ Done |
| 4 | Number of Islands II | 🔴 Hard | ✅ Done |
| 5 | MST Theory | 🟢 Easy | ⏳ Pending |
| 6 | Prim's Algorithm | 🔴 Hard | ⏳ Pending |
| 7 | Find MST Weight (Kruskal's) | 🔴 Hard | ⏳ Pending |
| 8 | Most Stones Removed with Same Row/Column | 🟡 Medium | ⏳ Pending |
| 9 | Making a Large Island | 🔴 Hard | ⏳ Pending |
| 10 | Swim in Rising Water | 🟡 Medium | ⏳ Pending |

---

### Other Algorithms — 0 / 3

| # | Problem | Difficulty | Status |
| - | ------- | ---------- | ------ |
| 1 | Bridges in Graph | 🔴 Hard | ⏳ Pending |
| 2 | Articulation Point in Graph | 🔴 Hard | ⏳ Pending |
| 3 | Kosaraju's Algorithm (SCC) | 🔴 Hard | ⏳ Pending |
