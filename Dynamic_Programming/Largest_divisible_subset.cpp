//HAVEN'T PRACTISED THIS QUESTION BUT THIS IS EXACTLY SAME TO LIS, WE CHECK GREATER THAN IN LIS HERE WE HAVE TO CHECK BY DIVIDING THE CURRENT ELEMENT BY THE PREV ELEMENT IN STORED DP THAT'S IT.

368. Largest Divisible Subset: Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]

APPROACH:
TC: O(n^2) and SC : O(n)

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        vector<int>ans;
        vector<int>dp(n, 1); //DP array
        vector<int> parent(n); //Array to keep record of the parent

        //to store thr index of last element in the LDS
        int lastIndex =0;

        //to store the lenth of LDS
        int maxlen =0;

        for(int i=0; i<n; i++){
            parent[i] =i;


            for(int prevInd =0; prevInd <i; prevInd++){

                if(nums[i] % nums[prevInd] == 0 && dp[i] < dp[prevInd] + 1){

                    dp[i] = dp[prevInd] + 1;
                    parent[i] = prevInd;               
                 }
            }

            if(dp[i] > maxlen){
            lastIndex = i;
            maxlen = dp[i];
            }
        }

        //Backtracking
        int i = lastIndex;


        //Until we reach  an index which is its own parent
        while(parent[i] != i){
            ans.push_back(nums[i]); //Add the element at current index
            i = parent[i]; 
        }

        ans.push_back(nums[i]);

        return ans;
    }
};
