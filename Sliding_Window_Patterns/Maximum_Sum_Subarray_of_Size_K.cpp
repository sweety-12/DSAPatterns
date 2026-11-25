GFG: Max Sum Subarray of Size K

Given an array of integers arr[]  and a number k. Return the maximum sum of a subarray of size k.

Note: A subarray is a contiguous part of any given array.

Examples:

Input: arr[] = [100, 200, 300, 400], k = 2
Output: 700
Explanation: arr2 + arr3 = 700, which is maximum.
Input: arr[] = [1, 4, 2, 10, 23, 3, 1, 0, 20], k = 4
Output: 39
Explanation: arr1 + arr2 + arr3 + arr4 = 39, which is maximum.
Input: arr[] = [100, 200, 300, 400], k = 1
Output: 400
Explanation: arr3 = 400, which is maximum.
Constraints:

arr.size() ≤ 106
0 ≤ arr[i] ≤ 106
1 ≤ k ≤ arr.size()
Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)

APPROACH: Sliding window Problem

class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int sum =0;
        for(int i=0; i<k; i++){
            sum += arr[i];
        }
        
        int maxWindow = sum;
        for(int i =k; i<arr.size(); i++){
            
            sum += arr[i] - arr[i-k];
            
            maxWindow = max(maxWindow, sum);
        }
        
        return maxWindow;
    }
};
