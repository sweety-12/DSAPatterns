LEETCODE 162. Find Peak Element - A peak element is an element that is strictly greater than its neighbors.
Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
You must write an algorithm that runs in O(log n) time.
Example 1:
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.

BRUTE FORCE : Simple Linear search (must take care of the edge cases) 
TC : O(n) and SC : O(1)

int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        //edge cases
        //THESE EDGE CASES ARE VERY IMPORTANT, REMEMBER THESE AS THEY ARE GOING TO THE USED IN MANY QUESTIONS.
        if(n == 1)   return 0;
        if(nums[0] > nums[1])  return 0;
        if(nums[n-1] > nums[n-2])   return n-1;


        for(int i=1; i<n-1; i++){
            if(nums[i-1] < nums[i] && nums[i] > nums[i+1]){
                return i;
            }
        }

        return -1;
}

OPTIMIZED APPROACH :
TC : O(log n) and SC : O(1)

 int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        //edge cases
        //THESE EDGE CASES ARE VERY IMPORTANT, REMEMBER THESE AS THEY ARE GOING TO THE USED IN MANY QUESTIONS.
        if(n == 1)   return 0;
        if(nums[0] > nums[1])  return 0;
        if(nums[n-1] > nums[n-2])   return n-1;

        int low = 1;
        int high = n-2;

        while(low <= high){

            int mid = (low + high)/2;

            //if found the ans
            if(nums[mid -1] < nums[mid] && nums[mid] > nums[mid+1]){
                return mid;
            } 

            if(nums[mid - 1] > nums[mid]){   //ans lies int the first half

                high = mid -1;

            }

            else{
                low = mid + 1;    //ans lies in the 2nd half
            }
        }

        return -1;
    }
