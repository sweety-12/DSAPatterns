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
void dfs(int node,
         vector<vector<int>>& adj,
         vector<int>& visited){

    visited[node] = 1;

    for(auto neigh : adj[node]){
        if(!visited[neigh]){
            dfs(neigh, adj, visited);
        }
    }
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

        for(auto neigh : adj[node]){
            if(!visited[neigh]){
                visited[neigh] = 1;
                q.push(neigh);
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
* Number of islands
* Reachability
* Flood fill
* Visit every node exactly once

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

### Pattern 2 — Shortest Path

#### When to use

* Minimum steps
* Minimum distance
* Minimum cost

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
* Dependency validation
* Graph validity

#### Key Insight

Undirected Graph:

```text
Visited neighbour
AND
Neighbour != Parent

⇒ Cycle
```

Directed Graph:

```text
Visited neighbour
AND
Still in recursion stack

⇒ Cycle
```

| # | Problem                          | Difficulty |
| - | -------------------------------- | ---------- |
| 1 | Detect Cycle in Undirected Graph (BFS) | 🔴 Hard |
| 2 | Detect Cycle in Undirected Graph (DFS) | 🔴 Hard |
| 3 | Detect Cycle in Directed Graph (DFS)   | 🔴 Hard |

---

### Pattern 4 — Topological Sort

#### When to use

* Course schedule
* Build systems
* Dependency ordering

#### Key Insight

Topological ordering exists only for DAGs.

```text
Topo Sort Exists
        ⇓
No Cycle
```

#### Kahn's Algorithm

```cpp
for(auto neigh : adj[node]){
    indegree[neigh]--;

    if(indegree[neigh] == 0){
        q.push(neigh);
    }
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

### Pattern 5 — Multi-Source BFS

#### When to use

Signals:

* Nearest source
* Spread
* Infection
* Fire
* Rotting

#### Key Insight

Push ALL sources initially.

```cpp
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(source){
            q.push({i,j});
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

### Pattern 6 — Union Find (DSU)

#### When to use

* Dynamic connectivity
* Edge additions
* Redundant connections
* Component counting

#### Key Insight

If graph connectivity changes over time:

```text
Think DSU First
```

#### DSU Template

```cpp
int find(int node){
    if(parent[node] == node)
        return node;

    return parent[node] = find(parent[node]);
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

* Matrix traversal
* Islands
* Shortest path in grid
* Flood fill

#### Key Insight

A matrix is often just a graph in disguise.

Convert movement into directions.

```cpp
int drow[4] = {-1,0,1,0};
int dcol[4] = {0,1,0,-1};
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
