Problem — Two Sum II (Pattern 1: Opposite Ends)
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number.
Return the indices of the two numbers as an integer array [index1, index2] where 1 <= index1 < index2 <= numbers.length.
You must use only constant extra space.
Example 1:
Input:  numbers = [2, 7, 11, 15], target = 9
Output: [1, 2]
Explanation: numbers[0] + numbers[1] = 2 + 7 = 9

Example 2:
Input:  numbers = [2, 3, 4], target = 6
Output: [1, 3]

Example 3:
Input:  numbers = [-1, 0], target = -1
Output: [1, 2]
Constraints:

2 <= numbers.length <= 3 * 10⁴
-1000 <= numbers[i] <= 1000
numbers is sorted in non-decreasing order
Exactly one solution exists


Brute force : This can be easily solved by using nested loop but it is going to take TC : O(n2) so we will move to optimized appraoch

Optimized Approach

vector<int>twoSum(vector<int>&nums, int target){

    //EDGE CASE 
    if(nums.empty()) return {};

    int left =0;
    int right = nums.size()-1;
    int sum =0;

    while(left < right){

        sum = nums[left]+ nums[right];

        if(sum > target){
            right--;
        }

        else if(sum < target){
            left++;
        }

        else if(sum == target){
            return {left +1 , right + 1};
        }
    }

    return {};
}