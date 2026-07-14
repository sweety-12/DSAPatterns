Solved in GFG - Ninja's training
A ninja has planned a n-day training schedule. Each day he has to perform one of three activities - running, stealth training, or fighting practice. The same activity cannot be done on two consecutive days and the ninja earns a specific number of merit points, based on the activity and the given day.
Given a n x 3-sized matrix, where matrix[i][0], matrix[i][1], and matrix[i][2], represent the merit points associated with running, stealth and fighting practice, on the (i+1)th day respectively. Return the maximum possible merit points that the ninja can earn.
Example 1

Input: matrix = [[10, 40, 70], [20, 50, 80], [30, 60, 90]]

Output: 210

Explanation:

Day 1: fighting practice = 70

Day 2: stealth training = 50

Day 3: fighting practice = 90

Total = 70 + 50 + 90 = 210

This gives the optimal points.

Example 2

Input: matrix = [[70, 40, 10], [180, 20, 5], [200, 60, 30]]

Output: 290

Explanation:

Day 1: running = 70

Day 2: stealth training = 20

Day 3: running = 200
This gives the optimal points.



RECURSIVE APPROACH:
  TC : O(2^n) and SC : O(n)

class Solution {
  public:
    int recursive_func(int day, int last, vector<vector<int>>&mat){
        
        //base case
        if(day == 0){
            
            int maxi =0;
            
            for(int task =0; task <3; task++){
                
                if(task != last){
                    
                    maxi = max( mat[day][task], maxi);
                }
            }
            
            return maxi;
        }
        
        //Do all possible stuffs on that index
        int maxi =0;
        
        for(int task =0; task <3; task++){
            
            if(task != last){
                
                int point = mat[day][task] + recursive_func(day-1, task, mat);
                
                //Find maxi according to the question
                maxi = max(point, maxi);
            }
        }
        
        return maxi;
        
    }
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        
        //convert the question in terms of index
        int n = mat.size();
        
        return recursive_func(n-1, 3, mat);
        
    }
};


MEMOIZATION APPROACH:
TC : O(n*4*3) and SC : O(n) + O(n*4) 


class Solution {
  public:
    int recursive_func(int day, int last, vector<vector<int>>&mat, vector<vector<int>>&dp){
        
        //base case
        if(day == 0){
            
            int maxi =0;
            
            for(int task =0; task <3; task++){
                
                if(task != last){
                    
                    maxi = max( mat[day][task], maxi);
                }
            }
            
            return dp[day][last] = maxi;
        }
        
        
        //sub problem found
        if(dp[day][last] != -1)   return dp[day][last];
        
        
        //Do all possible stuffs on that index
        int maxi =0;
        
        for(int task =0; task <3; task++){
            
            if(task != last){
                
                int point = mat[day][task] + recursive_func(day-1, task, mat, dp);
                
                //Find maxi according to the question
                maxi = max(point, maxi);
            }
        }
        
        return dp[day][last] = maxi;
        
    }
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        
        //convert the question in terms of index
        int n = mat.size();
        
        //Memoization
       vector<vector<int>>dp(n, vector<int>(4, -1));
        
        return recursive_func(n-1, 3, mat, dp);
        
    }
};


TABULATION APPROACH :
TC : O(n*4*3) and SC : O(n*4)

class Solution {
  public:
   
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        
        //convert the question in terms of index
        int n = mat.size();
        
        //Memoization
       vector<vector<int>>dp(n, vector<int>(4, 0));
        
       dp[0][0] = max(mat[0][1], mat[0][2]);
       dp[0][1] = max(mat[0][0], mat[0][2]);
       dp[0][2] = max(mat[0][0], mat[0][1]);
       dp[0][3] = max(mat[0][0], max(mat[0][1], mat[0][2]));
       
       for(int day =1; day <n; day++){
           for(int last =0; last<4; last++){
               for(int task = 0; task<3; task++){
                   
                   if(task != last){
                       int activity = mat[day][task] + dp[day-1][task];
                       
                       dp[day][last] = max(dp[day][last], activity);
                   }
               }
           }
       }
       
        return dp[n-1][3];
    }
};

SPACE OPTIMIZATION APPROACH:
TC: O(n*4*3) and SC : O(1)

class Solution {
  public:
   
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        
        //convert the question in terms of index
        int n = mat.size();
        
        //Memoization
       vector<int>prev(4, 0);
        
       prev[0] = max(mat[0][1], mat[0][2]);
       prev[1] = max(mat[0][0], mat[0][2]);
       prev[2] = max(mat[0][0], mat[0][1]);
       prev[3] = max(mat[0][0], max(mat[0][1], mat[0][2]));
       
       for(int day =1; day <n; day++){
           
           vector<int>temp(4, 0);
           
           for(int last =0; last<4; last++){
               
               for(int task = 0; task<3; task++){
                   
                   if(task != last){
                       int activity = mat[day][task] + prev[task];
                       
                       temp[last] = max(temp[last], activity);
                   }
               }
           }
           
           prev = temp;
       }
       
        return prev[3];
    }
};

