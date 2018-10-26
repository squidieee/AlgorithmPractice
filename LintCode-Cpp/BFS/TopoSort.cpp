/*
127. Topological Sorting
Given an directed graph, a topological order of the graph nodes is defined as follow:

For each directed edge A -> B in graph, A must before B in the order list.
The first node in the order can be any node in the graph with no nodes direct to it.
Find any topological order for the given graph.

Example
For graph as follow:

picture

The topological order can be:

[0, 1, 2, 3, 4, 5]
[0, 2, 3, 1, 5, 4]
...
Challenge
Can you do it in both BFS and DFS?

Clarification
Learn more about representation of graphs

Notice
You can assume that there is at least one topological order in the graph.
*/
/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */

 class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        vector<DirectedGraphNode*> order;
        if (graph.empty()) return order;
        
        unordered_map<DirectedGraphNode*, int> indegrees;
        // compute in degrees
        for (int i = 0; i < graph.size(); i++)
        {
            if(indegrees.count(graph[i])==0)
                indegrees.insert({graph[i], 0});
            for(auto nei: graph[i]->neighbors)
            {
                if(indegrees.count(nei)==0)
                    indegrees.insert({nei, 1});
                else
                    indegrees.at(nei)++;
            }
        }
        
        queue<DirectedGraphNode*> que;
        // find starting point
        for(unordered_map<DirectedGraphNode*, int>::iterator it = indegrees.begin(); it != indegrees.end(); it++)
        {
            if (it->second == 0) 
            {
                que.push(it->first);
                order.push_back(it->first);
            }
        }
        
        // bfs
        while(!que.empty())
        {
            DirectedGraphNode* cnode = que.front();
            que.pop();
            
            for(auto nei: cnode->neighbors)
            {
                indegrees.at(nei)--;
                if (indegrees.at(nei) == 0)
                {
                    que.push(nei);
                    order.push_back(nei);
                }
            }
            
        }
        return order;
    }
};