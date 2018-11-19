/* 
1645. Least Subsequences
Given an array with n integers. Splitting it into subsequences of strictly descending order.
Output the minimum number of subsequences you can get by splitting.

Example
Input: [5,2,4,3,1,6]
Output: 3

Explanation:
 You can split this array into : [5,2,1], [4,3], [6]. And there are 3 subsequences you get.﻿ 
Or you can split it into [5, 4, 3],[2,1], [6] also 3 subsequences.
But [5, 4, 3, 2, 1], [6] is not legal because [5, 4, 3, 2, 1] is not a subsuquence of the original array.
input: [1, 1, 1]
Output: 3
Explanation: Because of the strictly descending order you must split it into 3 subsequences: [1],[1],[1]
Challenge
Deal it with the complexity: o(nlogn)
*/

class Solution {
public:
    /**
     * @param arrayIn: The original array.
     * @return: Count the minimum number of subarrays.
     */
    int LeastSubsequences(vector<int> &arrayIn) {
        // Ver 1
        // [] => 0 or [1] => [1]
        // [1 2] => [1] [2]
        // [5 2 4 3 1 6] => [5]
        // +2 => [5 2]
        // +4 => [5 2] [4]
        // +3 => [5 2] [4 3]
        // +1 => [5 2 1] [4 3]
        // +6 => [5 2 1] [4 3] [6]
        // until i > size
        // Time O(n^2)
        //
        // Ver 2
        // binary search through all last lastVals
        // Time O(nlogn))
        
        if (arrayIn.empty()) return 0; 
        if (arrayIn.size() == 1) return 1;
        
        vector<int> lastVals;
        lastVals.push_back(arrayIn[0]);
        
        for(int i = 1; i < arrayIn.size(); i++)
        {
            int start(0), end(lastVals.size() - 1);
            while(start + 1 < end)
            {
                int mid = start + (end - start)/2;
                if (arrayIn[i] > lastVals[mid])
                {
                    start = mid;
                }
                else if (arrayIn[i] < lastVals[mid])
                {
                    end = mid;
                }
                else // find the last one if there are lots repeats
                {
                    start = mid;
                }
            }
            
            if (arrayIn[i] < lastVals[start])
            {
                lastVals[start] = arrayIn[i];
            }
            else if (arrayIn[i] < lastVals[end])
            {
                lastVals[end] = arrayIn[i];
            }
            else
            {
                if ( end < lastVals.size() - 1 )
                    lastVals[end + 1] = arrayIn[i]; // if end is not the end of lastVals, then modify the next val
                else
                    lastVals.push_back(arrayIn[i]); // arrayIn[i] >= all our vals
            }

        }
        
        return lastVals.size();
    }
};