LEETCODE 2643. Row With Maximum Ones
Given a m x n binary matrix mat, find the 0-indexed position of the row that contains the maximum count of ones, and the number of ones in that row.
In case there are multiple rows that have the maximum count of ones, the row with the smallest row number should be selected.
Return an array containing the index of the row, and the number of ones in it.
Example 1:
Input: mat = [[0,1],[1,0]]
Output: [0,1]
Explanation: Both rows have the same number of 1's. So we return the index of the smaller row, 0, and the maximum count of ones (1). So, the answer is [0,1]. 
Example 2:

Input: mat = [[0,0,0],[0,1,1]]
Output: [1,2]
Explanation: The row indexed 1 has the maximum count of ones (2). So we return its index, 1, and the count. So, the answer is [1,2].
Example 3:

Input: mat = [[0,0],[1,1],[0,0]]
Output: [1,2]
Explanation: The row indexed 1 has the maximum count of ones (2). So the answer is [1,2].


BRUTE FORCE : SIMPLY TRAVERSE IN THE ENTIRE MATRIX ROW BY ROW, SIMUTANEOULY MAINTAIN THE COUNT_MAX VARIABLE  AND INDEX AND RETURN THE ROW WITH MAX 1's
TC : O(m*n) and SC :O(1)

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
        int cnt_max = 0;  // Max number of 1s found
        int index = -1;   // Index of row with most 1s

        // Traverse each row of the matrix
        for (int i = 0; i < n; i++) {
            int cnt_ones = 0;  // Count 1s in current row
            for (int j = 0; j < m; j++) {
                cnt_ones += matrix[i][j];
            }
            // Update if this row has more 1s
            if (cnt_ones > cnt_max) {
                cnt_max = cnt_ones;
                index = i;
            }
        }
        return {index, cnt_max};
    }

OPTIMIZED APPROACH: BINARY SEARCH
TC : O(nlogm) and SC :O(1)

 int count(vector<int>row, int m, int one){

         sort(row.begin(), row.end());

        int low = 0;
        int high = m-1;
        int ans = m;

        while(low <= high){

            int mid = (low + high)/2;

            if(row[mid] == one){
                ans = mid;
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int count_max = -1;
        int index = -1;

        for(int i=0; i<m; i++){

            int count_ones = n - count(mat[i], n, 1);

            if(count_ones > count_max){
                count_max = count_ones;
                index = i;
            }
        }
        return {index, count_max};
    }
