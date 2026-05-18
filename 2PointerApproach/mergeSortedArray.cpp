Merge Sorted Array — LeetCode #88
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums2 into nums1 as one sorted array in-place.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
Input:  nums1 = [1,2,3,0,0,0], m = 3
        nums2 = [2,5,6],       n = 3
Output: [1,2,2,3,5,6]

Input:  nums1 = [1], m = 1
        nums2 = [], n = 0
Output: [1]

Input:  nums1 = [0], m = 0
        nums2 = [1], n = 1
Output: [1]
Constraints:

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-10⁹ <= nums1[i], nums2[i] <= 10⁹
Must be in-place — O(1) extra space


//////////////////////////////////////////////////////////////////////
BRUTE FORCE :
TC : O((m+n)(log (m+n))) and SC : O(1);

void sortedArray(vector<int> &nums1, vector<int>&nums2, int m, int n){

    int i = m;
    int j =0;

    while(i<nums1.size() && j < nums2.size()){

        nums1[i] = nums2[j];
        i++;
        j++;
    }

    sort(nums1.begin(), nums1.end());
}

//////////////////////////////////////////////////////////////////////
Optimized Approach :
TC : O(m+n) and SC : O(1)

void sortedArray(vector<int>&num1, vector<int>&num2, int m, int n){
    int i = m-1;
    int j = n-1;
    int k = m+n-1;   // if i am considering num1 contains exactly n extra space in it, then k = num1.size()-1;
    
    while( i >=0 && j >= 0){

        if(num1[i] >= num2[j]){
            num1[k] = num1[i];
            k--;
            i--;
        }
        else{
            num1[k] = num2[j];
            k--;
            j--;
        }
    }
    //if i exhausts then we will simply copy all the j elements to num1
    //here i am expecting k will not go beyond 0 coz i am traversing exactly m+n-1 no of elements;
    while( j >= 0){
        num1[k] = num2[j];
        j--;
        k--;
    }
}
