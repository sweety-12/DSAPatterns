Given a sorted array nums and an integer x. Find the floor and ceil of x in nums. The floor of x is the largest element 
in the array which is smaller than or equal to x. The ceiling of x is the smallest element in the array greater
than or equal to x. If no floor or ceil exists, output -1.
  
Example 1
Input : nums =[3, 4, 4, 7, 8, 10], x= 5
Output: 4 7
Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.
Example 2
Input : nums =[3, 4, 4, 7, 8, 10], x= 8
Output: 8 8
Explanation: The floor of 8 in the array is 8, and the ceiling of 8 in the array is also 8.
  
////////////////////////////////////////////////////////////
BRUTE FORCE :   Just a linear search 
TC : O(n) and SC : O(1)

vector<int> getFloorAndCeil(vector<int> nums, int x) {

        //Floor -> largest no in array <= x
        int n = nums.size();
        int floor = -1;
        int ceil = -1;

        for(int i=0; i<n; i++){
            if(nums[i] <= x){
                floor = nums[i];
            }
        }
        //ceil -> smallest no in array >= x
         for(int i=n-1; i>= 0; i--){
            if(nums[i] >= x){
                ceil = nums[i];
            }
        }

        return {floor, ceil};
    }

////////////////////////////////////////////////////////////

OPTIMIZED APPROACH :
TC : O(log n) and SC : O(1)
  
int findFloor(vector<int>& arr, int x) {
        // code here
       //Floor -> largest no in array <= x
        int n = arr.size();
        int floor = -1;
        //int ceil = -1;
        int low = 0;
        int high = n-1;
        
        while(low <= high){
            
            int mid = (low + high)/2;
            
            if(arr[mid] <= x){
                floor = mid;
                low = mid+1;
            }
            
            else{
                high = mid -1;
            }
            
            
        }

        return floor;
        
    }

 int findCeil(vector<int>& arr, int x) {
        // code here
               //Floor -> largest no in array <= x
        int n = arr.size();
        int ceil = -1;
        //int ceil = -1;
        int low = 0;
        int high = n-1;
        
        while(low <= high){
            
            int mid = (low + high)/2;
            
            if(arr[mid] >= x){
                ceil = mid;
                high = mid -1;
                
            }
            
            else{
                low = mid+1;
            }
            
            
        }

        return ceil;
        
    }
