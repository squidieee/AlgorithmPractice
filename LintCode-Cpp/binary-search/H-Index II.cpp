/* 
1303. H-Index II

Given an array of citations sorted in ascending order (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

Example
Input: citations = [0,1,3,5,6]
Output: 3 
Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had 
             received 0, 1, 3, 5, 6 citations respectively. 
             Since the researcher has 3 papers with at least 3 citations each and the remaining 
						 two with no more than 3 citations each, her h-index is 3.
Challenge
This is a follow up problem to H-Index, where citations is now guaranteed to be sorted in ascending order.
Could you solve it in logarithmic time complexity?
Notice
If there are several possible values for h, the maximum one is taken as the h-index.
*/

class Solution {
public:
    /**
     * @param citations: a list of integers
     * @return: return a integer
     */
    int hIndex(vector<int> &citations) {
        int len = citations.size();
        if (len < 1) return 0;
        
        int start = 0;
        int end = min(citations.back(), len);
        while(start + 1 < end)
        {
            int h = start + (end - start) /2;
            
            // increase h 
            if (citations[len - h - 1] > h)
            {
                start = h;
            }
            else
            {
                end = h;
            }
        }
        
        if (validH(citations, end)) return end;
        return start;
    }
    
    bool validH(vector<int> &citations, int h)
    {
        int len = citations.size();

        return (h == 0 || citations[len - h] >= h) && ( len == h || citations[len - h - 1] <= h);
    }
};

// Range: 0 to min(citations.back(), citations.size())
// goal: find h that meets the requirement
// brutal force: linearly search from 0 to citations.back() until the first one fails
// Time O(n)
// How to see if a number h is good? 
// citations[len - h] >= h && citations[len - h - 1] <= h
// When to increase h?
// citations[len - h - 1] > h 
// no need to worry when h = len or h = 0 since it will quit while() before h = len

// sorted: binary search 
// Time O(lgn)

