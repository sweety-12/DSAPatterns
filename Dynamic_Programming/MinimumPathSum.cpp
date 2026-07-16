LEETCODE 64. Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

RECURSIVE APPROACH:
TC : O(2^(m+n) and O(m+n)

class Solution {
public:
    int func(int row, int col, vector<vector<int>>& grid){

        //base case
        if(row == 0 && col == 0){
            return grid[0][0];
        }

        //edge case
        if(row <0 || col <0){
            return 1e9;
        }

        //recursive call

        int left = grid[row][col] +  func(row, col-1, grid);

        int up = grid[row][col] + func(row-1, col, grid);

        int ans = min(left, up);


        return ans;
    }
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        return func(m-1, n-1, grid);        
    }
};

MEMOIZATION APPROACH:
TC: O(m*n) and SC : O(m*n) + O((m-1) + (n-1))

class Solution {
public:
    int func(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp){

        //base case
        if(row == 0 && col == 0){
            return dp[0][0] = grid[0][0];
        }

        //edge case
        if(row <0 || col <0){
            return 1e9;
        }

        //overlapping subproblems
        if(dp[row][col] != -1)  return dp[row][col];
        //recursive call

        int left = grid[row][col] +  func(row, col-1, grid, dp);

        int up = grid[row][col] + func(row-1, col, grid, dp);

        int ans = min(left, up);


        return dp[row][col] = ans;
    }
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>dp(m, vector<int>(n, -1));
        return func(m-1, n-1, grid, dp);        
    }
};

TABULATION APPROACH:
TC:O(m*n) and SC : O(m*n)

class Solution {
public:
    int func(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp){

       for(int i=0; i<row; i++){
        for(int j =0; j<col; j++){

            //base case
            if(i==0 && j ==0){
                dp[i][j] = grid[i][j];

                 continue;
            }
            int up = 0; //grid[i][j];
            int left = 0; //grid[i][j];

            if(i>0){
                up += grid[i][j] + dp[i-1][j];
            }
            else{
                up +=1e9;
            }

            if(j >0){
                left = grid[i][j] + dp[i][j-1];
            }
            else{
                left +=1e9;
            }


            int ans = min(left, up);
            dp[i][j] = ans;
        }
       }

       return dp[row-1][col-1];
    }
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>dp(m, vector<int>(n, 0));
        return func(m, n, grid, dp);        
    }
};
