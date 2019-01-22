/* 
62. Search in Rotated Sorted Array
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Example
For [4, 5, 1, 2, 3] and target=1, return 2.

For [4, 5, 1, 2, 3] and target=0, return -1.

Challenge
O(logN) time
*/
class Solution {
public:
    /**
     * @param A: an integer rotated sorted array
     * @param target: an integer to be searched
     * @return: an integer
     */
    int search(vector<int> &A, int target) {
        if (A.empty()) return -1;
        // first to find start of second
        int start(0), end(A.size() - 1);
        while(start + 1 < end)
        {
            int mid = start + (end - start)/2;
            if (A[mid] > A.back())
                start = mid;
            else
                end = mid;
        }
        
        start = A[start] < A[end] ? start:end;
        
        // second to find the target
        // special case: non-rotated array
        if (start == 0) 
        { 
            end = A.size() - 1;
        }
        else
        {
            if (target > A.back()) // first half
            {
                end = start - 1;
                start = 0;
            }
            else
                end = A.size() - 1;
        }
        
        
        while(start + 1 < end)
        {
            int mid = start + (end - start)/2;
            if (A[mid] > target)
                end = mid;
            else
                start = mid;
        }
        
        if (A[start] == target) return start;
        if (A[end] == target) return end;
        return -1;
    }
    
    // O(n), do a pass
    // binary search O(lgn)
    // array is partitioned into two halves
    // if target > A.back(): in the first half
    // otherwise in second half
    // we need to first know the partitioned location (start of second)
    
    /// FIRST PASS
    /*
    int search(vector<int> &A, int target) {
        if (A.empty()) return -1;
        
        // step1: find minimum index
        int start = findMin(A);
        int end;
        // step2: find target in SubArray
        if (start == 0) // non-rotated array
        {
            end = A.size()-1;
        }
        else // rotated array
        {
            if (target >= A[start] && target <= A[A.size()-1])
                end = A.size()-1;
            else if (target >= A[0] && target <= A[start - 1])
            {
                end = start - 1;
                start = 0;
            }
            else
                return -1;
        }
        
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
        
        if (A[start]==target) return start;
        if (A[end]==target) return end;
        return -1;
        
    }
    
    
    int findMin(vector<int> &A)
    {
        int start(0), end(A.size()-1);
        int last = A[end];
        while (start + 1 < end)
        {
            int mid = start + (end - start)/2;
            if (A[mid] > last)
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        
        return A[start] > A[end] ? end:start; 
    }
*/
};