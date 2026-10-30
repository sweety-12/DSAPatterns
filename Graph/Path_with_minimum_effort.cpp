1631. Path With Minimum Effort
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

Example 1:
Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

Example 2:
Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].

APPROACH: Extended Dijkstra Algo
TC: O(r*c(log(r*c)) and SC: O(r*c)

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int r = heights.size();
        int c = heights[0].size();

        vector<vector<int>>dist(r, vector<int>(c, INT_MAX));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;

        dist[0][0] = 0;
       pq.push({0, {0, 0}});

        //to traverse the 4 direction
        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};


        while(!pq.empty()){

            int effort = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;

            pq.pop();

            if(effort > dist[i][j]) continue;

            for(int d =0; d<4; d++){

                int nrow = i + drow[d];
                int ncol = j + dcol[d];

                if(nrow >= 0 && nrow <r && ncol >= 0 && ncol < c){

                    int diff = abs(heights[nrow][ncol] - heights[i][j]);
                    int newEffort = max(diff, dist[i][j]);

                    if(newEffort < dist[nrow][ncol]){
                        dist[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                }

            }

        }

        return dist[r-1][c-1];
        
    }
};
