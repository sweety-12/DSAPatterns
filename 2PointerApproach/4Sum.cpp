Problem 4 — Quadruple Sum to Target
LeetCode #18
Given an array of integers and a target, return all unique quadruplets that sum to target.
Input:  nums = [4, 1, 2, -1, 1, -3], target = 1
Output: [[-3, -1, 1, 4], [-3, 1, 1, 2]]

Input:  nums = [2, 0, -1, 1, -2, 2], target = 2
Output: [[-2, -1, 1, 4], [-2, 0, 0, 4], [-1, 0, 0, 1]]
Constraints:

1 <= nums.length <= 200
-10⁹ <= nums[i] <= 10⁹
-10⁹ <= target <= 10⁹
Answer must not contain duplicate quadruplets


Before you code — answer these:


How does this extend Problem 2 (ThreeSum)?
How many nested loops do you need before two pointer kicks in?
What is the TC you re expecting?


Answer then code. 👊
  
according to me this is the exact code as previous one, here in case we will fix 2 elements using 
2 nested loops and will then use 2 pointer approach. TC : O(n^3)

///////////////////////////////////////////////////////////////////////


vector<vector<int>fourSum(vector<int>&nums, int target){
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>>ans;

    for(int i=0; i<n-3; i++){
        if(i>0 && nums[i] == nums[i-1]) continue;

        for(int j = i+1 ; j<n-2; j++){

            if(j > i+1 && nums[j] == nums[j-1]) continue;

            int left = j+1;
            int right = n-1;

            while(left < right){

                int sum = nums[i] + nums[j] + nums[left] + nums[right];

                if(sum == target){

                    ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    right--;

                    while(left < right && nums[left] == nums[left-1]) left++;
                    while(lefft < right && nums[right] == nums[right+1]) right--;

                }

                else if ( sum > target) right--;
                else left++;
            }
        } 
    }

    return ans;
}
