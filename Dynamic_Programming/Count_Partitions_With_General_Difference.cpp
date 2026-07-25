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
        //WE NEED TO TAKE CARE OF COZ (SUM - DIFF) /2 MUST BE A POSITIVE
        //INTERGER AS THIS NEEDS TO BE IN THE REMAINING ARRAY
        if((sum - diff)%2 != 0) return 0;
        
        target = (sum-diff)/2;
        
        return func(n-1, target, arr);
    }

MEMOIZATION APPRAOCH:
TC : O(n*target) and SC : O(n*target)

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

TABULATION APPROACH;
TC: O(N*TARGET) AND SC : O(N*TARGET)

 int tabulationApproach(vector<int>&arr, int n, int diff, int target,  vector<vector<int>>&dp){
        
        //base case
        //THIS BASE CASE IS HAUNTING ME BROTHER...... :(
        if(arr[0] == 0)  dp[0][0] = 2;
        else dp[0][0] =1;
        
        if(arr[0] != 0 && arr[0] <= target)  dp[0][arr[0]] = 1;
        
        //nested loop
        for(int i = 1; i<n; i++){
            for (int j = 0 ; j<= target ; j++){
                
                int not_pick = dp[i-1][j];
                
                int pick = 0;
                if(arr[i] <= j){
                    pick = dp[i-1][j- arr[i]];
                }
                
                dp[i][j] = pick + not_pick;
                
            }
        }
        
        return dp[n-1][target];
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
        
        vector<vector<int>>dp(n, vector<int>(target + 1, 0));
        
        return tabulationApproach(arr, n, diff, target, dp);
        
    }
