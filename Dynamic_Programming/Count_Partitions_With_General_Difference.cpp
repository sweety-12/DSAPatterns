RECURSIVE APPROACH:
TC: O(2^n) and SC : O(n)

int func(int ind, int target, vector<int>&arr){
        
        //base case
        // if(target == 0) return 1;
        
        if(ind == 0){
            
            //handling 0's
            if(arr[0] == 0 && target == 0)  return 2;
            
            //not pick case
            if(target == 0) return 1;
            
            //pick case
            if(arr[0] == target) return 1;
            
            return 0;
        }
        
        //reccursive call
        int not_pick = func(ind -1, target, arr);
        int pick =0;
        
        if(arr[ind] <= target){
            pick = func(ind -1, target - arr[ind] , arr);
        }
        
        int ans = pick + not_pick;
        
        return ans;
    }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int target =0;
        int n = arr.size();
        
        int sum =0;
        for(int i=0; i<n ; i++){
            sum += arr[i];
        }
        
        //edge case -- OK THIS IS ONE OF THE EDGE CASE 
        //WE NEED TO TAKE CARE OF COZ (SUM - DIFF) /2 MUST BE AN POSITIVE
        //INTERGER AS THIS NEEDS TO BE IN THE REMAINING ARRAY
        if((sum - diff)%2 != 0) return 0;
        
        target = (sum-diff)/2;
        
        return func(n-1, target, arr);
    }

MEMOIZATION APPRAOCH:
TC : O(n*diff) and SC : O(n*diff)

   int func(int ind, int target, vector<int>&arr, vector<vector<int>>&dp){
        
        //base case
        // if(target == 0) return 1;
        
        if(ind == 0){
            
            //handling 0's
            if(arr[0] == 0 && target == 0)  return 2;
            
            //not pick case
            if(target == 0) return 1;
            
            //pick case
            if(arr[0] == target) return 1;
            
            return 0;
        }
        
        //overelapping sub problem
        if(dp[ind][target] != -1) return dp[ind][target];
        
        //reccursive call
        int not_pick = func(ind -1, target, arr, dp);
        int pick =0;
        
        if(arr[ind] <= target){
            pick = func(ind -1, target - arr[ind] , arr, dp);
        }
        
        int ans = pick + not_pick;
        
        return dp[ind][target] = ans;
    }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int target =0;
        int n = arr.size();
        
        int sum =0;
        for(int i=0; i<n ; i++){
            sum += arr[i];
        }
        
        //edge case -- OK THIS IS ONE OF THE EDGE CASE 
        //WE NEED TO TAKE CARE OF COZ (SUM - DIFF) /2 MUST NOT BE A DECIMAL VALUE 
        //AND BE AN POSITIVE INTERGER AS THIS NEEDS TO BE IN THE ARRAY
        
        
        if((sum - diff) %2 != 0 || (sum - diff) < 0) return 0; 
        
        target = (sum-diff)/2;   //THE TARGET WE ARE CALCULATING MUST ALSO BE POSITIVE
        
        vector<vector<int>>dp(n, vector<int>(target + 1, -1));
        
        return func(n-1, target, arr, dp);
    }
