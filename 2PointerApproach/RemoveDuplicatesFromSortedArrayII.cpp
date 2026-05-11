Remove Duplicates from Sorted Array II
Difficulty: Medium
Pattern: P2a — Read/Write pointers

Problem
Given an integer array nums sorted in non-decreasing order, remove duplicates in-place such that each unique element appears at most twice.
Return k — the number of elements remaining.

Examples
Example 1:
Input:  nums = [1,1,1,2,2,3]
Output: k = 5, nums = [1,1,2,2,3,_]
Example 2:
Input:  nums = [0,0,1,1,1,1,2,3,3]
Output: k = 7, nums = [0,0,1,1,2,3,3,_,_]

Constraints

1 <= nums.length <= 3 * 10⁴
-104 <= nums[i] <= 10⁴
nums is sorted in non-decreasing order


/////////////////////////////////////////////////
 int removeDuplicates(vector<int>& nums) {

        //EDGE CASE
        if(nums.size() < 3){
            return nums.size();
        }
       
       int k =2;

       for(int i=2; i<nums.size(); i++){

        if(nums[i] != nums[k-2]){
            nums[k] = nums[i];
            k++;
        }
       }

       return k;
    }
