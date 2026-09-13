1048. Longest String Chain
You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].

APPROACH:
TC: O(n^2) + O(n) and SC : O(n)

class Solution {
public:
    int longestStrChain(vector<string>& words) {

        int n = words.size();

        sort(words.begin(), words.end(), compare);

        vector<int> dp(n, 1);

        int maxLen =0;

        for(int i =0; i <n; i++){

            for(int j =0; j < i; j++){

                if(checkPossible(words[i], words[j]) && dp[i] < dp[j] + 1){

                    dp[i] = dp[j] + 1;
                }
            }

            if(dp[i] > maxLen)  maxLen = dp[i];
        }

        return maxLen;
    }

    bool static compare(string &s, string &t){
        return s.size() < t.size();
    }

    bool checkPossible(string &s, string &t){

        if(s.size() != t.size() + 1)  return false;

        int i = 0, j = 0;

        while(i < s.size()){

            if(j < t.size() && s[i] ==t[j]){
                i++, j++;
            }

            else{    //this should get hit only once to check that one extra character
                i++;
            }
        }

        if(i == s.size() && j == t.size())  return true;

        return false;

    }
};
