/* 
61. Search for a Range
Given a sorted array of n integers, find the starting and ending position of a given target value.

If the target is not found in the array, return [-1, -1].

Example
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

Challenge
O(log n) time.
*/

class Solution {
public:
    /**
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: a list of length 2, [index1, index2]
     */
    vector<int> searchRange(vector<int> &A, int target) {
        vector<int> result(2, -1);
        if (A.empty()) return result;
        
        int start(0), end(A.size() - 1);
        while(start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            if (target > A[mid])
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        
        int left(-1), right(-1);
        if (A[end] == target)
        {
            left = end;
        }
        
        if (A[start] == target)
        {
            left = start;
        }
        
        if (left == -1) return result;
        
        right = left + 1;

        while( left >= 0 && A[left] == target)
        {
            left--;
        }

        while( right < A.size() && A[right] == target)
        {
            right++;
        }

        result[0] = left + 1;
        result[1] = right - 1;
        
        return result;
    }
    
    
    // Brutal Force: Linear Time O(n)
    // Binary search O(logn)
    // first binary search, either start or end find one
    // then do a two pointer till either not equal or out of range
};