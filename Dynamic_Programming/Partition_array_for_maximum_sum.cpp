1043. Partition Array for Maximum Sum
Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
Example 2:

Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83

RECURSIVE APPROACH:
TC: Exponential  and SC: O(1)

class Solution {
public:
    int func(int ind, vector<int>&arr, int k){

        int n = arr.size();

        //base case
        if(ind == n)  return 0;

        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;

        //recursive calls
         for(int i = ind; i < min(ind + k, n) ; i++)    //min(ind + k, n) means the traversal must not go beyond out bound, it may happen that at last ind + k elements are not remaining hence whatever remaining i.e n i should traverse till that.
        {
            len++;
            maxi = max(maxi, arr[i]);

            int sum = len * maxi + func(i+1, arr, k);
            maxAns = max(maxAns, sum);
        } 

        return maxAns;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {

        return func(0, arr, k);
        
    }
};

MEMOIZATION APPROACH:
TC: O(n*k) and SC: O(n) + O(n)

//MEMOIZATION APPROACH

class Solution {
public:
    int func(int ind, vector<int>&arr, int k, vector<int>&dp){

        int n = arr.size();

        //base case
        if(ind == n)  return 0;

        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;


        //overlapping subproblem
        if(dp[ind] != -1)  return dp[ind];

        //recursive calls
         for(int i = ind; i < min(ind + k, n) ; i++)    //min(ind + k, n) means the traversal must not go beyond out bound, it may happen that at last ind + k elements are not remaining hence whatever remaining i.e n i should traverse till that.
        {
            len++;
            maxi = max(maxi, arr[i]);

            int sum = len * maxi + func(i+1, arr, k, dp);
            maxAns = max(maxAns, sum);
        } 

        return dp[ind] = maxAns;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {

        int n = arr.size();
        vector<int>dp(n, -1);
        return func(0, arr, k, dp);
        
    }
};

TABULATION APPROACH:
TC: O(n*k) and SC: O(n)

class Solution {
public:

    int maxSumAfterPartitioning(vector<int>& arr, int k) {

        int n = arr.size();
        vector<int>dp(n+1, 0);

        for(int ind = n-1; ind >=0; ind--){

                int len = 0;
                int maxi = INT_MIN;
                int maxAns = INT_MIN;

                //recursive calls
                for(int i = ind; i < min(ind + k, n) ; i++)    //min(ind + k, n) means the traversal must not go beyond out bound, it may happen that at last ind + k elements are not remaining hence whatever remaining i.e n i should traverse till that.
                {
                    len++;
                    maxi = max(maxi, arr[i]);

                    int sum = len * maxi + dp[i+1];
                    maxAns = max(maxAns, sum);
                } 

               dp[ind] = maxAns;
        }
        return dp[0];
        
    }
};
