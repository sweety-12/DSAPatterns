GFG - Median in a row-wise sorted Matrix
Given a row-wise sorted matrix mat[][] of size n*m, where the number of rows and columns is always odd. Return the median of the matrix.
Examples:
Input: mat[][] = [[1, 3, 5], 
                [2, 6, 9], 
                [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives us [1, 2, 3, 3, 5, 6, 6, 9, 9]. Hence, 5 is median.
Input: mat[][] = [[2, 4, 9],
                [3, 6, 7],
                [4, 7, 10]]
Output: 6
Explanation: Sorting matrix elements gives us [2, 3, 4, 4, 6, 7, 7, 9, 10]. Hence, 6 is median.
Input: mat = [[3], [4], [8]]
Output: 4
Explanation: Sorting matrix elements gives us [3, 4, 8]. Hence, 4 is median.

BRUTE FORCE : TRAVERSE ENTIRE MATRIX, STORE IT IN A 1D VECTOR AND FIND MEDIAN
TC : O(n*m) and SC : O(n*m)

OPTIMIZED APPROACH : BINARY SEARCH
TC : O(log (10^9) + (n log m)) and SC : O(1)
  
// USING BINARY SEARCH (CONCEPT IS NOT VERY DIFFICULT, JUST FINDING THE NUMBERS WHICH 
// ARE LESSER THAN THE MEDIAN WE ARE PASSING THE BINARYSEARCH FUNCTION. REVISIT THE LAST LECTURE FOR MORE CLARITY.

int countLessEqual(vector<int>& row, int mid) {
        // Using upper_bound to find count efficiently
        return upper_bound(row.begin(), row.end(), mid) - row.begin();
}
    
int median(vector<vector<int>> &matrix) {
        // code here
      int rows = matrix.size();
      int cols = matrix[0].size();

        // Minimum possible element in matrix
        int low = matrix[0][0];

        // Maximum possible element in matrix
        int high = matrix[0][cols - 1];
        for (int i = 1; i < rows; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][cols - 1]);
        }

        // Binary search over the value range
        while (low < high) {
            int mid = (low + high) / 2;

            // Count elements ≤ mid
            int count = 0;
            for (int i = 0; i < rows; i++) {
                count += countLessEqual(matrix[i], mid);
            }

            // If count is less than half, median is greater
            if (count < (rows * cols + 1) / 2)
                low = mid + 1;
            else
                high = mid;
        }

        // Final low is the median
        return low;
  }
