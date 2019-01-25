/* 
626. Rectangle Intersection Area
Given two rectangles, find the intersection area.

Example
Given l1 = [0, 8], r1 = [8, 0], l2 = [6, 6], r2 = [10, 0], return 12

Given l1 = [0, 8], r1 = [8, 0], l2 = [9, 6], r2 = [10, 0], return -1

Notice
l1: Top Left coordinate of first rectangle.
r1: Bottom Right coordinate of first rectangle.
l2: Top Left coordinate of second rectangle.
r2: Bottom Right coordinate of second rectangle.

l1 != r2 and l2 != r2
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
     * @param l1: top-left coordinate of first rectangle
     * @param r1: bottom-right coordinate of first rectangle
     * @param l2: top-left coordinate of second rectangle
     * @param r2: bottom-right coordinate of second rectangle
     * @return: true if they are overlap or false
     */
    int findIntersectArea(Point &l1, Point &r1, Point &l2, Point &r2) {
        // left
        if (r2.x < l1.x) return -1;
        // right
        if (l2.x > r1.x) return -1;
        // up
        if (r2.y > l1.y) return -1;
        // down
        if (l2.y < r1.y) return -1;
        
        // compute the intersection area
        int dist_x = min(r1.x, r2.x) - max(l1.x, l2.x);
        int dist_y = min(l1.y, l2.y) - max(r1.y, r2.y);
    }
    
};

// instead of computing intersection
// we should compute non-intersect case instead
// if we divide the region outside a rectangle
// it has left right up bottom

// the intersected rectangle will have different min or max 
// based on the rectangle's definition of corner points 