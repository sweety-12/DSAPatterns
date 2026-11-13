//---------------------------------------- THIS QUESTION IS ON A HIGHER LEVEL OF DIFFICULTY OF ALL THE QUESTIONS I HAVE SOLVED IN BFS PATTERN ----------------------------------

GFG: Shortest Transformation Length in a Word List
Given two distinct words s and e, and a list of unique words words[], where all words have the same length, find the length of the shortest transformation sequences from start to end.

A valid transformation sequence must satisfy the following conditions:

Only one character can be changed in each transformation.
Every transformed word must exist in words[], including e.
All words consist only of lowercase English letters.
s may or may not be present in words[].
Return the length of the shortest transformation sequence from s to e. If no such sequence exists, return 0.

Examples:

Input: words[] = ["des", "der", "dfr", "dgt", "dfs"], s = "der", e = "dfs"
Output: 3
Explanation: The length of the shortest transformation sequence from "der" to "dfs" is 3 i.e "der" -> "dfr" -> "dfs".
Input: words = ["geek", "gefk"], s = "gedk", e = "geek", 
Output: 2
Explanation: The length of the shortest transformation sequence from "gedk" to "geek" is 2 i.e "gedk" -> "geek"
Input: words[] = ["poon", "plee", "same", "poie", "plea", "plie", "poin"], s = "toon", e = "plea",
Output: 7 
Explanation: The length of the shortest transformation sequence from "toon" to "plea" is 7 i.e., toon -> poon -> poin -> poie -> plie -> plee -> plea 

APPROACH :  BFS
1144 TESTCASES PASSES OF 1145 - THREW TLE
class Solution {
  public:
    int wordLadder(vector<string> &words, string &s, string &e) {
        // code here
        
        queue<pair<int, string>>q;
        q.push({1, s});
        
        map<string, bool>mp;
        
        for(int i=0; i<words.size(); i++){
            string s;
            
            for(int j =0; j< words[i].size(); j++){
                s += words[i][j];
                
                mp[s] = true;
            }
        }
        
        mp.erase(s);
        
        while(!q.empty()){
            pair<int, string> p = q.front();
            q.pop();
            
            if(p.second == e) return p.first;
            
            for(int j =0; j< p.second.size(); j++){
                
                char ch = p.second[j];
                for(char c = 'a' ; c <= 'z'; c++){
                    p.second[j] = c;
                    
                    if(mp.count(p.second)){
                        mp.erase(p.second);
                        q.push({p.first+1, p.second});
                    }
                }
                
                p.second[j] = ch;
            }
        }
        
        return 0;
    }
};
