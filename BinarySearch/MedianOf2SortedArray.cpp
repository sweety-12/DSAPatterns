LEETCODE 4. Median of Two Sorted Arrays. Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).
Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

BRUTE FORCE:
TC : O((m+n)log(m+n) and SC : O(1)

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

     int m = nums1.size();
     int n = nums2.size();
     vector<int>vec;

     for(int i=0; i<m; i++){
        vec.push_back(nums1[i]);
     }

     for(int i=0; i<n; i++){
        vec.push_back(nums2[i]);
     }

     sort(vec.begin(), vec.end());
     double median;
     if((m+n) % 2 == 0){
        int mid = (0+m+n-1)/2;
        median = (vec[mid] + vec[mid+1])/2.0;
     }
     else{
        int mid = (0+m+n-1)/2;
        median = vec[mid];
     }

    return median; 
}

BETTER APPROACH:   REMOVING SPACE COMPLEXITY
TC: O(m+n) and SC : O(1)
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0, m1 = 0, m2 = 0;

        // Find median.
        for (int count = 0; count <= (n + m) / 2; count++) {   //WE CAN ALSO USE WHILE LOOP HERE
            m2 = m1;
            if (i != n && j != m) {
                if (nums1[i] > nums2[j]) {
                    m1 = nums2[j++];
                } else {
                    m1 = nums1[i++];
                }
            } else if (i < n) {
                m1 = nums1[i++];
            } else {
                m1 = nums2[j++];
            }
        }

        // Check if the sum of n and m is odd.
        if ((n + m) % 2 == 1) {
            return (double)(m1);
        } else {
            double ans =  (double)(m1) +  (double)(m2);
            return ans / 2.0;
        }
  }
OPTIMIZED APPROACH : 
TC : O(min(logn1, logn2)) and SC : O(1)

//SOMETIMES YOU FEEL YOU HAVE REACHED THE THRESHOLD OF YOUR BRAIN CAPACITY, THIS IS THE QUESTION.

class Solution {
public:
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    int n1 = nums1.size();
    int n2 = nums2.size();

    if(n1 > n2)  return findMedianSortedArrays(nums2, nums1); // i want to perform BINARY SEARCH on smaller array

    int low = 0, high = n1;
    int left = (n1 + n2 + 1)/2;
    int n = n1 + n2;

    while( low <= high){

        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if(mid1 < n1) r1 = nums1[mid1];
        if(mid2 < n2) r2 = nums2[mid2];

        if(mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
        if(mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

        if(l1 <= r2 && l2 <= r1){
            if(n % 2 == 1)  return max(l1, l2);
            return ((double)(max(l1, l2) + min(r1, r2)))/2.0;
        }

        else if(l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }

    return 0;
  }

};
