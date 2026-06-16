LEETCODE - 1539. Kth Missing Positive Number
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
Return the kth positive integer that is missing from this array.
Example 1:
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.

BRUTE FORCE :
Time Complexity = O((n + k) × n) and SC : O(1)

int findKthPositive(vector<int>& arr, int k) {

        int count =0;
        int n = arr.size();
        int max = INT_MAX;
        
        for(int i=1; i<=max; i++){
            int flag = false;

            for(int j = 0; j<n; j++){

                if(i == arr[j]){
                    flag = true;
                    break;
                }
            }

            if(flag == false){
                count++;

                if(count == k){
                    return i;
                }
            }
        }
        return -1;
    }


OPTIMIZED APPROACH :  BINARY SEARCH
TC : O(log n) and SC : O(1)

int findKthPositive(vector<int>& arr, int k) {

       int n = arr.size();

       int low = 0;
       int high = n-1;


       while(low <= high){

        int mid = (low + high)/2;

        int missing = arr[mid] - (mid + 1);

        if(missing < k){
            low = mid + 1;
        }

        else{
            high = mid -1;
        }
       }

       return k + high + 1;
    }
