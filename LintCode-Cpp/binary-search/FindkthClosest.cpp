/* 
460. Find K Closest Elements
Given a target number, a non-negative integer k and an integer array A sorted in ascending order, find the k closest numbers to target in A, sorted in ascending order by the difference between the number and target. Otherwise, sorted in ascending order by number if the difference is same.

Example
Given A = [1, 2, 3], target = 2 and k = 3, return [2, 1, 3].

Given A = [1, 4, 6, 8], target = 3 and k = 3, return [4, 1, 6].

Challenge
O(logn + k) time complexity.

Notice
The value k is a non-negative integer and will always be smaller than the length of the sorted array.
Length of the given array is positive and will not exceed 10^4
Absolute value of elements in the array and x will not exceed 10^4
*/

class Solution {
public:
    /**
     * @param A: an integer array
     * @param target: An integer
     * @param k: An integer
     * @return: an integer array
     */
    vector<int> kClosestNumbers(vector<int> &A, int target, int k) {
        // write your code here
        if (A.empty()) return A;

    vector<int> kclose;

        
    int start(0), end(A.size() - 1), mid;

    while(start + 1 < end)
    {
        mid = start + (end-start)/2;
        
        if (target > A[mid])
        {
            start = mid;
        } 
        else if ( target < A[mid] )
        {
            end = mid;
        } 
        else 
        {
            break;
        }
    }
    
    int left = mid;
    
    if (start + 1 == end)
    {
        left = std::abs(A[start]-target) <= std::abs(A[end]-target)? start:end;
    }
    
    
    int right = left + 1;
    
    while(kclose.size() < k)
    {
        if (isLeftCloser(A, target, left, right))
        {
            kclose.push_back(A[left]);
            left--;
        }
        else
        {
            kclose.push_back(A[right]);
            right++;
        }
        
    }
    return kclose;
    }
    
    bool isLeftCloser(vector<int>& A, int target, int left, int right)
    {
        if (left < 0)
            return false;
        if (right > A.size() - 1)
            return true;
        if (abs(A[left]-target) <= abs(A[right]-target) )
            return true;
        else
            return false;
    }
    
};