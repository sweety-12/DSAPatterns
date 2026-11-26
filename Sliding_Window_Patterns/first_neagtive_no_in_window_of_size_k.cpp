First Negative in Windows of Size K

Given an array arr[]  and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

Note: If a window does not contain a negative integer, then return 0 for that window.

Examples:

Input: arr[] = [-8, 2, 3, -6, 10] , k = 2
Output: [-8, 0, -6, -6]
Explanation:
Window [-8, 2] First negative integer is -8.
Window [2, 3] No negative integers, output is 0.
Window [-6, 10] First negative integer is -6.

Approach : Brute Force
TC: O (n*n) and SC: O(n)

class Solution {
public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        queue<int> q;

        int i = 0;
        int n = arr.size();

        while (i < n - k + 1) {
            int l = k - 1 + i;
            int j = i;
            int flag = 1;

            while (j <= l && l < n) {
                if (arr[j] < 0) {
                    q.push(arr[j]);
                    flag = 0;
                    break;
                }
                j++;
            }

            if (flag == 1) q.push(0);

            i++;
        }

        vector<int> ans;

        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};

************************ OPTIMIZED APPROACH SAMJH NHI AYA HAI ***********************
OPTIMIZED APPROACH: Sliding window
TC: O(n) AND SC: O(n)

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // code here
        queue<int>q;
        vector<int>vec;
        
        for(int i =0;i< arr.size(); i++){
            if(arr[i] < 0){
                q.push(i);  //push only the index into q;
            }
            
            while(!q.empty() && q.front() <= i-k){
                q.pop();
            }
            
            if(i >= k-1){
                if(!q.empty()){
                    vec.push_back(arr[q.front()]);
                }
                else{
                    vec.push_back(0);
                }
            }
        }
        
        return vec;
        
    }
};
