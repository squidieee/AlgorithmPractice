/* 
612. K Closest Points
Given some points and an origin point in two-dimensional space, find k points which are nearest to the origin.
Return these points sorted by distance, if they are same in distance, sorted by the x-axis, and if they are same in the x-axis, sorted by y-axis.

Example
Given points = [[4,6],[4,7],[4,4],[2,5],[1,1]], origin = [0, 0], k = 3
return [[1,1],[2,5],[4,4]]
*/

class Solution {
public:
    /**
     * @param A: an integer array
     * @return: nothing
     */
    void sortIntegers2(vector<int> &A) {
        // write your code here
        if (A.empty() || A.size()==1) return; 
        //quickSort(A, 0, A.size()-1);
        mergeSort(A, 0, A.size()-1);
    }
    
    // quick sort
    void quickSort(vector<int> &A, int start, int end)
    {
        if (start == end) return;
        
        int pivot = A[start + (end - start) /2];
        
        // partition
        int left(start), right(end);
        while(left <= right)
        {
            while(left <= right && A[left] < pivot)
            {
                left++;
            }
            while(left <= right && A[right] > pivot)
            {
                right--;
            }
            
            if (left <= right)
            {
                swap(A[left], A[right]);
                left++;
                right--;
            }
        }
        
        // recurse
        quickSort(A, start, left - 1); // left is the partition index; right may be invalid index
        quickSort(A, left, end);
    }
    // merge sort
    
    void mergeSort(vector<int> &A, int start, int end)
    {
        if (start == end) return;
        int mid = start + (end-start)/2;
        
        //recurse
        mergeSort(A, start, mid);
        mergeSort(A, mid+1, end);
        
        // merge
        vector<int> temp(end - start + 1);
        
        int left(start),right(mid+1);
        
        for(int i = 0; i < temp.size();i++)
        {
            if ( (A[left] <= A[right] && left <= mid) || right > end)
            {
                temp[i] = A[left];
                left++;
            }
            else
            {/**
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
     * @param points: a list of points
     * @param origin: a point
     * @param k: An integer
     * @return: the k closest points
     */
    vector<Point> kClosest(vector<Point> &points, Point &origin, int k) {
        vector<Point> results;
        if (k == 0 || points.empty()) return results;
        
        vector<double> distances = getDistances(points, origin);
        
        // find first k closest by partition
        partition(points, distances, k-1, 0, points.size() - 1);
        
        // sort k points by distances
        partition(points, distances, -1, 0, k-1);
        for (int i = 0 ; i < k; i++)
        {
            results.push_back(points[i]);
        }

        return results;
    }
    
    vector<double> getDistances(vector<Point> &points, Point &origin)
    {
        vector<double> distances;
        for( Point& pt: points)
        {
            double d = (pt.x - origin.x) * (pt.x - origin.x) + (pt.y - origin.y) * (pt.y - origin.y);
            distances.push_back(d);
        }
        
        return distances;
    }
    
    void partition(vector<Point> &points, vector<double> &distances, int k, int start, int end)
    {
        if (start >= end) return;
        
        int left(start), right(end);
        int mid = left + (right - left)/2;
        
        double pivot = distances[mid]; // pivot should not change!
        Point pivotP = points[mid];
        
        while(left <= right)
        {
            while(isLargerThan(pivot, distances[left], pivotP, points[left]) && left <= right)
            { left++;}
            while(isLargerThan(distances[right], pivot, points[right],pivotP) && left <= right)
            { right--;}
            
            if (left <= right)
            {
                std::swap(distances[left], distances[right]);
                std::swap(points[left].x, points[right].x);
                std::swap(points[left].y, points[right].y);
                    
                left++;
                right--;
            }
        }
        
        if (k > 0)
        {
            
            // it quits when left > right
            // 1st interval [start, right]
            if (k <= right)
            {
                return partition(points, distances, k, start, right);
            }
            // 3rd interval [left, end]
            if (k >= left)
            {
                return partition(points, distances, k, left, end);
            }
            // 2nd interval: we found it at k
            
        }
        else
        {
            partition(points, distances, k, start, right);
            partition(points, distances, k, left , end);
        }
    }
    
    bool isLargerThan(double d1, double d2, Point& p1, Point& p2)
    {
        if (d1 != d2)
            return d1 > d2;
            
        // d1 == d2
        if (p1.x != p2.x) 
            return p1.x > p2.x;
        else
            return p1.y > p2.y;
    }
};
                temp[i] = A[right];
                right++;
            }

        }
        
        // copy array
        for (int i = 0; i < temp.size(); i++)
            A[start + i] = temp[i];
    }
};