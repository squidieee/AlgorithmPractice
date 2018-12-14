/* 
577. Merge K Sorted Interval Lists
Merge K sorted interval lists into one sorted interval list. You need to merge overlapping intervals too.

Example
Given

[
  [(1,3),(4,7),(6,8)],
  [(1,2),(9,10)]
]
Return

[(1,3),(4,8),(9,10)]
*/


/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

 class Solution {
public:
    /**
     * @param intervals: the given k sorted interval lists
     * @return:  the new sorted interval list
     */
    vector<Interval> mergeKSortedIntervalLists(vector<vector<Interval>> &intervals) {
        if (intervals.empty()) return vector<Interval>();
        return mergeKIntervalHelper(intervals, 0, intervals.size() - 1);
    }
    
    vector<Interval> mergeKIntervalHelper(vector<vector<Interval>> &intervals, int start, int end)
    {
        if (start == end) return intervals[start];
        if (start + 1 == end) return merge2SortedIntervals(intervals[start], intervals[end]);
        
        int mid = start + (end - start)/2;
        vector<Interval> firstHalf = mergeKIntervalHelper(intervals, start, mid);
        vector<Interval> secondHalf = mergeKIntervalHelper(intervals, mid+1, end);
        
        return merge2SortedIntervals(firstHalf, secondHalf);
    }
    
    vector<Interval> merge2SortedIntervals(vector<Interval>& v1, vector<Interval>& v2)
    {
        if (v1.empty()) return v2;
        if (v2.empty()) return v1;
        
        vector<Interval> merged;
        
        int iv1(0), iv2(0);
        while(iv1 < v1.size() || iv2 < v2.size())
        {
            cout << "1 "<< iv1 << endl;
            cout << "2 " << iv2 << endl;
            if (iv2 > v2.size() - 1 || (iv1 < v1.size() && v1[iv1].start <= v2[iv2].start))
            {
                
                if (merged.empty()) 
                {
                    merged.push_back(v1[iv1]);
                    iv1++;
                    continue;
                }
                
                if ( v1[iv1].start > merged.back().end)
                    merged.push_back(v1[iv1]);
                else
                    merged.back().end = max(merged.back().end, v1[iv1].end);
                iv1++;
            }
            else
            {
                if (merged.empty()) 
                {
                    merged.push_back(v2[iv2]);
                    iv2++;
                    continue;
                }
                
                if ( v2[iv2].start > merged.back().end)
                    merged.push_back(v2[iv2]);
                else
                    merged.back().end = max(merged.back().end, v2[iv2].end);
                
                iv2++;
            }
        }
        return merged;
        
    }

    // merge sort:
    // merge every two vectors
    // three pointers: one -> merged, one -> v1, and one -> v2
    // compare v1's and v2's start, choose the one with smaller start
    // then compare its start with the merged's end to see whether it needs merging
    // if not -> simply add it to merged, and ++ the index of both vectors
    // if yes -> modify the end of merged's last val
};

