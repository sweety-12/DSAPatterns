Compare Version Numbers — LeetCode #165
Given two version strings version1 and version2, compare them.

Return -1 if version1 < version2
Return 1 if version1 > version2
Return 0 if they are equal

Version strings are split by . into revisions. Each revision is compared numerically.
Input:  version1 = "1.2",   version2 = "1.10"
Output: -1
Reason: 2 < 10 numerically

Input:  version1 = "1.01",  version2 = "1.001"
Output: 0
Reason: 01 == 001 == 1 numerically

Input:  version1 = "1.0",   version2 = "1"
Output: 0
Reason: missing revision = 0

Input:  version1 = "1.5.1", version2 = "1.5"
Output: 1
Reason: 1.5.1 > 1.5 → missing revision treated as 0
Constraints:

1 <= version1.length, version2.length <= 500
Versions only contain digits and .
Revisions don't have leading zeros except "0" itself


Before coding — answer these:

Why is direct string comparison wrong?
How do you extract each revision number between dots?
What do you do when one version runs out of revisions but other hasn't?

Answer first. 👊

1. inside string elements are in the form of characters and we cannot compare greater than less than with chars, we need to have integer in that case
2. stoi 
3. 1.5.0

//////////////////////////////////////////////////////////// 
Brute force
TC : O(n+m) and SC : O(n+m);

vector<int>getint(string s){

    string temp = "";
    vector<int>nums;

    for(int i=0; i<s.length(); i++){

        if(s[i] == '.'){
            nums.push_back(stoi(temp));
            temp = "";
        }
        else{
            temp += s[i];
        }
    }
    nums.push_back(stoi(temp));
    return nums;
}

int compareVersions(string v1, string v2){

    //converting the string into integer
    vector<int>vec1 = getint(v1);
    vector<int>vec2 = getint(v2);

    int size = max(vec1.size(), vec2.size());

    for(int i=0; i<size; i++){

        int a=0, b=0;
        if(i<vec1.size()){
            a = vec1[i];
        }

        if(i < vec2.size()){
            b = vec2[i];
        }

        if(a > b){
            return 1;
        }
        else (a<b){
            return -1;
        }
        
    }

   return 0;
}

////////////////////////////////////////////////////////////
Optimized Approach 

int compareversions(string v1, string v2){
    int m = v1.length();
    int n = v2.length();

    int i=0, j=0;

    while(i<m || j<n){

        int num1 =0;
        int num2 =0;

        //converting string v1
        while(i<m && v1[i] != '.'){
            num1 = num1 * 10 + (v1[i] - '0');
            i++;
        }

        //converting string v2
        while(j<n && v2[j] != '.'){
            num2 = num2 * 10 + (v2[j] - '0');
            j++;
        }

         if(num1 > num2)  return 1;
         else if ( num2 > num1)  return -1;

         //skipping the dots
        if(i<m) i++;
        if(j<n) j++;
        
    }

    return 0;
}

TC : O(n+m) and SC : O(1)

//NEED TO COME BACK AND PRACTICE AGAIN
