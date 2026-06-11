////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                         **PROBABLY NEEDS TO REVISIT IT, THE SOLUTION WAS EASY BUT THE APPROACH **
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours.

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23
 
Constraints:

1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109

BRUTE FORCE : 
TC : O(n * max(a[])) and SC : O(1)
  
    // Function to calculate total hours for given speed
    int calculateTotalHours(vector<int>& a, int hourly) {
        int totalHours = 0;
        for (int pile : a) {
            // Add hours using ceil
            totalHours += (pile + hourly - 1) / hourly;
        }
        return totalHours;
    }

    // Function to find minimum eating speed
    int minEatingSpeed(vector<int>& a, int h) {
        // Find maximum pile size
        int maxVal = *max_element(a.begin(), a.end());

        // Try every possible speed
        for (int i = 1; i <= maxVal; i++) {
            int hours = calculateTotalHours(a, i);

            // If hours fit within h
            if (hours <= h) {
                return i;
            }
        }
        return maxVal;
    }

OPTIMIZED APPROACH :
TC : O(N*log(max(a[]))) and SC : O(1)
  
int findMax(vector<int>& piles){
        int maxi = INT_MIN;

        for(int i=0; i<piles.size(); i++){

            maxi = max(maxi, piles[i]);
        }

        return maxi;
    }
    long long calculateHrs(vector<int>& piles, int hourly){
        long long totalH = 0;
        int n = piles.size();

        for(int i=0; i<n; i++){
            totalH += ceil((double)piles[i] / (double)hourly);   //finding ceil value to ignore the decimal values like took 1.5 hrs to eat 3 bananas, it will be counted as 2 hrs.
        }

        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int n = piles.size();
        int low = 1;
        int high = findMax(piles);

        int ans = INT_MAX;

        while(low <= high){
            int mid = (low + high)/2;   //mid is the rate at which koko is eating banana ex = mid = bananas/hr

            long long totalHrs = calculateHrs(piles, mid);

            if(totalHrs <= h){
                 ans = mid;
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }

