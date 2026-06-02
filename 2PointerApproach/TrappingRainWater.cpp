Problem 2 of 4 — Trapping Rain Water
Difficulty: Hard

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
Input:  height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

Input:  height = [4,2,0,3,2,5]
Output: 9
Visual for example 1:
        |
    |   | | | |
|   | | | | | | | |
0 1 0 2 1 0 1 3 2 1 2 1

Water trapped = 6 units
Constraints:

n == height.length
1 <= n <= 2 * 10⁴
0 <= height[i] <= 10⁵


BETTER APPROACH :
TC : O(n) and SC : O(n)

int mostWater(vector<int>&height){

    int trappedWater = 0;
    int n = height.size();
    vector<int>prefixLeft(n);
    vector<int>prefixRight(n);

    prefixLeft[0] = height[0];
    prefixRight[n-1] = height[n-1];

    for(int i=1; i<n; i++){
        prefixLeft[i] = max(height[i], prefixLeft[i-1]);
    }

    for(int i= n-2; i>=0 ; i--){
        prefixRight[i] = max(height[i], prefixRight[i+1]);
    }

    //finding the final ans
    for(int i=0; i<n; i++){
        trappedWater += min(prefixLeft[i], prefixRight[i]) - height[i];
    }

    return trappedWater;
}

OPTIMIZED  APPROACH :
TC : O(n) and SC : O(1)
