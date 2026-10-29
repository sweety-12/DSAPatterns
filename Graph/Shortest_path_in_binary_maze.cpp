GFG: Shortest Distance in Binary Maze
Given a binary matrix mat[][] containing values 0 and 1, and a source cell src[] and destination cell dest[], find the minimum number of steps required to reach the destination cell from the source cell. From any cell, you can move to its adjacent cells in the up, down, left, and right directions.

1 represents a traversable cell.
0 represents a blocked cell that cannot be visited.
If the destination cannot be reached from the source, return -1.

Examples:

Input: mat[][] = [[1, 1, 1, 1], [1, 1, 0, 1], [1, 1, 1, 1], [1, 1, 0, 0], [1, 0, 0, 1]], src[] = [0, 1], dest[] = [2, 2]
Output: 3
Explanation: From (0,1), the minimum number of steps to reach (2,2) is 3.
  
Input: mat[][] = [[1, 1, 1, 1, 1], [1, 1, 1, 1, 1], [1, 1, 1, 1, 0], [1, 0, 1, 0, 1]], src[] = [0, 0], dest[] = [3, 4]
Output: -1
Explanation: From (0,0), the destination (3,4) cannot be reached because all possible paths are blocked by 0 cells, so no valid route exists.
 
Constraints:

1 ≤ mat.size(), mat[i].size() ≤ 500
0 ≤ mat[i][j] ≤ 1
The source and destination cells are always inside the given matrix.

APPROACH: BFS
TC: O(r*c) and SC : O(r*c)

// //STEPS:
// 1. Declare and dist vector of vector and initialize witj -1;
// 2. Shortest Path -> BFS
// 3. Declare Queue and push the src;
// 4. Start traversing and assign the neighbours with + 1.
// 5. Push the neighbours into queue
// 6. Return dist[dest[0], dest[1]];

class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat, vector<int> &src, vector<int> &dest) {
        // code here
        int r = mat.size();
        int c = mat[0].size();
        
        
        //temp sol
        int src_row = src[0];
        int src_col = src[1];
        
        
        int dest_row = dest[0];
        int dest_col = dest[1];
        
        //edge case 
        //if the src cell is blocked we cannot start the traversal
        if(mat[src_row][src_col] == 0)  return -1;
        
        //if the dest cell is blocked we cannot reach
        
        if(mat[dest_row][dest_col] == 0)  return -1;
        
        
        
        vector<vector<int>>dist(r, vector<int>(c, -1));
        
        
        queue<pair<int, int>>q;
        
        q.push({src[0], src[1]});
        dist[src_row][src_col] = 0;
        
        //to traverse the 4 direction
        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        while(!q.empty()){
            
            auto [i, j] = q.front();
            q.pop();
            
            for(int d =0; d<4; d++){
                
                int nrow = i + drow[d];
                int ncol = j + dcol[d];
                
                //need to check out of boundary
                if(nrow >= 0 && nrow < r && ncol >= 0 && ncol <c 
                && mat[nrow][ncol] == 1 && dist[nrow][ncol] == -1){
                    
                    dist[nrow][ncol] = dist[i][j] + 1;
                    q.push({nrow, ncol});
                }
            }
        }
        
        return dist[dest_row][dest_col];
    }
};

