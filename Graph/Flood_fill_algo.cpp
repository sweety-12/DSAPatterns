733. Flood Fill
You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.

Example 1:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

Output: [[2,2,2],[2,2,0],[2,0,1]]

Explanation:

From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.

Note the bottom corner is not colored 2, because it is not horizontally or vertically connected to the starting pixel.

APPROACH: USING DFS
TC: O (r*c) and SC: O(r*c)

//STEPS
// 1. Copy the image matrix.
// 2. Declare the drow and dcol for traversal
// 3. start traversing from the starting point
// 4. check the conditions in both matrix and color

class Solution {
public:
    void dfs(int i, int j, int color,  vector<vector<int>>&image,  vector<vector<int>>&vis , int initColor){

       if(i<0 || i> image.size() || j<0 || j> image[0].size()) return;


         int drow[] = {1, 0, -1, 0};
         int dcol[] = {0, 1, 0, -1};

            for(int d =0; d<4; d++){

                int nx = drow[d] + i;
                int ny = dcol[d] + j;

               if(nx >= 0 && nx < image.size() && ny >=0 && ny < image[0].size()
                && image[nx][ny] == initColor && vis[nx][ny] != color) {
                    vis[nx][ny] = color;

                    dfs(nx, ny, color, image, vis, initColor);
               } 
            }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r = image.size();
        int c = image[0].size();

        int initColor = image[sr][sc];
        vector<vector<int>>vis = image;

        vis[sr][sc] = color;
        dfs(sr, sc, color, image, vis, initColor);

       return vis;
    }
};
