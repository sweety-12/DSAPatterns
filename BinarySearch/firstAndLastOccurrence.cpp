LEETCODE 34 : Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]

BRUTE FORCE :
TC : O(n) and SC : O(1)

vector<int> searchRange(vector<int>& nums, int target) {

        int n = nums.size();
        int first = -1;
        int last = -1;
        //first occurence

        for(int i=0; i<n; i++){
            if(nums[i] == target){
                first = i;
                break;
            }
        }

        for(int i=n-1; i>=0; i--){
            if(nums[i] == target){
                last = i;
                break;
            }
        }
        
        return {first, last};
    }

OPTMIZED APPROACH :
TC : O(log n) and SC : O(1)


    vector<int> searchRange(vector<int>& nums, int target) {

        int n = nums.size();
        int first = -1;
        int last = -1;

        int low = 0;
        int high = n-1;
        
        //first occurrence
        while(low <= high){
            int mid = (low + high) /2;

            if(nums[mid] == target){
                first = mid;
                high = mid -1;   //Keep searching left
                
            }
            else if(nums[mid] < target){
            
                low = mid +1;
            }

            else{
                high = mid -1;
            }


        }
        low =0;
        high = n -1;
         //last occurrence
        while(low <= high){
            int mid = (low + high) /2;
            if(nums[mid] == target) {
                last = mid;
                low = mid +1;
            }
            else if(nums[mid] > target){
                high = mid -1;
                
            }

            else{
               low = mid +1;
            }


        }

        return {first, last};
    }
