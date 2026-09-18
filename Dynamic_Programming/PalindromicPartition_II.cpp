132. Palindrome Partitioning II

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
Example 2:

Input: s = "a"
Output: 0
Example 3:

Input: s = "ab"
Output: 1


RECURSIVE APPROACH:
TC : Exponential and SC : O(1)

class Solution {
public:
    bool isPalindrome(string &s, int i, int j){

        while( i<j){
            if(s[i] != s[j])  return false;

            i++;
            j--;
        }

        return true;
    }
    int func(string &s, int i){
        int n = s.length();

        if(i == n || isPalindrome(s, i, n-1))  return 0;

        int mini = INT_MAX;

        for(int j = i; j <n; j++){

            if(isPalindrome(s, i, j)){
                int cuts = 1 + func(s, j+1);

                mini = min(mini, cuts);
            }
        }

        return mini;
    }
    int minCut(string s) {

        int n = s.length();

        return func(s, 0);
        
    }
};
