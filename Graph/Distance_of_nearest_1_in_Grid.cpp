//------------------THIS ONE IS EXACTLY SIMILAR TO 01 MATRIX PROBLEM----------

GFG - Distance of Nearest 1 in Grid
Given a binary grid[][], where each cell contains either 0 or 1, find the distance of the nearest 1 for every cell in the grid.
The distance between two cells (i1, j1)  and (i2, j2) is calculated as |i1 - i2| + |j1 - j2|. 
You need to return a matrix of the same size, where each cell (i, j) contains the minimum distance from grid[i][j] to the nearest cell having value 1.

Note: It is guaranteed that there is at least one cell with value 1 in the grid.

Examples

Input: grid[][] = [[0, 1, 1, 0], 
                [1, 1, 0, 0], 
                [0, 0, 1, 1]]
Output: [[1, 0, 0, 1], 
        [0, 0, 1, 1], 
        [1, 1, 0, 0]]
Explanation: The grid is -

- 0's at (0,0), (0,3), (1,2), (1,3), (2,0) and (2,1) are at a distance of 1 from 1's at (0,1), (0,2), (0,2), (2,3), (1,0) and (1,1) respectively.

APPROACH : Multisource BFS
TC : O(r*c) and SC: O(r*c)

class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // code here
        
        int r = grid.size();
        int c = grid[0].size();
        
        vector<vector<int>>ans(r, vector<int>(c, 1e9));
        
        queue<pair<int, int>>q;
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                
                if(grid[i][j] == 1){
                    q.push({i, j});
                }
                
                if(grid[i][j] == 1){
                    ans[i][j] = 0;
                }
            }
        }
        
        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();
            
            for(int d =0; d<4; d++){
                
                int nrow = i + drow[d];
                int ncol = j + dcol[d];
                
                if(nrow <0 || nrow >= r || ncol <0 || ncol >= c)  continue;
                
                if(ans[nrow][ncol] == 1e9){
                    ans[nrow][ncol] = ans[i][j] + 1;
                    
                    q.push({nrow, ncol});
                }
                
            }
        }
        
         return ans;
    }
};
