Problem 7 — Valid Palindrome
LeetCode #125
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring case.
Input:  s = "A man, a plan, a canal: Panama"
Output: true

Input:  s = "race a car"
Output: false

Input:  s = " "
Output: true
Constraints:

1 <= s.length <= 2 * 10⁵
s consists only of printable ASCII characters


bool validPalindrome(string s){
    int left =0;
    int right = s.length() -1;

    while(left < right){

        if(!isalnum(s[left])) {
            left++;
            continue;
        }
        if(!isalnum(s[right])) {
            right--;
            continue;
        }

        else{
            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }
    
        }

        left++;
        right--;
    }

TC : O(n) and SC : O(1)

    return true;;
}
