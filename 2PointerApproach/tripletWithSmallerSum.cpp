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


The Logic for :   
Count += right-left 

nums = [-1, 0, 2, 3, 4], target = 6
        i   L          R

nums[i] + nums[L] + nums[R] < target
-1      +  0      +  4      = 3 < 6 ✅
Since array is sorted — everything between L and R is smaller than R.
So ask yourself:

If -1 + 0 + 4 < 6
then -1 + 0 + 3 < 6 ?

Yes — because 3 < 4 ✅

then -1 + 0 + 2 < 6 ?

Yes — because 2 < 4 ✅

So how many valid right pointers exist at this moment?
L         R
0    2    3    4
     ↑    ↑    ↑
     R1   R2   R3   →  3 valid rights for this L
How many elements are between L and R?
right - left = 4 - 1 = 3 ✅

One line logic

"If smallest + largest < target, then smallest + anything in between < target too."

That "anything in between" is exactly right - left elements.

                                        "Count a range at once instead of one by one"
