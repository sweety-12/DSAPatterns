LEETCODE 210:
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.
Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

APPROACH: KAHN'S ALGO BFS

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

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

        reverse(ans.begin(), ans.end());

        if(ans.size() != numCourses)  return {};

        return ans;
    }
};
