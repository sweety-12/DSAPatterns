673. Number of Longest Increasing Subsequence
Given an integer array nums, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.
Example 1:

Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:

Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.


APPROACH:
TC: O(n^2) + O(n) and SC : O(n)

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size();
          // code here
        vector<int>dp1(n, 1);
        vector<int>count(n, 1);
        
        for(int i =0; i<n; i++){
            for(int prev = 0; prev <i ; prev++){
                
                if(nums[prev] < nums[i] && dp1[prev] + 1 > dp1[i]){
                    dp1[i] = dp1[prev] + 1;
                    count[i] = count[prev];
                }
                else if(nums[prev] < nums[i] && dp1[prev] + 1 == dp1[i]){

                    count[i] += count[prev];
                }
            }
        }

        int maxi =1;
        for(int i=0; i<n; i++){

            maxi = max(maxi, dp1[i]);
        }

        int ans=0;
        for(int i=0; i<n; i++){
            if(dp1[i] == maxi){
                ans += count[i];
            }
        }
        return ans;
    }
};
