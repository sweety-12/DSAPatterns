300. Longest Increasing Subsequence

Given an integer array nums, return the length of the longest strictly increasing subsequence.
Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104


Recursive approach:
TC: O(2^n) and SC : O(n)

class Solution {
public:
    int func(int ind, int prev, int n, vector<int>&nums){
        //base case
        if(ind == n) return 0;

        //recursive calls
        // not take
        int len =  0 + func(ind + 1, prev, n, nums);

        //take 
        if(prev == -1 || nums[ind] > nums[prev]){
            
            len =  max(len,  1 + func(ind + 1, ind, n, nums));
        }

        return len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        return func(0, -1, n, nums);
    }
};
