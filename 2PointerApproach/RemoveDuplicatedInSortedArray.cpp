26. Remove Duplicates from Sorted Array
Difficulty: Easy
Pattern: P2a — Read/Write pointers

Problem
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once.
The relative order must be kept the same. Return k — the number of unique elements.
Do not allocate extra space. You must do this with O(1) extra memory.

Examples
Example 1:
Input:  nums = [1,1,2]
Output: k = 2, nums = [1,2,_]
Example 2:
Input:  nums = [0,0,1,1,1,2,2,3,3,4]
Output: k = 5, nums = [0,1,2,3,4,_,_,_,_,_]

Constraints

1 <= nums.length <= 3 * 10⁴
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order

int removeDuplicates(vector<int>&nums){

    int k =1;

    for(int i=1; i<nums.size(); i++){

       if(nums[i] != nums[k-1]){
        nums[k] = nums[i];
        k++
       }

    }

    return k;
}

TC : O(n) and SC : O(1)
