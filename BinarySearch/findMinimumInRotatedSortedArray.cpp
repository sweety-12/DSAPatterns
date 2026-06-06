Find minimum in Rotated Sorted Array
Given an integer array nums of size N, sorted in ascending order with distinct values, and then rotated an unknown number of times (between 1 and N), find the minimum element in the array.
Example 1
Input : nums = [4, 5, 6, 7, 0, 1, 2, 3]
Output: 0
Explanation: Here, the element 0 is the minimum element in the array.
Example 2
Input : nums = [3, 4, 5, 1, 2]
Output: 1
Explanation:Here, the element 1 is the minimum element in the array.

////////////////////////////////////////////////////////////

BRUTE FORCE : Simply search by linear search
tc : O(n) and SC : O(1)
  
////////////////////////////////////////////////////////////

OPTIMIZED APPROACH :
TC : O(log n) and SC : O(1)

 int findMin(vector<int>& arr) {

        int n = arr.size();
        int low = 0;
        int high = n-1;

        int ans  = INT_MAX;
        

        while(low <= high){

            int mid = (low + high)/2;

            if(arr[low] <= arr[mid] ){
                ans = min(ans, arr[low]);

                low = mid + 1;
            }
            else{
                ans = min(ans, arr[mid]);

                high = mid -1;
            }    
        }

       return ans;
    }

