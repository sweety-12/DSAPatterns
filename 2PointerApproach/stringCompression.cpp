443. String Compression
Medium
Topics
premium lock icon
Companies
Hint
Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

Note: The characters in the array beyond the returned length do not matter and should be ignored. 

Example 1:

Input: chars = ["a","a","b","b","c","c","c"]
Output: 6
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
Example 2:

Input: chars = ["a"]
Output: 1
Explanation: The only group is "a", which remains uncompressed since it is a single character.
Example 3:

Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: 4
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
 

Constraints:

1 <= chars.length <= 2000
chars[i] is a lowercase English letter, uppercase English letter, digit, or symbol.

//////////////////////////////////////
Brute force Approach : 
Tc : O(n) and SC : o(n)

int compress(vector<char>&chars){

    int n = chars.size();
    int i=0;
    string temp = ""
;
    while(i<n){

        int count =0;
        char cur = chars[i];

        //count same elements
        while(i<n &&  chars[i] == cur){
            count++;
            i++;
        }

        //Adding the character
        temp += cur;

        //Adding the count;
        if(count > 1){
            temp += to_string(count);
        }   
    }

     //COPY BACK TO ORIGINAL
        for(int i=0; i<temp.size(); i++){
            chars[i] = temp[i];
        }

        return temp.size();
}


///////////////////////////////////

Opitmized Approach
Tc : O(n) and SC : O(1)

int compress(vector<char>&chars){

    int read =0;
    int write =0;
    int n = chars.size();

    while(read < n){

        char curr = chars[read];
        int count = 0;

        //Counting repeated elements
        while(read < n && chars[read] == curr){
            read++;
            count++;
        }

        //Adding the element
        chars[write] = curr;
        write++;

        //Adding the count
        if(count > 1){
            string cnt = to_string(count);

            for(auto it : cnt){
                chars[write] = it;
                write++;
            }
        }
    }

    return write;
}
