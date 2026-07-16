LEETCODE 62. Unique Paths

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

RECURSIVE APPROACH:
TC : O(2^(m+n)) and SC: O(m+n)


int recursive_func(int row, int col){

//Base case
if(row == 0 && col == 0) return 1; // means we have found 1 unique path

//edge case
if(row < 0 || col < 0) return 0; // it will never help me to reach the destination


//recursive function
//Do all stuffs in that index

int first = recursive_func(row, col-1);

int second = recursive_func(row-1, col);


//count sum, max, min acc to question

int ans = first+second;

return ans;
}
int uniquePaths(int m, int n) {
// your code here

//CONVERT THE PROBLEM IN THE FORM OF INDEX
return recursive_func(m-1, n-1);

}

MEMOIZATION APPROACH:
TC: O(m*n) and SC : O(m*n)

//MEMOIZATION APPROACH:

int recursive_func(int row, int col, vector<vector<int>>&dp){

//base case
if(row == 0 && col == 0) return dp[row][col] = 1;

//edge case
if(row <0 || col <0) return 0;




//overlapping subproblem
if(dp[row][col] != -1) return dp[row][col];


//recursive function
int first = recursive_func(row, col -1, dp);
int second = recursive_func(row-1, col, dp);

dp[row][col] = first + second;

return dp[row][col];
}



int uniquePaths(int m, int n) {
// your code here

vector<vector<int>>dp(m, vector<int>(n, -1));

//CONVERT THE PROBLEM IN THE FORM OF INDEX
return recursive_func(m-1, n-1, dp);

}


TABULATION APPROACH:
TC : O(m*n) and SC : O(m*n)


//TABULATION
int uniquePaths(int m, int n) { // your code here
vector<vector<int>>dp(m, vector<int>(n, 0));
for(int i=0; i<m ; i++){ int first =0, second =0; for(int j =0; j<n ; j++){
if(i==0 && j == 0)
{ dp[i][j] = 1; 

continue;
}

int up =0; 
  if(i>0){
  up = dp[i-1][j];
}

int left =0; 
  if(j>0){
    left = dp[i][j-1];
  }

dp[i][j] = up + left; 
} 
                       
} 
return dp[m-1][n-1];
}

SPACE OPTIMIZATION:
TC: O(m*n) and SC :O(n)

 int func(int m, int n){
        /* Initialize a vector to represent 
        the previous row of the grid.*/
        vector<int> prev(n, 0);

        // Iterate through the rows of the grid.
        for (int i = 0; i < m; i++) {
            /* Create a temporary vector to
            represent the current row.*/
            vector<int> temp(n, 0);

            for (int j = 0; j < n; j++) {
                // Base case
                if (i == 0 && j == 0) {
                    temp[j] = 1;
                    continue;
                }

            /* Initialize variables to store the number
            of ways from the cell above (up) and left (left).*/
            int up = 0;
            int left = 0;

            /* If we are not at the first row (i > 0), update
            'up' with the value from the previous row.*/
            if (i > 0)
                up = prev[j];

            /* If we are not at the first column (j > 0),
            update 'left' with the value from current row.*/
            if (j > 0)
                left = temp[j - 1];

            /* Calculate the number of ways to reach the
            current cell by adding 'up' and 'left'.*/
            temp[j] = up + left;
        }

        /* Update the previous row with values 
        calculated for the current row.*/
        prev = temp;
    }

    /* The result is stored in the last
    cell of the previous row (n-1).*/
    return prev[n - 1];
}
public:
    /*Function to count the total ways
    to reach (0,0) from (m-1,n-1)*/
    int uniquePaths(int m, int n) {
        
        //Return the total count(0 based indexing)
        return func(m, n);
    }


