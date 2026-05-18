Intersection of Two Arrays II — LeetCode #350

Given two integer arrays, return an array of their intersection. Each element in the result must appear as many times as it appears in both arrays.
Input:  nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Input:  nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]  (order does not matter)
Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000


Before coding — answer these:

What is the brute force approach?
If both arrays are sorted, how does two pointer help?
When do you move i? When do you move j? When do you add to result?

Answer first. 👊

both the array needs to be sorted to apply 2 pointer approach
we move i when num1[i] < num2[j]
we move j when num2[j] < num1[i]
when both are same we push

////////////////////////////////////////////////////////////
Optimized Approach :
TC : O(nlogn + mlongm)  and SC : O(1)

vector<int>intersectionArray(vector<int>&num1, vector<int>&num2){

    sort(num1.begin(), num1.end());
    sort(num2.begin(), num2.end());

    int m = num1.size();
    int n = num2.size();

    int i=0, j=0;
    
    vector<int>ans;

   while(i<m && j <n){

        if(num1[i] > num2[j]){
            j++;
        }

        else if(num1[i] < num2[j]){
            i++;
        }

        else{
            ans.push_back(num1[i]);
            i++;
            j++;
        }
        
    }
    return ans;
}
