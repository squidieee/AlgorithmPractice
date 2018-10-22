/*
616. Course Schedule II
There are a total of n courses you have to take, labeled from 0 to n - 1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example
Given n = 2, prerequisites = [[1,0]]
Return [0,1]

Given n = 4, prerequisites = [1,0],[2,0],[3,1],[3,2]]
Return [0,1,2,3] or [0,2,1,3]
 */
 class Solution {
public:
    /*
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: the course order
     */
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {
        vector<int> result;
        if (numCourses < 1) return result;
        
        // record in-degree
        vector<int> indegrees(numCourses);
        vector<vector<int>> depends(numCourses);
        
        for(auto rep: prerequisites)
        {
            indegrees[rep.second]++;
            depends[rep.first].push_back(rep.second);
        }
        
        // prepare queue
        queue<int> zeroIndegrees;
        stack<int> inv_result;
        
        for(int i = 0; i < numCourses; i++)
        {
            if (indegrees[i] == 0)
            {
                zeroIndegrees.push(i);
                inv_result.push(i);
            }
        }
        
        int visited(0);
        // bfs
        while (!zeroIndegrees.empty())
        {
            int node = zeroIndegrees.front();
            zeroIndegrees.pop();
            visited++;
            for(int i = 0; i < depends[node].size(); i ++)
            {
                // reduce in degree
                indegrees[depends[node][i]]--;
                
                if (indegrees[depends[node][i]] == 0) 
                {
                    // update zero indegrees
                    zeroIndegrees.push(depends[node][i]);
                    // record in inv_result
                    inv_result.push(depends[node][i]);
                }
            }
        }
        
        if (visited == numCourses)
        {
            while(!inv_result.empty())
            {
                result.push_back(inv_result.top());
                inv_result.pop();
            }
        }
        
        return result;
    }
};