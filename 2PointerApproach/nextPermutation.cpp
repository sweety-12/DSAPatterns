problem 4 of 4 — Next PermutationProblem
Difficulty: Hard

A permutation of an array of integers is an arrangement of its members in some order.
The next permutation is the next lexicographically greater permutation. If no such permutation exists (array is descending), rearrange to the lowest possible order (ascending).
Must be done in-place with O(1) extra space.
Input:  nums = [1,2,3]
Output: [1,3,2]

Input:  nums = [3,2,1]
Output: [1,2,3]

Input:  nums = [1,1,5]
Output: [1,5,1]

Input:  nums = [1,3,2]
Output: [2,1,3]
Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100


Intuition Builder 🧠
Think about [1,3,2] manually:
All permutations in order:
[1,2,3]
[1,3,2]  ← we are here
[2,1,3]  ← next
[2,3,1]
[3,1,2]
[3,2,1]

Look at [1,3,2] — what is the minimum change you can make to get the next one?

Before writing any code — can you spot the 3-step pattern by just staring at the array? 🎯

BRUTE FORCE APPROACH :

TC: O(n! * n) — n! permutations, each of size n
SC: O(n!) — storing all permutations


void nextPermutation(vector<int>& nums) {
    vector<vector<int>> allPerms;
    vector<int> temp = nums;
    
    // sort to start from smallest permutation
    sort(temp.begin(), temp.end());
    
    // generate all permutations
    do {
        allPerms.push_back(temp);
    } while(next_permutation(temp.begin(), temp.end()));
    
    // find current permutation
    for(int i = 0; i < allPerms.size(); i++) {
        if(allPerms[i] == nums) {
            // if last permutation → return first
            if(i == allPerms.size()-1) {
                nums = allPerms[0];
            } else {
                nums = allPerms[i+1];
            }
            return;
        }
    }
}


OPTIMIZED APPROACH :
TC : O(n) and SC : O(1)

void nextPermutation(vector<int>& nums) {
    int n = nums.size();

    // Step 1: find pivot
    int pivot = -1;
    for(int i = n-1; i >= 1; i--) {
        if(nums[i-1] < nums[i]) {
            pivot = i-1;
            break;
        }
    }

    // Step 2: find & swap
    if(pivot != -1) {
        int swapIdx = -1;
        for(int i = n-1; i > pivot; i--) {
            if(nums[i] > nums[pivot]) {
                swapIdx = i;
                break;
            }
        }
        swap(nums[pivot], nums[swapIdx]);
    }

    // Step 3: reverse suffix
    reverse(nums.begin() + pivot + 1, nums.end());
}


