200. Number of Islands
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

APPROACH 1: DFS Solution with visited vector.
TC: O(r*c) And SC: O(r*c)
//WHAT IF THE INTERVIEWER ASKED WE CAN'T MODIFY THE INPUT GRID.

class Solution {
public:
    void dfs(int i, int j, int row, int col, vector<vector<char>>&grid, vector<vector<int>>&vis){

        //boundary conditions
        if( i<0 || i>= row || j<0 || j>= col) return;

        //if already visited 
        if(vis[i][j] == '1' || grid[i][j] == '0') return;


        vis[i][j] = '1';  //mark it as visited

        dfs(i+1, j, row, col, grid, vis);   //down
        dfs(i, j+1, row, col, grid, vis);   //right
        dfs(i-1, j, row, col, grid, vis);   //up
        dfs(i, j-1, row, col, grid, vis);   // left
    }
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>>vis(r, vector<int>(c, 0));

        int islands =0;

        for(int i=0; i<r; i++){
            for(int j =0; j<c; j++){

                if(grid[i][j] == '1' && vis[i][j] == 0)
                {
                    dfs(i, j, r, c, grid, vis);
                    islands++;
                }
            }
        }

        return islands;
    }
};


APPROACH 2: IF WE CAN MODIFY THE INPUT GRID.
TC: O(r*c) and SC : O(1)
  
class Solution {
public:
    void dfs(int i, int j, int row, int col, vector<vector<char>>&grid){

        //boundary conditions
        if( i<0 || i>= row || j<0 || j>= col) return;

        //if already visited 
        if(grid[i][j] == '2' || grid[i][j] == '0') return;


        grid[i][j] = '2';  //mark it as visited

        dfs(i+1, j, row, col, grid);   //down
        dfs(i, j+1, row, col, grid);   //right
        dfs(i-1, j, row, col, grid);   //up
        dfs(i, j-1, row, col, grid);   // left
    }
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        int islands =0;

        for(int i=0; i<r; i++){
            for(int j =0; j<c; j++){

                if(grid[i][j] == '1')
                {
                    dfs(i, j, r, c, grid);
                    islands++;
                }
            }
        }

        return islands;
    }
};
