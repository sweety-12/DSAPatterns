Problem 2 — Triplet Sum to Zero
Given an array of unsorted integers, find all unique triplets that sum to zero.
Input:  nums = [-3, 0, 1, 2, -1, 1, -2]
Output: [[-3, 1, 2], [-2, 0, 2], [-2, 1, 1], [-1, 0, 1]]

Input:  nums = [-5, 2, -1, -2, 3]
Output: [[-5, 2, 3], [-2, -1, 3]]
Constraints:

Result set must not contain duplicate triplets
Elements within each triplet should be non-decreasing order
Same element cannot be used twice

//////////////////////////////////////////////////
OPTIMIZED SOLUTION 
TIME COMPLEXITY :
Sort              →  O(n log n)
Outer loop i      →  O(n)
Two pointer       →  O(n)  for each i
─────────────────────────────────────
O(n log n) + O(n × n) = O(n²)
O(n²) dominates — final TC is O(n²)

Space Complexity
Sorting in place     →  O(1)   (no extra space)
Output ans vector    →  O(n)   (but this is output, doesn't count)
─────────────────────────────────────────────────────────────────
SC = O(1)

**In interviews always clarify — "I'm not counting output space" — interviewers appreciate that.**


//////////////////////////////////////////////////

vector<vector<int>>threeSum(vector<int>&nums){

    vector<vector<int>>ans;

    for(int i=0; i<nums.size()-2; i++){

        //SKIP DUPICATES
        if(i>0 && nums[i] == nums[i-1]) continue;

        int left = i+1;
        int right = nums.size()-1;

        while(left < right){

            int sum = nums[i] + nums[left] + nums[right];

            if(sum > 0){
                right--;
            }

            else if(sum < 0){
                left++;
            }

            else {
                
                ans.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;

                while(left < right && nums[left] == nums[left-1]) left++;
                while(left < right && nums[right] == nums[right+1]) right--;
            }
        }
    }

    return ans;
}
