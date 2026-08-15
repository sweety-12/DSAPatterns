APPROACH : THIS IS LITERALLY THE EXACT QUESTION - LONGEST PALINDROMIC SUBSEQUENCE. SO THE APPROACH IS WE NEED TO FIND MINIMUM NUMBER OF ELEMENTS TO MAKE A STRING A PALINDROME RIGHT? 
FOR THAT WE FIRST TO NEED TO HOW MANY CHARACTERS ARE THEIR WHICH ARE ALREADY IN PALINDROME. FOR REST WE NEED TO ADD THAT MUCH NUMBER OF ELEMENTS TO MAKE STRING PALINDROME. THAT'S IT.

ONLY CHANGE WE NEED IS : return n - longest_palindrome_subsequence(s)

RECURSIVE APPRAOCH:
TC: O(2^n) and SC : O(n)

class Solution {
public:
    int func(int ind1, int ind2, string &text1, string &text2){
        //base case
        if(ind1 < 0 || ind2 < 0){
            return 0;
        }

        //recursive call
        if(text1[ind1] == text2[ind2]){

            return 1 + func(ind1 -1, ind2 -1, text1, text2);
        }

        return 0 + max( func(ind1 -1, ind2, text1, text2), func(ind1, ind2-1, text1, text2));
    }
    int longestPalindromeSubseq(string s1) {
        
        int n = s1.length();

        string s2 = s1;
        reverse(s2.begin(), s2.end());

        return func(n-1, n-1, s1, s2);
    }

    int minInsertions(string s) {
        
       int n = s.length();
       

       return n - longestPalindromeSubseq(s);
    }
};

