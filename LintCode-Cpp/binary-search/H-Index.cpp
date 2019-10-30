/* 
1304. H-Index

Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

Example
Example1

Input: citations = [3, 0, 6, 1, 5]
Output: 3
Explanation:
The researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.
Example2

Input: citations = [5, 5, 5, 5, 5]
Output: 5
Explanation:
The researcher has 5 papers in total and each of them had received 5, 5, 5, 5, 5 citations respectively. Since the researcher has 5 papers with at least 5 citations, his h-index is 5.
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
        /* Sol2: memo array */
        if (citations.size() < 1) return 0;
        
        vector<int> memo(citations.size() + 1, 0);
        for(int c: citations)
        {
            if (c > citations.size())
            {
                memo[citations.size()]++;
            }
            else
            {
                memo[c]++;
            }
        }
        if (memo.back() >= citations.size()) return citations.size();

        // compute accumulated citations
        int result = 0;
        for(int i = memo.size() - 2; i >= 0; i--)
        {
            memo[i] += memo[i + 1];
            if (memo[i] >= i)
            {
                result = i;
                break;
            }
        }
        
        return result;
        /* Sol1
        if (citations.size() < 1) return 0;
        
        std::sort(citations.begin(), citations.end());
        
        int len = citations.size();
        int start = 0;
        int end = min(len, citations.back());
        while(start + 1 < end)
        {
            int h = start + (end - start)/2;
            if (citations[len - h - 1] > h)
            {
                start = h;
            }
            else
            {
                end = h;
            }
        }
        
        if (len == 0 || citations[len - end] >= end ) return end;
        return start;
        */
    }
};

// Sol1: sort first + binary search (=H-Index II)
// Time O(nlogn + logn)

// Sol2: brutal force
// Time O(n^2)

// Sol3: org numbers in an array from 0 to size - 1
// 0 -> memo[0]++
// 1 -> memo[1]++
// 100 -> memo[size - 1]++
// Then get accumulated result from 0 to size - 1
// when encountering the first accumulation >= index
// return the index
// Time O(n) Space O(n)