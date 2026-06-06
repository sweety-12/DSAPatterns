////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                          ** MUST TAKE CARE OF THE EDGE CASE IN OPTMIZED APPROACH**
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Search in rotated sorted array-II
Given an integer array nums, sorted in ascending order (may contain duplicate values) and a target value k. Now the array is rotated at some pivot point unknown to you. Return True if k is present and otherwise, return False.
Example 1
Input : nums = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 3
Output: True
Explanation: The element 3 is present in the array. So, the answer is True.
Example 2
Input : nums = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 10
Output: False
Explanation:The element 10 is not present in the array. So, the answer is False.

BRUTE FORCE : Simply a linear search
TC : O(n) and SC : O(1)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

OPTIMIZED ARRPOACH :
TC : O(log n) and SC : O(1)

bool search(vector<int>& arr, int target) {

        int n = arr.size();
        int low = 0;
        int high = n-1;

        while(low <= high){

            int mid = (low + high)/2;

            //If ans found
            if(arr[mid] == target){
                return true;
            }

            //EDGE CASE IF ALL THREE ARE SAME
            if(arr[low] == arr[mid] && arr[mid] == arr[high]){
                low++;
                high--;
                continue;
            }

            //Find sorted half

            if(arr[low] <= arr[mid]){
                if(arr[low] <= target && target <= arr[mid]){
                    high = mid -1;
                }
                else{
                    low = mid + 1;
                }
            }
            else{
                if(arr[mid] <= target && target <= arr[high]){
                    low = mid + 1;
                }
                else {
                    high = mid -1;
                }
            }
        }
        return false;
    }
};
