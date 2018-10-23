/*
611. Knight Shortest Path
Given a knight in a chessboard (a binary matrix with 0 as empty and 1 as barrier) with a source position, find the shortest path to a destination position, return the length of the route.
Return -1 if knight can not reached.

Example
[[0,0,0],
 [0,0,0],
 [0,0,0]]
source = [2, 0] destination = [2, 2] return 2

[[0,1,0],
 [0,0,0],
 [0,0,0]]
source = [2, 0] destination = [2, 2] return 6

[[0,1,0],
 [0,0,1],
 [0,0,0]]
source = [2, 0] destination = [2, 2] return -1
Clarification
If the knight is at (x, y), he can get to the following positions in one step:

(x + 1, y + 2)
(x + 1, y - 2)
(x - 1, y + 2)
(x - 1, y - 2)
(x + 2, y + 1)
(x + 2, y - 1)
(x - 2, y + 1)
(x - 2, y - 1)
Notice
source and destination must be empty.
Knight can not enter the barrier.
 */
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

 class Solution {
public:
    /**
     * @param grid: a chessboard included 0 (false) and 1 (true)
     * @param source: a point
     * @param destination: a point
     * @return: the shortest path 
     */
    int shortestPath(vector<vector<bool>> &grid, Point &source, Point &destination) {
        // write your code here
        if (grid.empty()) return 0;
        if (source.x == destination.x && source.y == destination.y) return 0;
        
        vector<pair<int,int>> directions{{1,2},{-1,2},{-1,-2},{1,-2},{2,1},{-2,-1},{-2,1},{2,-1}};

        queue<Point>  nextMove;
        nextMove.push(source);
        
        int totalMove(0);
        
        while(!nextMove.empty())
        {
            totalMove++;
            int len = nextMove.size();
            // for each level
            for (int i = 0; i < len; i++) 
            {
                Point pt = nextMove.front();
                nextMove.pop();    
                for (pair<int,int> dir : directions)
                {
                    Point new_pt;
                    new_pt.x = dir.first + pt.x;
                    new_pt.y = dir.second + pt.y;
                    if (new_pt.x == destination.x && new_pt.y == destination.y)
                        return totalMove;
                    if (isValid(new_pt, grid))
                    {
                        nextMove.push(new_pt);
                        grid[new_pt.x][new_pt.y] = true;
                    }
                    
                }                
            }
        }
        return -1;
    }

    bool isValid(Point &pt, vector<vector<bool>> &grid)
    {
        if (pt.x > grid.size()-1 || pt.x < 0) return false;
        if (pt.y > grid[0].size()-1|| pt.y < 0) return false;
        return !grid[pt.x][pt.y];
    }
};