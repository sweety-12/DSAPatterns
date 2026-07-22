Given an array arr[]  containing non-negative integers, the task is to divide it into two sets set1 and set2 such that the absolute difference between their sums is minimum and find the minimum difference.

Examples:

Input: arr[] = [1, 6, 11, 5]
Output: 1
Explanation: 
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11 
Hence, minimum difference is 1.  

MEMOIZATION APPROACH:
TC : WILL UPDATE

 bool subsetSumUntil(int ind, int target, vector<int>&arr, vector<vector<int>>&dp){
        if(target == 0){
            return dp[ind][target] = true;
        }

        if(ind == 0){
            return dp[ind][target] = (arr[0] == target);
        }

        if(dp[ind][target] != -1)
             return dp[ind][target];

        bool not_taken = subsetSumUntil(ind -1, target, arr, dp);

        bool taken = false;
        if(arr[ind] <= target){
            taken = subsetSumUntil(ind -1, target - arr[ind], arr, dp);
        }

        return dp[ind][target] = not_taken || taken;
    }

    int minDifference(vector<int>& arr) {
        // code here
        int n = arr.size();
        int totSum =0;

        for(int i=0; i<n; i++){
            totSum += arr[i];
        }

        vector<vector<int>>dp(n, vector<int>(totSum + 1, -1));

        for(int i=0; i<= totSum ; i++){

            bool dummy = subsetSumUntil(n-1, i, arr, dp);
        }

        int mini = 1e9;
        for(int i=0; i<= totSum ; i++){
            if(dp[n-1][i] == true){
                int diff = abs(i - (totSum - i));
                mini = min(mini, diff);
            }
            
        }

        return mini;
    }

TABULATION APPROACH:
TC : WILL UPDATE

int minDifference(vector<int>& arr) {
        // code here
         int n = arr.size();
        int totSum =0;

        for(int i=0; i<n; i++){

            totSum += arr[i];
        }

        vector<vector<bool>>dp(n, vector<bool>(totSum + 1, false));


        for(int i=0; i<n; i++){
            dp[i][0] = true;
        }

        if(arr[0] <= totSum){
            dp[0][arr[0]] = true;
        }

        for(int ind =1; ind <n; ind++){
            for(int target = 1; target <= totSum ; target++){

                bool not_taken = dp[ind -1][target];

                bool taken = false;
                if(arr[ind] <= target){
                    taken = dp[ind - 1][target - arr[ind]];
                }

                dp[ind][target] = not_taken || taken;
            }
        }

        int mini = 1e9;
        for(int i=0; i<= totSum ; i++){
            if(dp[n-1][i] == true){

                int diff = abs(i - (totSum - i));
                mini = min(mini, diff);
            }
        }

        return mini;
    }
