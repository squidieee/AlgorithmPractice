/*
1708. Shortest Bridge

In a given 2D binary array A, there are two islands. (An island is a 4-directionally connected group of 1s not connected to any other 1s.)

Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.

Return the smallest number of 0s that must be flipped. (It is guaranteed that the answer is at least 1.)

Example
Example 1:

Input：[[0,1],[1,0]]
Output：1
Explanation：Flip 0 on (0,0) or (1,1)
Example 2:

Input：[[0,1,0],[0,0,0],[0,0,1]]
Output：2
Explanation：Flip 0 on (0,2) and (1,2)
Notice
1 <= A.length = A[0].length <= 100
A[i][j] == 0 or A[i][j] == 1
*/



class Solution {
public:
    int ShortestBridge(vector<vector<int>> &A) {
        // record indices for two islands or simply one island to num 2 
        vector<pair<int, int>> island2;
        vector<pair<int, int>> island1;
        for(int i = 0; i < A.size(); i++)
        {
            for(int j = 0; j < A[0].size(); j++)
            {
                if(A[i][j] == 1)
                {
                    bool markIsland1 = island2.size() > 0;
                    
                    queue<pair<int, int>> que;
                    que.push(std::make_pair(i, j));
                    A[i][j] = 2;
                    while(!que.empty())
                    {
                        pair<int, int> curr = que.front();
                        que.pop();
                        
                        if(markIsland1) 
                            island1.push_back(curr);
                        else
                            island2.push_back(curr);
                            
                        for(int d = 0; d < 4; d++)
                        {
                            int nextX = curr.first + _x[d];
                            int nextY = curr.second + _y[d];
                            if( valid(A, nextX,nextY) && A[nextX][nextY] == 1)
                            {
                                que.push(std::make_pair(nextX, nextY));
                                A[nextX][nextY] = 2;
                            }
                        }
                    }
                }
            }
        }
        
        // for each node on island 2, find its distance to island 1 by iterating all nodes on island 1
        int result = INT_MAX;
        for(int i1 = 0; i1 < island1.size(); i1++)
        {
            for(int i2 = 0; i2 < island2.size(); i2++)
            {
                result = min( result, abs(island1[i1].first - island2[i2].first) + 
                                      abs(island1[i1].second - island2[i2].second) ); 
            }
        }
        
        return result - 1;
    }
    
    bool valid(vector<vector<int>> &A, int x, int y)
    {
        return x >= 0 && x < A.size() && y >=0 && y < A[0].size();
    }
    
private:

const int _x[4] = {1, 0, -1, 0};
const int _y[4] = {0, 1, 0, -1};
};

// bfs
// to compute shortest distance between two sets, there is no need to do bfs/dfs
// just iterating to find min or max