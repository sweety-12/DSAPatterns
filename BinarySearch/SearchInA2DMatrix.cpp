74. Search a 2D Matrix

You are given an m x n integer matrix matrix with the following two properties:
Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
Example 1:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

BRUTE FORCE: TRAVERSE A MATRIX USING NESTED LOOP AND SEARCH
TC : o(m*n) and SC : O(1)

BETTER SOLUTION 1 : COMPARE THE LAST COLUMN VALUES OF EVERY ROW, IF IT IS LOW THEN MOVE TO THE NEXT ROW , 
IF LESS THEN VALUE LIES IN THE CURRENT ROW, DO J--;

TC : O(n+m) and SC : O(1)

bool searchMatrix(vector<vector<int>>& matrix, int target) {

      int n = matrix.size();
      int m = matrix[0].size();
      int i = 0;
      int j = m-1;

      while(i<n && j >=0){
        if(matrix[i][j] == target) return true;

        else if(matrix[i][j] > target) j--;

        else i++;
      }
        return false;
    }

BETTER SOLUTION2 : USING BINARY SEARCH WHERE WE WILL COMPARE IF, THE TARGET >= FIRST VALUE OF THE ROW AND TARGET <= LAST VALUE OF THE ROW.
IF TARGET LIES THEN WE WILL APPLY BINARY SEARCH ON THAT ROW ONLY.

TC : O(n + log m) or O(r + log c) and SC : O(1)

bool binarySearch(vector<int>row, int target){
        int low = 0;
        int high = row.size()-1;

        while(low <= high){

            int mid = (low + high)/2;

            if(row[mid] == target) return true;
            else if(row[mid] > target) {
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int r = matrix.size();
        int c = matrix[0].size();

        for(int i=0; i<r; i++){

            if(target >= matrix[i][0] &&  target <= matrix[i][c-1]){

                bool isPossible = binarySearch(matrix[i], target);

                if(isPossible == true){
                    return true;
                }
            }
        }
        
        return false;
    }

OPTIMIZED APPROACH : USING BINARY SEARCH AND MATHS :( 
//VERY INTERESTING MATHS CONCEPT TO FIND ROW AND COLUMN FROM A 2D SORTED MATRIX BY STRIVER(BS-24)<- REFER TO THIS LECTURE WHENEVER YOU FORGOT.
//HERE WE ARE CREATING AN IMARGINARY 1D ARRAY FROM THAT 2D MATRIX AND THEN APPLY BINARY SEARCH ON IT.

TC : O(log m*n) and SC : O(1)

bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int r = matrix.size();
        int c = matrix[0].size();

        int low = 0, high = r*c-1;

        while(low <= high){

            int mid = (low + high)/2;
            int row = mid / c;
            int col = mid % c;

            if(matrix[row][col] == target)  return true;
            else if(matrix[row][col] > target)  high = mid -1;
            else low = mid + 1;
        }

        return false;
    }
  
