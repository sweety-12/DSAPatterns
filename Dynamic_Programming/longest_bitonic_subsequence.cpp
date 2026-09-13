Longest Bitonic Subsequence
Given an array of positive integers. Find the maximum length of Bitonic subsequence.  A subsequence of array is called Bitonic if it is first strictly increasing, then strictly decreasing. Return the maximum length of bitonic subsequence.
 
Note : A strictly increasing or a strictly decreasing sequence should not be considered as a bitonic sequence

Examples :

Input: n = 5, nums[] = [1, 2, 5, 3, 2]
Output: 5
Explanation: The sequence [1, 2, 5] is increasing and the sequence [3, 2] is decreasing so merging both we will get length 5.

APPROACH:
TC: O(n^2) + O (n^2) + O(n)
SC: O(n)

class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        // code here
        vector<int>dp1 (n, 1);
        
        for(int i =0; i<n; i++){
            for(int prev = 0; prev <i ; prev++){
                
                if(nums[prev] < nums[i] && dp1[prev] + 1 > dp1[i]){
                    dp1[i] = dp1[prev] + 1;
                }
            }
        }
        
        vector<int>dp2(n, 1);
        
        for(int i = n-1; i>=0; i--){
            for(int prev = n-1; prev >i; prev--){
                
                if(nums[prev] < nums[i] && dp2[prev] + 1 > dp2[i]){
                    dp2[i] = dp2[prev] + 1;
                }
            }
        }
        
             int maxi =0;
                for(int i=0; i<n; i++){
                    
                    //ADD THIS IF STATEMENT ONLY IF STRICTLY INCREASING
                    //AND STRICTLY DECREASING IS NOT ALLOWED IN BITONIC SUBSEQUNCE
                     if(dp1[i] != 1 and dp2[i] != 1)
                    maxi = max(maxi, (dp1[i] + dp2[i] -1));
                }
                
 
    }
};


