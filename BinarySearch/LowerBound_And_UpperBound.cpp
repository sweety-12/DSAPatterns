Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the lower bound of x.

What is lower bound?
The lower bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.

The lower bound is the smallest index, ind, where arr[ind] >= x. But if any such index is not found, the lower bound algorithm returns n i.e. size of the given array.

Examples
Example 1:
Input Format: N = 4, arr[] = {1,2,2,3}, x = 2
Result: 1
Explanation: Index 1 is the smallest index such that arr[1] >= x.

Example 2:
Input Format: N = 5, arr[] = {3,5,8,15,19}, x = 9
Result: 3
Explanation: Index 3 is the smallest index such that arr[3] >= x.


Brute Force Approach :
TC : O(n) and SC : O(1)

int lowerBound(vector<int> arr, int n, int x) {
        // Traverse the array
        for (int i = 0; i < n; i++) {
            // If current element is greater than or equal to x
            if (arr[i] >= x) {
                return i;  // Return index of the first such element
            }
        }
        // If all elements are smaller than x
        return n;
    }

OPTIMIZED APPROACH : This can be solved by a simple binary search algorithm.
TC : O(log n) and SC : O(1)

 int lowerBound(vector<int> arr, int n, int x) {
        int low = 0;           
        int high = n - 1;      
        int ans = n;           // Default to n (not found)

        // Binary search loop
        while (low <= high) {
            int mid = (low + high) / 2;  

            if (arr[mid] >= x) {
                ans = mid;           
                high = mid - 1;      
            } else {
                low = mid + 1;       
            }
        }
        return ans;  
    }


INBUILT FUNCTIONS FOR LOWER BOUND AND UPPER BOUND WHICH CAN BE DIRECTLY USED IN CODING ROUNDS OR IF ASKED IN INTERVIEWS.

int lb = lower_bound(arr.begin(), arr.end(), n) - arr.begin();

int ub = upper_bound(arr.begin(), arr.end(), n) - arr.begin();
            
