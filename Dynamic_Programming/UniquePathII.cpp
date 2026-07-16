LEETCODE 63. Unique Paths II

You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

RECURSIVE APPROACH :
TC : O(2^(m+n)) and SC : O(m+n)


class Solution {
public:
    int func(int row, int col, vector<vector<int>>&grid){

        //base case
        if(row == 0 && col == 0)  return 1;

        //edge case
        if(row < 0 ||  col < 0)  return 0;

        //obstacle
        if(grid[row][col] == 1)  return 0;

        //recursive call
        int left = func(row, col-1, grid);

        int up = func(row-1, col, grid);


        int ans = left + up;

        return ans;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        //edge case
        if(grid[m-1][n-1] == 1 || grid[0][0] == 1) {
            return 0;
        }

        //convert into index
        return func(m-1, n-1, grid);
        
    }
};

MEMOIZATION APPROACH:
TC: O(m*n) and SC : O((N-1)+(M-1)) + O(M*N)

class Solution {
public:
    int func(int row, int col, vector<vector<int>>&grid, vector<vector<int>>&dp){

        //base case
        if(row == 0 && col == 0)  return dp[row][col] = 1;

        //edge case
        if(row < 0 ||  col < 0)  return 0;

        //obstacle
        if(grid[row][col] == 1)  return 0;

        //overlapping subproblem
       if(dp[row][col] != -1)  return dp[row][col]; 

        //recursive call
        int left = func(row, col-1, grid, dp);

        int up = func(row-1, col, grid, dp);


        int ans = left + up;
        return dp[row][col] = ans;
        // return ans;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        //edge case

        //STARTING AND ENDING POINT MUST NOT HAVE OBSTACLE
        if(grid[m-1][n-1] == 1 || grid[0][0] == 1) {
            return 0;
        }

        //converting to memoization
        vector<vector<int>>dp(m, vector<int>(n, -1));

        //convert into index
        return func(m-1, n-1, grid, dp);

    }
};

TABULATION APPROACH:
TC: O(m*n) and SC : O(m*n)

  class Solution {
public:
    int func(int row, int col, vector<vector<int>>&grid, vector<vector<int>>&dp){

        for(int i=0; i<row; i++){
            for(int j =0; j<col; j++){


                if(grid[i][j] == 1){
                    dp[i][j] =0;
                    continue;
                }

                if(i==0 && j == 0) {
                    dp[i][j] = 1;

                    continue;
                } 

                int up =0;
                int left =0;

                if(i>0){
                    
                    up = dp[i-1][j];
                }

                if(j>0){
                   
                    left = dp[i][j-1];
                }


                dp[i][j] = up + left;
            }
        }

        return dp[row-1][col-1];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        //edge case

        //STARTING AND ENDING POINT MUST NOT HAVE OBSTACLE
        // if(grid[m-1][n-1] == 1 || grid[0][0] == 1) {
        //     return 0;
        // }

        //converting to memoization
        vector<vector<int>>dp(m, vector<int>(n, 0));

        //convert into index
        return func(m, n, grid, dp);

    }
};
