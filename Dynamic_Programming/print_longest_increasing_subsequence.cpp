Get Longest Increasing Subsequence
Solved
Difficulty: MediumAccuracy: 51.81%Submissions: 68K+Points: 4Average Time: 20m
Given an array of integers arr[], return the Longest Increasing Subsequence (LIS) of the given array. LIS is the longest subsequence where each element is strictly greater than the previous one.

If multiple LIS exist, return the one that appears first based on the lexicographical order of indices (i.e., the earliest combination of positions from the original sequence).

Examples:

Input: arr[] = [10, 20, 3, 40]
Output: [10, 20, 40]
Explanation: [10, 20, 40] is the longest subsequence where each number is greater than the previous one, maintaining the original order.


Approach:
TC: O(n^2) and SC : O(n)
class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        int n = arr.size();
        
        //dp array to store the length of LIS ending at each index
        vector<int> dp(n, 1);
        
        //Array to store previous index of LIS
        vector<int>prev(n, -1);
        
        
        //Compute LIS length for each index
        for(int i = 1; i< n; i++){
            for(int j =0; j<i; j++){
                
                if(arr[j] < arr[i] && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }
        
        //find the index of maximum LIS length
        int maxlen =0, maxIndex =0;
        
        for(int i = 0; i < n; i++){
            if(dp[i] > maxlen){
                maxlen = dp[i];
                maxIndex = i;
            }
        }
        
        vector<int> lisSeq;
        int curr = maxIndex;
        
        while(curr != -1){
            lisSeq.push_back(arr[curr]);
            curr = prev[curr];
        }
        
        //reverse sequence 
        reverse(lisSeq.begin(), lisSeq.end());
        
        return lisSeq;
    }
};
