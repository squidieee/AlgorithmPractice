/*
615. Course Schedule
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example
Given n = 2, prerequisites = [[1,0]]
Return true

Given n = 2, prerequisites = [[1,0],[0,1]]
Return false
 */
 class Solution {
public:
    /*
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: true if can finish all courses or false
     */
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // compute in-degree
        vector<int> indegrees(numCourses, 0);
        vector<vector<int>> map(numCourses);
        
        for(auto p: prerequisites)
        {
            indegrees[p.second]++;
            map[p.first].push_back(p.second);
        }
        
        queue<int> q;
        for (int i = 0; i < indegrees.size(); i++)
        {
            if (indegrees[i] == 0) q.push(i);
        }
        
        int numVisited(0);
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            numVisited++;
            for(int directed:  map[temp])
            {
                indegrees[directed]--;
                if (indegrees[directed] == 0) q.push(directed);
            }
        }
        
        return numVisited == numCourses;
    }
    

};