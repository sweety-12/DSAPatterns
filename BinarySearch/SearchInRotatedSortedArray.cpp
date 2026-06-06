Given an integer array nums, sorted in ascending order (with distinct values) and a target value k. The array is rotated at some pivot point that is unknown. Find the index at which k is present and if k is not present return -1.
Example 1
Input : nums = [4, 5, 6, 7, 0, 1, 2], k = 0
Output: 4
Explanation: Here, the target is 0. We can see that 0 is present in the given rotated sorted array, nums. Thus, we get output as 4, which is the index at which 0 is present in the array.
Example 2
Input: nums = [4, 5, 6, 7, 0, 1, 2], k = 3
Output: -1
Explanation: Here, the target is 3. Since 3 is not present in the given rotated sorted array. Thus, we get the output as -1.

 BRUTE FORCE : Simply do a linear search and return the elements index
  TC : O(n) and SC : o(1)
////////////////////////////////////////////////////////////

OPTIMIZED APPROACH :
TC : O(log n) and SC : O(1)

int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low <= high){

            int mid = (low + high) / 2;

            //if found
            if(nums[mid] == target)  return mid;

            //find the sorted half;
            if(nums[low] <= nums[mid]){   //if the first half is sorted

                if(nums[low] <= target && target <= nums[mid]){
                    high = mid -1;

                }
                else{
                    low = mid +1;
                }
            }
            else{

                if(nums[mid] <= target && target <= nums[high]){
                    low = mid +1;
                }
                else{
                    high = mid -1;
                }
            }
        }

        return -1;
    }
