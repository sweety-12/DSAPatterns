SOLVED IN GFG - You are given an array with unique elements of stalls[], which denote the positions of stalls. You are also given an integer k 
which denotes the number of aggressive cows. The task is to assign stalls to k cows such that the minimum distance between any two of them 
is the maximum possible.
Examples:
Input: stalls[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows in this case is 3, which is the largest among all possible ways.

BRUTE FORCE : TC : O(maxi - mini) * O(n) ~ O(n^2) and SC : O(1)
bool canWePlace(vector<int> &stalls, int k, int dist){
        
        int n = stalls.size();
        int countCows =1;
        int last = stalls[0];
        
        for(int i=1; i<n; i++){
            
            if(stalls[i] - last >= dist){
                countCows++;
                last = stalls[i];
            }
        }
        
        if(countCows >= k)  return true;
        
        return false;
        
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int n = stalls.size();
        
        sort(stalls.begin(), stalls.end());
        int maxDist = stalls[n-1] - stalls[0];
        int ans =0;
        
        for(int i=1; i<=maxDist; i++){
            
            bool ifPossible = canWePlace(stalls, k, i);
            
            if(ifPossible == true) {
                ans = i;
            }
        }
        
        return ans;
    }


OPTIMAL APPROACH:
TC : O(log(maxi-mini))* O(n) ~ O(nlogn)
SC : O(1)

 bool canWePlace(vector<int> &stalls, int k, int n, int dist){
        
        int countCows =1;
        int last = stalls[0];
        
        for(int i=1; i<n; i++){
            
            if(stalls[i] - last >= dist){
                countCows++;
                last = stalls[i];
            }
        }
        
        if(countCows >= k)  return true;
        
        return false;
        
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int n = stalls.size();
        
        sort(stalls.begin(), stalls.end());
        
        int low = 1;
        int high = stalls[n-1];
        int ans = -1;
        
        while(low <= high){
            
            int mid = (low + high)/2;
            
            bool ifPossible = canWePlace(stalls, k, n, mid);
            
            if(ifPossible == true){
                ans = mid;
                low = mid + 1;
            }
            
            else{
                high = mid -1;
            }
        }
        
        return ans;
    }
