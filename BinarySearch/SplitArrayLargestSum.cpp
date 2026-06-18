LEETCODE 410. Split Array Largest Sum
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
Return the minimized largest sum of the split.
A subarray is a contiguous part of the array.
Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.

BRUTE FORCE:
TC : O(n) + O(maxi-mini)*O(n)  and sc : O(1)

 bool largestSum(vector<int>&nums, int k, int minSum){
        int sum =0;
        int countSplit = 1;

        for(int i =0; i<nums.size(); i++){

            if(nums[i] + sum <= minSum){
                sum += nums[i];
            }
            else{
                countSplit++;
                sum = nums[i];
            }
        }

        if(countSplit <= k)  return true;

        return false;
    }
    int splitArray(vector<int>& nums, int k) {

        int n = nums.size();
        int mini = INT_MIN;
        int maxi = 0;

        for(int i=0; i<n; i++){
            mini = max(mini, nums[i]);
            maxi += nums[i];
        }

        int low = mini;
        int high = maxi;
        int ans = -1;

        for(int i=low ; i<=high ; i++){

            bool isPossible = largestSum(nums, k, i);

            if(isPossible == true)  {
                return i;
            }
        }

        return ans;

    }

OPTIMIZED APPROACH :
TC :  O(n) + O(maxi-mini)*O(n) and SC : O(1)

bool largestSum(vector<int>&nums, int k, int minSum){
        int sum =0;
        int countSplit = 1;

        for(int i =0; i<nums.size(); i++){

            if(nums[i] + sum <= minSum){
                sum += nums[i];
            }
            else{
                countSplit++;
                sum = nums[i];
            }
        }

        if(countSplit <= k)  return true;

        return false;
    }
    int splitArray(vector<int>& nums, int k) {

        int n = nums.size();
        int mini = INT_MIN;
        int maxi = 0;

        for(int i=0; i<n; i++){
            mini = max(mini, nums[i]);
            maxi += nums[i];
        }

        int low = mini;
        int high = maxi;
        int ans = -1;

        while(low <= high){

            int mid = (low + high)/2;

            bool isPossible = largestSum(nums, k, mid);

            if(isPossible == true)  {
                ans = mid;
                high = mid -1;
            }
            else{
                low = mid + 1;
            }

        }
        return ans;  
    }
 
