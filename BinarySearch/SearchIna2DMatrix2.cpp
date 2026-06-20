LEETCODE 240. Search a 2D Matrix II
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

NOTE : Integers in each row are sorted in ascending from left to right.
NOTE : Integers in each column are sorted in ascending from top to bottom.
 
Example 1:

Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true

//Unquie Matrix is given where all the rows are sorted on its own and all the columns are sorted on its own.

BETTER APPROACH : SAME BINARY SEARCH(SOLVED IN searchA2DMatrix), where passing all the rows one by one and performing binary seach in it.
TC : O(rlogc) and SC : O(1)

OPTIMIZED APPROACH:
TC : O( r+c) and SC : O(1)

bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int r = matrix.size();
        int c = matrix[0].size();

        int i=0, j= c-1;

        while(i< r && j>= 0){

            if(target == matrix[i][j])  return true;
            else if(target > matrix[i][j]) i++;
            else  j--;
        }
        return false;    
    }

