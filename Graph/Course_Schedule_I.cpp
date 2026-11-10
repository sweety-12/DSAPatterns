LEETCODE 207:
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

APPROACH: TOPO SORT (KAHN'S ALGO BFS)

//LOGIC: The logic is exactly same to DAG problem, i just need to traverse all the nodes and if i am able to traverse all the nodes or push all the nodes into the ans vector then return true.

//steps:
//1. Declare adj list and initialize
//2. declare indegree vector and initialize it.
//3. Declare queue and push all the nodes whose indegree is 0
//4. declare a ans vector
//5. Start traversing inside while loop
//6. if size of ans != numCourses return false


//ai -> bi
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         
         vector<vector<int>>adj(numCourses);

            //initializing adj list
         for(auto it : prerequisites){
                adj[it[0]].push_back(it[1]);
         }

        //decalring indegree and initializing
         vector<int>indegree(numCourses, 0);

         for(int i=0; i<numCourses; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
         }

         queue<int>q;

         //pushing nodes whose indegree 0
         for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
         }


        vector<int>ans;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto it: adj[node]){
                indegree[it]--;

                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        if(ans.size() != numCourses)  return false;

        return true;
    }
};
