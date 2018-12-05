/* 
462. Total Occurrence of Target
Given a target number and an integer array sorted in ascending order. Find the total number of occurrences of target in the array.

Example
Given [1, 3, 3, 4, 5] and target = 3, return 2.

Given [2, 2, 3, 4, 6] and target = 4, return 1.

Given [1, 2, 3, 4, 5] and target = 6, return 0.

Challenge
Time complexity in O(logn)
*/

class Solution {
public:
    /**
     * @param A: A an integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int totalOccurrence(vector<int> &A, int target) {
        if (A.empty()) return 0;
        int start(0),end(A.size() - 1);
        
        while(start + 1 < end)
        {
            int mid = start + (end - start)/2;
            if (target > A[mid])
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        
        int anchor = (A[start] == target) ? start:end;
        int left(anchor), right(anchor + 1);
        
        int cnt(0);
        while(( right < A.size() && A[right] == target) || (left >= 0 && A[left] == target))
        {
            if ( right > A.size() - 1 || A[right] != target || left < 0 || A[left] != target)
            {
                cnt++;
            }
            else
            {
                cnt+=2;
            }
            
            right++;
            left--;
        }
        
        return cnt;
    }
    
    // binary search the target O(logn)
    // check left and right from the target with the same number O(k)
    // Total Time O(logn + k)
};