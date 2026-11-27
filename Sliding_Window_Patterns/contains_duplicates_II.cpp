219. Contains Duplicate II
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false

APPROACH: SLIDING WINDOW
TC: O(n) AND SC: O(n)

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_set<int>st;
        
        for(int i=0; i<n; i++){
            if(i > k){
                st.erase(nums[i-k-1]);  //shrink from left if window size exceeds k
            }

            if(st.count(nums[i])){  //return true if the value is already present in set means duplicate
                return true;
            }

            st.insert(nums[i]);    //expand the window size
        }

        return false;
    }
};
