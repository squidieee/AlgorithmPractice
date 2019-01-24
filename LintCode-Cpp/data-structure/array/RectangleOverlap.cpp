/* 
626. Rectangle Overlap
Given two rectangles, find if the given two rectangles overlap or not.

Example
Given l1 = [0, 8], r1 = [8, 0], l2 = [6, 6], r2 = [10, 0], return true

Given l1 = [0, 8], r1 = [8, 0], l2 = [9, 6], r2 = [10, 0], return ``false`

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
    bool doOverlap(Point &l1, Point &r1, Point &l2, Point &r2) {
        // left
        if (r2.x < l1.x) return false;
        // right
        if (l2.x > r1.x) return false;
        // up
        if (r2.y > l1.y) return false;
        // down
        if (l2.y < r1.y) return false;
        
        return true;
    }
    
};

// instead of computing intersection
// we should compute non-intersect case instead
// if we divide the region outside a rectangle
// it has left right up bottom