//---------------------------------------- THIS QUESTION IS FROM DIRECTED CYCLE DETECTION PATTERN BUT NEED TO PRACTICE AGAIN ------------------------------

GFG : Alien Dictionary
An alien language uses the lowercase English alphabet, but the order of its letters is unknown. You are given an array of strings words[] that is claimed to be sorted lexicographically according to the rules of the alien language.

Determine the order of the letters in the alien alphabet.

If a valid ordering exists, return a string containing all unique letters in lexicographical order according to the alien language.
Otherwise, return an empty string.
If a string s1 is lexicographically smaller than a string s2, and the first position at which they differ contains letter a in s1 and letter b in s2, then a must appear before b in the alien alphabet.
If one word is a prefix of the other, the shorter word must appear before the longer word.

Note: The driver code prints true if the returned order is valid; otherwise, it prints false.

Examples:

Input: words[] = ["baa", "abcd", "abca", "cab", "cad"]
Output: true
Explanation: A possible correct order of letters in the alien dictionary is "bdac".
The pair "baa" and "abcd" suggests 'b' appears before 'a' in the alien dictionary.
The pair "abcd" and "abca" suggests 'd' appears before 'a' in the alien dictionary.
The pair "abca" and "cab" suggests 'a' appears before 'c' in the alien dictionary.
The pair "cab" and "cad" suggests 'b' appears before 'd' in the alien dictionary.
So, 'b' -> 'd' -> 'a' -> 'c' is a valid ordering.

APPROACH : Kahn's Algo using BFS
- N = total number of characters across all words.
- V = number of distinct characters (at most 26).
- E = number of unique directed edges (at most V^2)).
Time Complexity:  O(N + V + E)

- Marking characters: (O(N))
- Building the graph: (O(N))
- Kahn's algorithm: (O(V+E))
So overall: (O(N+V+E)).
Space Complexity: O(V+E)

For the fixed lowercase English alphabet, V <= 26 and E <= 26^2, so the graph-related space is bounded by a constant.

class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        
        vector<unordered_set<int>>adj(26);  //coz no. of unique characters not given
        vector<int>indegree(26, 0);
        vector<bool> exists(26, false);
        
        //mark all characters that appear in the words
        int unique =0;
        
        for(string &word : words){
            for(char ch : word){
                
                int node = ch - 'a';
                
                if(exists[node] == false){
                    exists[node] = true;
                    unique++;
                }
            }
        }
        
        //build the graph with adjacent words
        for(int i=0; i+1 < words.size(); i++){
            
            string &a = words[i];
            string &b = words[i + 1];
            
            int j =0;
            int len = min(a.size(), b.size());
            
            while(j <len && a[j] == b[j]){
                j++;
            }
            
            //invalid prefix case: "abc" comes before "ab"
            if(j == len){
                if(a.size() > b.size()){
                    return "";
                }
                
                continue;
            }
            
             int u = a[j] - 'a';
            int v = b[j] - 'a';
            
            //avoid duplicate edges
            if(adj[u].insert(v).second){
                indegree[v]++;
            }
        }
        
       //kahn's algo
       
       queue<int>q;
       
       for(int i=0; i<26; i++){
           if(exists[i] &&  indegree[i] == 0){
               q.push(i);
           }
       }
       
       string ans;
       
       while(!q.empty()){
           
           int node = q.front();
           q.pop();
           
           ans += char(node + 'a');
           
           for(int neighbour : adj[node]){
               indegree[neighbour]--;
               
               if(indegree[neighbour] == 0){
                   q.push(neighbour);
               }
           }
       }
       
       if(ans.size() != unique) return "";
        
       return ans;
    }
};
