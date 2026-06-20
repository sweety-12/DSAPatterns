GFG: kth element of 2 sorted arrays
Given two sorted arrays a and b of size m and n respectively. Find the kth element of the final sorted array.
Example 1
Input: a = [2, 3, 6, 7, 9], b = [1, 4, 8, 10], k = 5
Output: 6
Explanation: The final sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.
Example 2
Input: a = [100, 112, 256, 349, 770], b = [72, 86, 113, 119, 265, 445, 892], k = 7
Output: 256
Explanation: Final sorted array is - [72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892], 7th element of this array is 256.

BRUTE FORCE: MERGE BOTH ARRAY -> SORT -> RETURN K-1;
TC : O((m+n)log(m+n)) and SC O(m+n)

int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int size = n+m;
        int ans[size];
        int x =0;
        for(int i=0;i<n; i++){
            ans[x++] = arr1[i];
        }
        for(int i =0; i<m; i++){
            ans[x++] = arr2[i];
        }
        
        sort(ans, ans+size);
        
        return ans[k-1];
        
    }

BETTER APPROACH : TWO POINTER APPROACH
TC : O(max(n, m)) and SC :o(1)

 int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int left =0;
        int right = 0;
        
        int n = a.size();
        int m = b.size();
        
        //edge case
        if(m+n < k)  return -1;
        
        int kthPointer = -1;
        
        while(left <n && right<m && k >0){
            
            // if(k == 0)  return kthPointer;
            
            if(a[left] <= b[right]){
                k--;
                kthPointer = a[left];
                left++;
            }
            else{
                k--;
                kthPointer = b[right];
                right++;
            }
        }
        
        while(left < n && k>0){
            k--;
            kthPointer = a[left];
            left++;
        }
        
        while(right < m && k >0){
            k--;
            kthPointer = b[right];
            right++;
        }
        
        return kthPointer;
    }

OPTIMIZED APPROACH : USING BINARY SEARCH 
//THIS IS THE EXACT SAME SOLUTION OF MEDIAN OF TWO SORTED ARRAY, I AM NOT ABLE TO UNDERSTAND THE APPROACH VERY CLREALY,
//NEED TO PRACTICE THIS APPROACH MORE.

TC : O(log(min(a, b))) and SC : O(1)

class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
       int n1 = a.size();
       int n2 = b.size();
       
       if(n1 > n2 ) return kthElement(b, a, k);
       
       int low = max(k - n2, 0);
       int high = min(k, n1);
       
       int left =k;
       int n = n1+ n2;
       
       while(low <= high){
           
           int mid1 = (low + high)/2;
           int mid2 = k - mid1;
           
           int l1 = INT_MIN, l2 = INT_MIN;
           int r1 = INT_MAX, r2 = INT_MAX;
           
           if(mid1 < n1)  r1 = a[mid1];
           if(mid2 < n2)  r2 = b[mid2];
           
           if(mid1 -1 >= 0) l1 = a[mid1 - 1];
           if(mid2 -1 >= 0) l2 = b[mid2 - 1];
           
           if(l1 <= r2 && l2 <= r1){
               
               return max(l1, l2);
           }
           else if(l1 > r2) high = mid1 -1;
           else low = mid1 + 1;
           
       }
       return 0;
    }
};
