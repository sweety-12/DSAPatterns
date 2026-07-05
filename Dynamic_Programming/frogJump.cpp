GFG -> Frog Jump : Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts from the first stair and wants to reach the last stair. From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. The cost of a jump is the absolute difference in height between the two stairs. Determine the minimum total cost required for the frog to reach the last stair.

Example:
Input: heights[] = [20, 30, 40, 20]
Output: 20
Explanation:  Minimum cost is incurred when the frog jumps from stair 0 to 1 then 1 to 3:
jump from stair 0 to 1: cost = |30 - 20| = 10
jump from stair 1 to 3: cost = |20 - 30| = 10
Total Cost = 10 + 10 = 20
Input: heights[] = [30, 20, 50, 10, 40]
Output: 30
Explanation: Minimum cost will be incurred when frog jumps from stair 0 to 2 then 2 to 4:
jump from stair 0 to 2: cost = |50 - 30| = 20
jump from stair 2 to 4: cost = |40 - 50| = 10
Total Cost = 20 + 10 = 30
Constraints:
1 ≤ height.size() ≤ 105
0 ≤ height[i] ≤ 104


RECURSION APPROACH :
TC : O(2^n) and SC : O(n) <- recursion stack

int f(int ind, vector<int>height){
        
        //DO ALL THE STUFFS IN THAT INDEX
        if(ind == 0)  return 0;
        
        int left = f(ind-1, height) + abs(height[ind] - height[ind-1]);
        
        int right = INT_MAX;
        
        if(ind > 1){
            right = f(ind-2, height) + abs(height[ind] - height[ind-2]);
        }
        
        //FIND THE MINIMUM OF ALL
        return min(left, right);
        
    }
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        
        //CONVERT THIS PROBLEM IN THE FORM OF INDEX
        return f(n-1, height);
    }

Memoization Approach:
TC : O(n) and SC : O(n) + O(n)

int f(int ind, vector<int>height, vector<int>&dp){
        
        //DO ALL THE STUFFS IN THAT INDEX
        if(ind == 0)  return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        int left = f(ind-1, height, dp) + abs(height[ind] - height[ind-1]);
        
        int right = INT_MAX;
        
        if(ind > 1){
            right = f(ind-2, height, dp) + abs(height[ind] - height[ind-2]);
        }
        
        //FIND THE MINIMUM OF ALL
        return dp[ind] = min(left, right);
        
    }
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        
        //Converting to memoization
        vector<int>dp(n+1, -1);
        
        //CONVERT THIS PROBLEM IN THE FORM OF INDEX
        return f(n-1, height, dp);
    }

Tabulation Approach :
TC : O(n) and SC : O(n)

