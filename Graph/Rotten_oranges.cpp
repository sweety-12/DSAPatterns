994. Rotting Oranges
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Example 1:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.


APPROACH : Multi-Source BFS
TC: O(r*c) and SC: O(r*c)

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int r = grid.size();
        int c = grid[0].size();

        //declare queue
        queue<pair<int, int>>q;
        int fresh =0;
        
        //traverse in the grid and count all the fresh organges and store all the rotten oranges in queue
        for(int i=0;i<r; i++){
            for(int j=0; j<c; j++){

                if(grid[i][j] == 1) fresh++;

                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        //for traversing all 4 directions;
        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};

        int minutes =0;

        while(!q.empty() && fresh > 0){
            int size = q.size();

            //this line is very immportant which i forgot, this make sure that the already rotten oranges stored in the queue should get execute first, coz, if this is not here we are simulataneously adding the newly rotten oranges. newly rotten oranges will also get counted in the first minute to rot next instead it should be counted in the next minute.   
            for(int k =0; k<size; k++){

            //pop one element out
            auto [i, j] = q.front();
            q.pop();

            for(int d =0; d<4; d++){
                int nrow = i + drow[d];
                int ncol = j + dcol[d];
            

            if(nrow >= 0 && nrow < r && ncol >=0 && ncol < c && grid[nrow][ncol] == 1){
                grid[nrow][ncol] = 2;
                fresh--;
                q.push({nrow, ncol});
            }
          }
        }
        
          minutes++; 
     }
    
     if(fresh != 0)  return -1;

     return minutes;
        
    }
};

--EXPLAINATION FOR SPACE AND TIME COMPLEXITY
Space Complexity — \(O(r \times c)\)

Your reasoning is correct.
- The queue can hold at most \(r \times c\) coordinates in the worst case.
- This happens when many or all cells contain oranges and are added to the queue.
- Since each cell is added to the queue at most once, the queue uses \(O(r \times c)\) space.
  
Time Complexity — \(O(r \times c)\)

There are two parts:
1. Initial grid traversal: \(O(r \times c)\)
You visit every cell once to count fresh oranges and enqueue initially rotten oranges.
2. BFS traversal: \(O(r \times c)\)
This is the part to understand carefully.
- Each orange is added to the queue at most once.
- Each queued orange is removed and processed at most once.
- For each processed orange, you check exactly four neighbors.
- Checking four neighbors takes constant time, \(O(1)\).
Therefore, BFS takes \(O(r \times c)\) overall.
