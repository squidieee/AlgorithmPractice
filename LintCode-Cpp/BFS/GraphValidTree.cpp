/*
178. Graph Valid Tree
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

Example
Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

Notice
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*/

class Solution {
public:
     
    bool validTree(int n, vector<vector<int>> &edges) {
        if (n < 2) return true;
        // pre-processing
        vector<vector<int>> neighbors(n);
        for(int i = 0; i < edges.size(); i++)
        {
            neighbors[edges[i][0]].push_back(edges[i][1]);
            neighbors[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool> visited(n, false);
        
        queue<int> myQue;
        myQue.push(0);
        visited[0] = true;
        
        int totalVisited(1);
        
        while(!myQue.empty())
        {
            int node = myQue.front();
            myQue.pop();
            int cnt(0);
            for(int i = 0; i < neighbors[node].size(); i++)
            {
                // add each neighbors except for its parent
                if (!visited[neighbors[node][i]])
                {
                    myQue.push(neighbors[node][i]);
                    visited[neighbors[node][i]] = true;
                    totalVisited++;
                }
                else
                    cnt++;
            }
            if (cnt > 1) return false; // it should not have more than one visited
        }
        return totalVisited == n;
    }
};

// "a tree is an undirected graph in which any two vertices are connected by exactly one path"
// pre-processing: 
// convert edge info into a vector of vector 
// such that each node recording adjacent nodes
// assuming 0 is root
// do a bfs while keeping a visited array to check if any nodes has been visited twice
// if so, it is not a tree