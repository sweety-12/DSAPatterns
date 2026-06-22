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

> **Progress: XX problems solved across 7 graph patterns**

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

| # | Problem              | Difficulty |
| - | -------------------- | ---------- |
| 1 | Number of Provinces  | 🟢 Easy    |
| 2 | Number of Islands    | 🟢 Easy    |
| 3 | Flood Fill           | 🟢 Easy    |
| 4 | Connected Components | 🟡 Medium  |

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

| # | Problem                        | Difficulty |
| - | ------------------------------ | ---------- |
| 1 | Shortest Path in Binary Matrix | 🟡 Medium  |
| 2 | Network Delay Time             | 🟡 Medium  |
| 3 | Path With Minimum Effort       | 🔴 Hard    |

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
| 1 | Detect Cycle in Undirected Graph | 🟢 Easy    |
| 2 | Detect Cycle in Directed Graph   | 🟡 Medium  |
| 3 | Graph Valid Tree                 | 🟡 Medium  |

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

| # | Problem            | Difficulty |
| - | ------------------ | ---------- |
| 1 | Course Schedule    | 🟡 Medium  |
| 2 | Course Schedule II | 🟡 Medium  |
| 3 | Alien Dictionary   | 🔴 Hard    |

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

| # | Problem         | Difficulty |
| - | --------------- | ---------- |
| 1 | Rotting Oranges | 🟡 Medium  |
| 2 | 01 Matrix       | 🟡 Medium  |
| 3 | Walls and Gates | 🟡 Medium  |

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

| # | Problem                   | Difficulty |
| - | ------------------------- | ---------- |
| 1 | Number of Provinces (DSU) | 🟡 Medium  |
| 2 | Redundant Connection      | 🟡 Medium  |
| 3 | Make Network Connected    | 🟡 Medium  |
| 4 | Accounts Merge            | 🔴 Hard    |

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

| # | Problem                        | Difficulty |
| - | ------------------------------ | ---------- |
| 1 | Number of Islands              | 🟢 Easy    |
| 2 | Flood Fill                     | 🟢 Easy    |
| 3 | Surrounded Regions             | 🟡 Medium  |
| 4 | Shortest Path in Binary Matrix | 🟡 Medium  |

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

| Pattern             | Key Technique                    |
| ------------------- | -------------------------------- |
| 1. Traversal        | DFS / BFS                        |
| 2. Shortest Path    | BFS / Dijkstra                   |
| 3. Cycle Detection  | Parent / Recursion Stack         |
| 4. Topological Sort | Kahn's Algorithm                 |
| 5. Multi-source BFS | Push all sources                 |
| 6. DSU              | Path Compression + Union by Size |
| 7. Grid as Graph    | Direction Arrays                 |

| Total Patterns      | 7                       |
| ------------------- | ----------------------- |
| Interview Readiness | Strong SDE-1 Foundation |
