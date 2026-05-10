Problem 6 — Squaring a Sorted Array
LeetCode #977
Given an array of integers sorted in non-decreasing order, return an array of the squares of each number, also in non-decreasing order.
Input:  nums = [-4, -1, 0, 3, 10]
Output: [0, 1, 9, 16, 100]

Input:  nums = [-7, -3, 2, 3, 11]
Output: [4, 9, 9, 49, 121]
Constraints:

1 <= nums.length <= 10⁴
-10⁴ <= nums[i] <= 10⁴
nums is sorted in non-decreasing order

We can solve this using brute force in TC : O(n long n)
  
BRUTE FORCE :
  
vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            nums[i] = nums[i]*nums[i];
        }

        sort(nums.begin(), nums.end());

        return nums;
}

OPTIMIZED :
vector<int>squaringSorted(vector<int>&nums){
        int n = nums.size();
        int left =0;
        int right = n-1;
        vector<int>result(n);
        int pos = n-1;

        while(left <= right){

            if(abs(nums[left]) >= abs(nums[right])){
                result[pos] = nums[left] * nums[left];
                pos--;
                left++;
            }
            else {
                result[pos] = nums[right] * nums[right];
                pos--;
                right--;
            }
        }

        return result;
 }

TC : O(n) , SC : O(1) avoiding the output array.
