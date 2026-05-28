Problem 6 — Find The Duplicate Number (Medium)
Platform: LeetCode 287

Problem Statement:
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive. There is exactly one repeated number — return that duplicate.
You must solve it without modifying the array and using only O(1) extra space.

Examples:
Example 1:
Input:  [1, 3, 4, 2, 2]
Output: 2
Example 2:
Input:  [3, 1, 3, 4, 2]
Output: 3

Constraints:

1 <= n <= 10⁵
nums.length == n + 1
1 <= nums[i] <= n
Only one duplicate number exists


The Trick — Array as Linked List 🤯
Think of it this way:
index:  0  1  2  3  4
value:  1  3  4  2  2
Treat nums[i] as next pointer:
0 → nums[0]=1 → nums[1]=3 → nums[3]=2 → nums[2]=4 → nums[4]=2 → ...
The duplicate creates a cycle — just like Linked List Cycle II!

////////////////////////////////////////////////////////////

int duplicate(vector<int>nums){

//Edge case
bool hasCycle = false;
if(nums.size() == 0) return 0;

int slow = 0;
int fast = 0;

//Flods algo
while(true) {

slow = nums[slow];
fast = nums[nums[fast]];

if(slow == fast) {

hasCycle = true;
slow = 0;
break;
}
}

if (hasCycle == false) return 0;
//Phase 2
while(slow != fast) {

slow = nums[slow];
fast = nums[fast];
}

return slow;

}
