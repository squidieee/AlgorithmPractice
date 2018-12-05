/* 
486. Merge K Sorted Arrays
Given k sorted integer arrays, merge them into one sorted array.

Example
Given 3 sorted arrays:

[
  [1, 3, 5, 7],
  [2, 4, 6],
  [0, 8, 9, 10, 11]
]
return [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11].

Challenge
Do it in O(N log k).

N is the total number of integers.
k is the number of arrays.
*/


 class Solution {
public:
    /**
     * @param arrays: k sorted integer arrays
     * @return: a sorted array
     */
    vector<int> mergekSortedArrays(vector<vector<int>> &arrays) {
       if (arrays.empty()) return vector<int>();
       
       return mergekSortedArraysHelper(arrays, 0, arrays.size() - 1);
    }
    
    // O(NK) if merge two and return merged one; then merge the merged one with new one
    // O(NlogK) merge sort
    
    vector<int> merge2SortedArray(vector<int>& a, vector<int>& b)
    {
        if (a.empty()) return b;
        if (b.empty()) return a;
        
        vector<int> mergedArray;
        int ia(0), ib(0);
        while(ia < a.size() || ib < b.size())
        {
            if (ib > b.size() - 1 || (ia < a.size() && a[ia] <= b[ib]))
            {
                mergedArray.push_back(a[ia]);
                ia++;
            }
            else
            {
                mergedArray.push_back(b[ib]);
                ib++;
            }
        }
        return mergedArray;
    }
    
    vector<int> mergekSortedArraysHelper(vector<vector<int>> &arrays, int start, int end)
    {
        if (start == end) return arrays[start];
        if (start + 1 == end) return merge2SortedArray(arrays[start], arrays[end]);
        
        int mid = start + (end - start)/2;
        vector<int> firstHalf = mergekSortedArraysHelper(arrays, start, mid);
        vector<int> secondHalf = mergekSortedArraysHelper(arrays, mid+1, end);
        
        return merge2SortedArray(firstHalf, secondHalf);
    }
    
    
};