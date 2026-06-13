Minimum days to make M bouquets
Given n roses and an array nums where nums[i] denotes that the 'ith' rose will bloom on the nums[i]th day, only adjacent bloomed roses can be picked to make a bouquet. Exactly k adjacent bloomed roses are required to make a single bouquet. Find the minimum number of days required to make at least m bouquets, each containing k roses. Return -1 if it is not possible.
Example 1
Input: n = 8, nums = [7, 7, 7, 7, 13, 11, 12, 7], m = 2, k = 3
Output: 12
Explanation: On the 12th the first 4 flowers and the last 3 flowers would have already bloomed. So, we can easily make 2 bouquets, one with the first 3 and another with the last 3 flowers.
Example 2
Input: n = 5, nums = [1, 10, 3, 10, 2], m = 3, k = 2
Output: -1
Explanation: If we want to make 3 bouquets of 2 flowers each, we need at least 6 flowers. But we are given only 5 flowers, so, we cannot make the bouquets.

OPTIMIZED APPROACH :
TC : O(log(maxi- min+1) * O(n)   and SC = O(1)

int check(vector<int>& bloomDay, int m, int k, int n, int day){

        int count =0;
        int ans =0;

        for(int i=0; i<n; i++){
            if(bloomDay[i] <= day){
                count++;
            }
            else{
                  ans += count/k;
                  count=0;
                }
        }
        ans += count/k;
        return ans;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {

        int n = bloomDay.size();

        int mini = INT_MAX, maxi = INT_MIN;

        for(int i=0; i<n; i++){
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }

        int low = mini;
        int high = maxi;
        int ans = -1;

        //edge case
        if((long long)m*k > n)  return -1;  //not enough flowers

        while( low <= high){

            int mid = (low + high)/2;

            int ifPossible = check(bloomDay, m, k, n, mid);

            if(ifPossible >= m){

                ans = mid;
                high = mid -1;
            }

            else{
                low = mid + 1;
            }
        }

        return ans;
    }
