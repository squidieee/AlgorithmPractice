/* 
839. Merge Two Sorted Interval Lists
Merge two sorted (ascending) lists of interval and return it as a new sorted list. The new sorted list should be made by splicing together the intervals of the two lists and sorted in ascending order.

Example
Given list1 = [(1,2),(3,4)] and list2 = [(2,3),(5,6)], return [(1,4),(5,6)].

Notice
The intervals in the given list do not overlap.
The intervals in different lists may overlap.
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
     * @param list1: one of the given list
     * @param list2: another list
     * @return: the new sorted list of interval
     */
    vector<Interval> mergeTwoInterval(vector<Interval> &list1, vector<Interval> &list2) {
        if (list2.empty()) return list1;
        if (list1.empty()) return list2;
        
        vector<Interval> result;
        
        int i1(0), i2(0);
        
        while( i1 < list1.size() || i2 < list2.size())
        {
            if (i1 > list1.size() - 1)
            {
                mergeHelper(result, list2, i2);
                i2++;
                continue;
            }
            
            if (i1 > list1.size() - 1)
            {
                mergeHelper(result, list1, i1);
                i1++;
                continue;
            }
            
            if ( list1[i1].start > list2[i2].start)
            {
                mergeHelper(result, list2, i2);
                i2++;
            }
            else
            {
                mergeHelper(result, list1, i1);
                i1++;
            }
        }
        
        return result;
    }
    
    // compare two interval:
    // case 1: merge: min(S1, S2) max(E1, E2)
    // (S2 >= S1 && S2 <= E1) || (S1 >= S2 && S1 <= E2)
    // case 2: independent
    void mergeHelper(vector<Interval>& result, vector<Interval>& list2, int i2)
    {
        if (result.empty())
        {
            result.push_back(list2[i2]);
            return;
        }
            
        Interval& int1 = result.back();
        Interval& int2 = list2[i2];
        
        if ( ( int1.start >= int2.start && int1.start <= int2.end) || ( int2.start >= int1.start && int2.start <= int1.end) )
        {
            int1.start = min(int1.start, int2.start);
            int1.end = max(int1.end, int2.end);
        }
        else
        {
            result.push_back(list2[i2]);
        }
    }
    


};