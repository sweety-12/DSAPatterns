Leetcode 1020. Number of Enclaves
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

Example 1:
Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.

APROACH: Multisource BFS

TC : O(r*c) and SC: O(r*c)

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
         int r = grid.size();
        int c = grid[0].size();

        //declare queue
        queue<pair<int, int>>q;

        //pushing all the o's which are at the boundary
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){

                if((i==0 || i == r-1 || j == 0 || j == c-1) && grid[i][j] == 1){
                    grid[i][j] = 2;
                    q.push({i, j});
                }
            }
        }

        //traversing 4 directions
        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()){

            auto[i, j] = q.front();
            q.pop();

            //mark than index as safe
            // grid[i][j] = '-1';

            for(int d =0; d<4; d++){

                int nrow = i + drow[d];
                int ncol = j + dcol[d];

                
                if((nrow >0 && nrow <r-1 && ncol >0 && ncol < c-1) && (grid[nrow][ncol] == 1)){
                    grid[nrow][ncol] = 2;
                    q.push({nrow, ncol});
                }

            }
        }
        int count =0;
        //NOW CONVERT ALL THE INDEX WHICH ARE NOT MARKED AS SAFE
         for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){

                if(grid[i][j] == 1){
                   count++;
                }
            }
        }

        return count;
    }
};
