LEETCODE 120. Triangle
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10

RECURSIVE APPROACH:
TC : O(2^(m+n) AND SC : O(m+n)

class Solution {
public:
    int func(int start_row, int start_col, int row, int col, vector<vector<int>>& grid) {

    //base case
    if(start_row == row) {
    return grid[start_row][start_col];
    }

    //recursive call

    //do all stuffs in the index
    int down = grid[start_row][start_col] + func(start_row+1, start_col, row, col, grid);

    int down_right = grid[start_row][start_col] + func(start_row+1, start_col +1, row, col, grid);

    //find min
    int ans = min(down, down_right);

    return ans;

}
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[0].size(); // this may be m-1 in place of 0 //EDIT -> THIS IS CURRENTLY NOT AFFECTING THE CODE, BUT IDEALLY IT SHOULD BE m-1.

        //STEP 1 - CONVERT THE PROBLEM IN THE FORM OF INDEX
         return func(0, 0, m-1, n-1, triangle);  
    }
};


MEMOIZATION APPROACH:      //MEMOIZATION CODE IS NOT ACCEPTED IN LEETCODE, MAY BE SOME REQUIREMENT DIFFERENT BUT THE CODE IS CORRECT.
TC: O(N*N) and SC : O(N) + O(N*N)    

int func(int start_row, int start_col, int row, int col, vector<vector<int>>& grid, vector<vector<int>>&dp)
{

//base case
if(start_row == row) {
return dp[start_row][start_col] = grid[start_row][start_col];
}

//overlapping subproblem
if(dp[start_row][start_col] != -1) return dp[start_row][start_col];

//recursive call

//do all stuffs in the index
int down = grid[start_row][start_col] + func(start_row+1, start_col, row, col, grid, dp);

int down_right = grid[start_row][start_col] + func(start_row+1, start_col +1, row, col, grid, dp);

//find min
int ans = min(down, down_right);
dp[start_row][start_col] = ans;

return ans;

}
int minimumTotal(vector<vector<int>>& triangle) {

int m = triangle.size();
int n = triangle[m-1].size(); // this may be m-1 in place of 0


vector<vector<int>>dp(m, vector<int>(n, -1));

//STEP 1 - CONVERT THE PROBLEM IN THE FORM OF INDEX
return func(0, 0, m-1, n-1, triangle, dp);
}

TABAULATION APPROACH:
TC: O(N*N) and SC: O(N*N)

int minimumTotal(vector<vector<int>>& triangle) {

int m = triangle.size();
int n = triangle[m-1].size(); // this may be m-1 in place of 0


vector<vector<int>>dp(m, vector<int>(n, 0));

for(int i=m-1; i>=0; i--) {
for(int j = 0; j <= i; j++) {

//base case
if(i == m-1) {
dp[i][j] = triangle[i][j];
continue;
}

int down =0;
int down_right = 0;

if(i<m-1) {
down = triangle[i][j] + dp[i+1][j];
down_right = triangle[i][j] +dp[i+1][j+1];
}

int ans = min(down, down_right);
dp[i][j] = ans;
}
}

return dp[0][0];

}
