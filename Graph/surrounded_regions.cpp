130. Surrounded Regions
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: A region is surrounded if none of the 'O' cells in that region are on the edge of the board. Such regions are completely enclosed by 'X' cells.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Explanation:
In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

APPROACH: Multisource BFS
TC: O(r*c) and SC: O(r*c)

class Solution {
public:
    void solve(vector<vector<char>>& grid) {

        int r = grid.size();
        int c = grid[0].size();

        //declare queue
        queue<pair<int, int>>q;

        //pushing all the o's which are at the boundary
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){

                if((i==0 || i == r-1 || j == 0 || j == c-1) && grid[i][j] == 'O'){
                    grid[i][j] = '1';
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

                
                if(nrow >0 && nrow <r-1 && ncol >0 && ncol < c-1 && grid[nrow][ncol] == 'O'){
                    grid[nrow][ncol] = '1';
                    q.push({nrow, ncol});
                }

            }
        }

        //NOW CONVERT ALL THE INDEX WHICH ARE NOT MARKED AS SAFE
         for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){

                if(grid[i][j] == '1'){
                    grid[i][j] = 'O';
                }

                else{
                    grid[i][j] = 'X';
                }
            }
        }
        
    }
};
