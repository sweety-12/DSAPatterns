Valid Triangle Number — LeetCode #611
Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

Input:  nums = [2,2,3,4]
Output: 3
Explanation:
Valid combinations:
2,2,3 ✅  (2+2 > 3)
2,3,4 ✅  (2+3 > 4)
2,3,4 ✅  (2+3 > 4)

Input:  nums = [4,2,3,1]
Output: 1

Input:  nums = [0,1,0]
Output: 0
Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 1000
Key insight — after sorting:

a <= b <= c
only check: a + b > c

////////////////////////////////////////////////////////////
BRUTE FORE : It can be easily solved by using 3 nested loops and having i, j, k pointers
TC : O(n^3) and SC : O(1)

////////////////////////////////////////////////////////////
OPTIMIZED APPROACH :
TC : O(N^2) and SC : O(1)

int triangleNumber(vector<int>& nums) {
    int n = nums.size();
    int count = 0;

    sort(nums.begin(), nums.end());

    for(int c = n-1; c >= 2; c--) {  // ✅ fix c, move inward
        int i = 0, j = c - 1;        // ✅ reset pointers each time

        while(i < j) {
            if(nums[i] + nums[j] > nums[c]) {
                count += j - i;       // ✅ all pairs from i to j-1
                j--;
            } else {
                i++;
            }
        }
    }
    return count;
}


