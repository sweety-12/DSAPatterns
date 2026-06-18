////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                              ***EXTREMELY HARD PROBLEM - NEED TO REVISIT THIS QUESTION***
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Minimize Max Distance to Gas Station. We have a horizontal number line. On that number line, we have gas stations at positions stations[0], stations[1], ..., stations[n-1]. Now, we add k more gas stations so that d, the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of d. Find the answer exactly to 6 decimal places.
Note: stations is in a strictly increasing order.
Examples:
Input: stations[] = [1, 2, 3, 4, 5], k = 2
Output: 1.00
Explanation: Since all gaps are already equal (1 unit each), adding extra stations in between does not reduce the maximum distance.
Input: stations[] = [3, 6, 12, 19, 33], k = 3
Output: 6.00 
Explanation: The largest gap is 14 (between 19 and 33). Adding 2 stations there splits it into approx 4.67. The next largest gap is 7 (between 12 and 19). Adding 1 station splits it into 3.5. Now the maximum gap left is 6.
Constraint:
1 ≤ stations.size() ≤ 10^5
0 ≤ stations[i] ≤ 10^6
0 ≤ k ≤ 10^5

 BRUTE FORCE :
  TC : O(k*n) + O(n) and SC : O(1)

  class Solution {
  public:
    double minMaxDist(vector<int> &stations, int k) {
        // Code here
        int n = stations.size();
        vector<int> howMany(n-1, 0);
        
        for(int gasStations=1; gasStations<= k ; gasStations++){
            
            double maxSection = -1;
            int maxInd = -1;
            
            for(int i=0; i<n-1; i++){
            
             double diff = (stations[i+1] - stations[i]);
             double sectionLength = diff/(double)(howMany[i] + 1);
            
            if(sectionLength > maxSection){
                maxSection = sectionLength;
                maxInd = i;
             }
            
            }
        
            howMany[maxInd]++;
        }
     
          double maxAns = -1;
         
         for(int i=0; i<n-1; i++){
             
              double diff = (stations[i+1] - stations[i]);
              double sectionLength = diff / ( double)( howMany[i] + 1);
             maxAns = max(maxAns, sectionLength);
             
         }
         
        return maxAns;
    }
};

BETTER APPROACH : INTERVIEWERS WILL BE SATISFIED TILL HERE.
TC : O(nlogn + klogn) and SC :  O(n-1)+O(n-1)

 long double minimiseMaxDistance(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> howMany(n - 1, 0); // Tracks how many stations in each segment
        priority_queue<pair<long double, int>> pq; // Max-heap

        // Initially insert all segments into the heap with their lengths
        for (int i = 0; i < n - 1; i++) {
            long double length = arr[i + 1] - arr[i];
            pq.push({length, i});
        }

        // Place k additional gas stations
        for (int gasStations = 1; gasStations <= k; gasStations++) {
            auto top = pq.top();
            pq.pop();
            int segmentIndex = top.second;

            // Add a station to the segment and recompute its length
            howMany[segmentIndex]++;
            long double totalDist = arr[segmentIndex + 1] - arr[segmentIndex];
            long double newLen = totalDist / (howMany[segmentIndex] + 1);
            pq.push({newLen, segmentIndex});
        }

        // Final answer is the max segment length at the top of the heap
        return pq.top().first;
    }

OPTIMIZED APPROACH : BINARY SEARCH
TC : O(n*log(Len)) + O(n) And SC : O(1)
int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
        int n = arr.size();
        int cnt = 0;

        for (int i = 1; i < n; i++) {
            // Number of stations needed between arr[i-1] and arr[i]
            int numberInBetween = (arr[i] - arr[i - 1]) / dist;

            // If perfectly divisible, reduce one to avoid extra placement
            if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
                numberInBetween--;
            }
            cnt += numberInBetween;
        }
        return cnt;
    }

    // Function to minimize the maximum distance between gas stations
    long double minimiseMaxDistance(vector<int> &arr, int k) {
        int n = arr.size();
        long double low = 0, high = 0;

        // Determine max initial distance between stations
        for (int i = 0; i < n - 1; i++) {
            high = max(high, (long double)(arr[i + 1] - arr[i]));
        }

        long double diff = 1e-6;

        // Binary search to find minimum possible maximum distance
        while (high - low > diff) {
            long double mid = (low + high) / 2.0;
            int cnt = numberOfGasStationsRequired(mid, arr);
            if (cnt > k) low = mid;
            else high = mid;
        }

        return high;
    }



