/* 
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalL = nums1.size() + nums2.size();
        if (totalL % 2 == 1) // odd
        {
            return findKthElement(nums1, nums2, 0, 0, totalL/2 + 1);
        }
        else //even
            return (findKthElement(nums1, nums2, 0, 0, totalL/2) + findKthElement(nums1, nums2, 0, 0, totalL/2 + 1)) / 2.0;
    }
    
    double findKthElement(vector<int>& n1, vector<int>& n2, int s1, int s2, int k)
    {
        if (s1 >= n1.size()) // all elements of n1 have been removed
            return n2[s2 + k - 1];
        if (s2 >= n2.size()) // all elements of n2 have been removed
            return n1[s1 + k - 1];
        if (k == 1)
            return min(n1[s1], n2[s2]);
        // partition the number of elements before the Kth element: partition it by half
        int idx1 = s1 + k/2 - 1;
        int idx2 = s2 + k/2 - 1;
        
        // if the index goes beyond the size: remove the first k/2 elements of 1st array anyway since there is not enough element in the second array
        int k1 = idx1 >= n1.size()? INT_MAX: n1[idx1]; 
        int k2 = idx2 >= n2.size()? INT_MAX: n2[idx2];
        
        if (k1 > k2)
        {
            return findKthElement(n1, n2, s1, idx2 + 1, k - k/2);
        }
        else
            return findKthElement(n1, n2, idx1 + 1, s2, k - k/2);

    }
};