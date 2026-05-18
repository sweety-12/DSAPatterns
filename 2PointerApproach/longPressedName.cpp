Long Pressed Name — LeetCode #925
Your friend is typing their name into a keyboard. However, they might hold a key too long, causing a character to be typed one or more extra times.
Given the typed string, return true if it is possible that typed was produced by long pressing some characters of name, otherwise return false.
Input:  name = "alex", typed = "aaleex"
Output: true
Reason: 'a' is long pressed once. 'e' is long pressed once.

Input:  name = "saeed", typed = "ssaaedd"
Output: false
Reason: name has 'e' twice but typed only has 'e' once → impossible

Input:  name = "leelee", typed = "lleeelee"
Output: true

Input:  name = "laiden", typed = "laiden"
Output: true
Reason: no long pressing needed, exact match is valid
Constraints:

1 <= name.length, typed.length <= 1000
name and typed consist of lowercase English letters

////////////////////////////////////////////////////////////
Brute force :
TC : O(n + m) and SC : O(n + m)   

 vector<pair<char,int>> compress(string s) {

        vector<pair<char,int>> groups;

        int i = 0;

        while(i < s.size()) {

            char ch = s[i];
            int count = 0;

            while(i < s.size() && s[i] == ch) {
                count++;
                i++;
            }

            groups.push_back({ch, count});
        }

        return groups;
    }

    bool isLongPressedName(string name, string typed) {

        vector<pair<char,int>> a = compress(name);
        vector<pair<char,int>> b = compress(typed);

        if(a.size() != b.size())
            return false;

        for(int i = 0; i < a.size(); i++) {

            // characters must match
            if(a[i].first != b[i].first)
                return false;

            // typed must have >= frequency
            if(a[i].second > b[i].second)
                return false;
        }

        return true;
    }

////////////////////////////////////////////////////////////

OPTIMIZED APPROACH :
TC : O(n + m) and SC : O(1)

 bool isLongPressedName(string name, string typed) {

        int i = 0;
        int j = 0;

        while(j < typed.size()) {

            // characters match
            if(i < name.size() && name[i] == typed[j]) {
                i++;
                j++;
            }

            // long press character
            else if(j > 0 && typed[j] == typed[j - 1]) {
                j++;
            }

            // invalid case
            else {
                return false;
            }
        }

        // all name chars should be used
        return i == name.size();
    }
