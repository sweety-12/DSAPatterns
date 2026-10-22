// IMPORTANT NOTE: RULES TO SOLVE ANY MULTISOURCE BFS QUESTION
//**PUSH ALL THE STARTING POINTS TO QUEUE AND THEN TRAVERSE**

542. 01 Matrix
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.

Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]

APPROACH: MULITSOURCE BFS

  TC : O(r*c) and SC: O(r*c)

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();

        vector<vector<int>>output(r, vector<int>(c, 1e9));

        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};

        queue<pair<int, int>>q;

        for(int i=0; i<r; i++){
            for(int j =0; j<c; j++){

                if(mat[i][j] == 0){
                    q.push({i, j});
                }

                if(mat[i][j] == 0){
                    output[i][j] = 0;  //INITIALIZE DISTANCE TO 0
                }
            }
        }

        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();

            // int count =0;

            for(int d =0; d<4; d++){
                int nrow = i + drow[d];
                int ncol = j + dcol[d];

                if(nrow <0 || nrow>= r || ncol < 0 || ncol >= c )  continue;

                if(output[nrow][ncol] == 1e9){
                    //any 4 neightbour is 0 then assign 1
                    output[nrow][ncol] = output[i][j] + 1;  
                    q.push({nrow, ncol});
                    
                    }
                }
            
           }

        return output;
    }
};
