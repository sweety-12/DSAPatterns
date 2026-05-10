Problem 3 — Triplet Sum Close to Target
Given an unsorted array of integers and a target, find a triplet whose sum is closest to the target. Return the sum.
Input:  nums = [-2, 0, 1, 2], target = 2
Output: 1  (triplet [-2, 1, 2] = 1, closest to 2)

Input:  nums = [-3, -1, 1, 2], target = 1
Output: 0  (triplet [-3, -1, 2] = 0 OR [-3, 1, 2] = 0... wait is it?)
           actually [-1, 1, 2] = 2... which is closer to 1?

Input:  nums = [1, 0, 1, 1], target = 100
Output: 3

Constraints:

3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-10⁴ <= target <= 10⁴
Exactly one valid answer exists


int tripetSumCloseToTarget(vector<int>&nums, int target){

    int ans = nums[0] + nums[1] + nums[2];
    sort(nums.begin(), nums.end());

    for(int i=0; i<nums.size()-2; i++){

        if(i>0 && nums[i] == nums[i-1]) continue;

        int left =i+1;
        int right = nums.size()-1;


        while(left < right){
            
            int sum = nums[i] + nums[left] + nums[right];

            if(abs(target - sum) < abs(target - ans)){
                    ans = sum;
                }

            if(sum == target){
                return sum;
            }

            else if(sum > target){    
                right--;
            }
            else if (sum < target){
                left++;
            }
        }

    }

    return ans;

} 
