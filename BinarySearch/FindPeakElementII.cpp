LLETCODE 1901. Find a Peak Element II
A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.
Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].
You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.
You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

Example 1:
Input: mat = [[1,4],[3,2]]
Output: [0,1]
Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.
Example 2:

OPTIMIZED APPROACH :
TC : O(c log r) and SC : O(1)

int findMaxIndex(vector<vector<int>>&mat, int n, int m, int col){
        int maxValue = -1;
        int index = -1;
        for(int i=0; i<n; i++){
            if(mat[i][col] > maxValue){
                maxValue = mat[i][col];
                index = i;
            }
        }

        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = m-1;

        while(low <= high){
            int mid = (low + high)/2;
            int maxRowIndex = findMaxIndex(mat, n, m, mid);
            int left = mid -1 >= 0 ? mat[maxRowIndex][mid -1] : -1;
            int right = mid + 1 < m ? mat[maxRowIndex][mid+1] : -1;

            if(mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right){
                return {maxRowIndex, mid};
            }

            else if(mat[maxRowIndex][mid] < left){
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }

        return {-1, -1};
    }
