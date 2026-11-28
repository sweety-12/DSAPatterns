Leetcode 2090: You are given a 0-indexed array nums of n integers, and an integer k.

The k-radius average for a subarray of nums centered at some index i with the radius k is the average of all elements in nums between the indices i - k and i + k (inclusive). If there are less than k elements before or after the index i, then the k-radius average is -1.

Build and return an array avgs of length n where avgs[i] is the k-radius average for the subarray centered at index i.

The average of x elements is the sum of the x elements divided by x, using integer division. The integer division truncates toward zero, which means losing its fractional part.

For example, the average of four elements 2, 3, 1, and 5 is (2 + 3 + 1 + 5) / 4 = 11 / 4 = 2.75, which truncates to 2.
 

Example 1:
Input: nums = [7,4,3,9,1,8,5,2,6], k = 3
Output: [-1,-1,-1,5,4,4,-1,-1,-1]
Explanation:
- avg[0], avg[1], and avg[2] are -1 because there are less than k elements before each index.
- The sum of the subarray centered at index 3 with radius 3 is: 7 + 4 + 3 + 9 + 1 + 8 + 5 = 37.
  Using integer division, avg[3] = 37 / 7 = 5.
- For the subarray centered at index 4, avg[4] = (4 + 3 + 9 + 1 + 8 + 5 + 2) / 7 = 4.
- For the subarray centered at index 5, avg[5] = (3 + 9 + 1 + 8 + 5 + 2 + 6) / 7 = 4.
- avg[6], avg[7], and avg[8] are -1 because there are less than k elements after each index.

APPROACH : SLIDING WINDOW
TC: O(n) and SC: O(n)

// Steps to solve
// 1. Calculate the window size: windowSize = 2*k + 1.
// 2. Initialize the answer vector with -1 because indices without a complete window will remain -1.
// 3. Handle edge cases:
//    - If k == 0, return nums.
//    - If n < 2*k + 1, return the answer vector filled with -1.
// 4. Calculate the sum of the first window (indices 0 to 2*k).
// 5. Calculate the average and store it at index k.
// 6. Start sliding from index k+1.
// 7. Update the window sum by:
//    sum += nums[i+k] - nums[i-k-1];
// 8. Calculate the average and store it at ans[i].
// 9. Repeat until the window reaches the end.
// 10. Return the answer vector.


class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();

        long long sum =0;
        vector<int>ans(n, -1);   //for storign the final values

        //edge cases.       //i was able to solve this question but forgot these edge case
        if(k == 0) return nums;
        if(n < 2*k + 1) return ans;


        //first window
        for(int i=0; i < 2*k+1; i++){
            sum += nums[i];
        }

        int avg = sum/(2*k+1);

        ans[k] = avg;   
        int i = k+1;
        while(i+k < n){
            sum += nums[i+k] - nums[i-k-1];

            int avg = sum/(2*k+1);

            ans[i] = avg;
            i++;
        }

        return ans;
    }
};
