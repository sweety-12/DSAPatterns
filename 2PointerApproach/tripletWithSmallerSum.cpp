Problem 5 — Triplet with Smaller Sum
LeetCode #259
Given an array of integers and a target, return the count of triplets whose sum is less than target.
Input:  nums = [-1, 0, 2, 3], target = 3
Output: 2
        (triplets: [-1, 0, 2] = 1, [-1, 0, 3] = 2 — both < 3)

Input:  nums = [-1, 4, 2, 1, 3], target = 5
Output: 4
Constraints:

0 <= nums.length <= 3500
-100 <= nums[i] <= 100
-10⁴ <= target <= 10⁴


int count_triplets(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int count = 0;

    for (int i = 0; i < n-2; i++) {
        int left = i+1;
        int right = n-1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum < target) {
                count += right - left;  // ✅ key insight
                left++;
            }
            else {
                right--;
            }
        }
    }
    return count;
}
