Find out how many times the array is rotated
Given an integer array nums of size n, sorted in ascending order with distinct values. The array has been right rotated an unknown number of times, between 0 and n-1 (including). Determine the number of rotations performed on the array.
Example 1
Input : nums = [4, 5, 6, 7, 0, 1, 2, 3]
Output: 4
Explanation: The original array should be [0, 1, 2, 3, 4, 5, 6, 7]. So, we can notice that the array has been rotated 4 times.
Example 2
Input: nums = [3, 4, 5, 1, 2]
Output: 3
Explanation: The original array should be [1, 2, 3, 4, 5]. So, we can notice that the array has been rotated 3 times.
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BRUTE FORCE : Simple Linear Search
TC : O(n) and SC : O(1)

 int findKRotation(vector<int> &arr)  {

        int n = arr.size();
        int ans = -1;

        for(int i=0; i<n-1; i++){
            if(nums[i] > nums[i+1]){
                ans = i;
                break;
            }
        }
        return ans+1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
(My solution - My solution finds the largest element and element +1 is the ans)
OPTIMIZED APPROACH :
TC : O(log n) and SC : O(1)

 int findKRotation(vector<int> &arr)  {

        int n = arr.size();

        int low =0;
        int high = n-1;
        int maxVal = INT_MIN;
        int maxInd = -1;

        //edge case if array is not rotated.
        if(arr[0] <= arr[n-1])  return 0;

        while(low <= high){
            int mid = (low + high)/2;

            //find the sorted half
            if(arr[low] <= arr[mid]){   //if true means sorted
                if(arr[mid] > maxVal){
                    maxVal = arr[mid];
                    maxInd = mid;
                }
                
                low = mid +1;
            }
            else{

                if(arr[high] > maxVal){
                    maxVal = arr[high];
                    maxInd = high;
                }
               
                high = mid -1;
            }
        }

        return maxInd + 1;
    }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
(Striver Solution - This solution finds the smallest element and that's the ans)

   int findRotations(vector<int>& arr) {
        // Initialize low and high pointers
        int low = 0;
        int high = arr.size() - 1;

        // Loop until low meets high
        while (low < high) {
            // Find mid index
            int mid = low + (high - low) / 2;

            // If mid element is greater than element at high,
            // smallest element lies to the right of mid
            if (arr[mid] > arr[high]) {
                low = mid + 1;
            } else {
                // Else smallest element is at mid or to the left
                high = mid;
            }
        }

        // When low == high, we found the smallest element
        return low;
    }
