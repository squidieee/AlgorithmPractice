/* 
464. Sort Integers II
Given an integer array, sort it in ascending order. Use quick sort, merge sort, heap sort or any O(nlogn) algorithm.

Example
Given [3, 2, 1, 4, 5], return [1, 2, 3, 4, 5].
*/

class Solution {
public:
    /**
     * @param A: an integer array
     * @return: nothing
     */
    void sortIntegers2(vector<int> &A) {
        // write your code here
        if (A.empty() || A.size()==1) return; 
        //quickSort(A, 0, A.size()-1);
        mergeSort(A, 0, A.size()-1);
    }
    
    // quick sort
    void quickSort(vector<int> &A, int start, int end)
    {
        if (start == end) return;
        
        int pivot = A[start + (end - start) /2];
        
        // partition
        int left(start), right(end);
        while(left <= right)
        {
            while(left <= right && A[left] < pivot)
            {
                left++;
            }
            while(left <= right && A[right] > pivot)
            {
                right--;
            }
            
            if (left <= right)
            {
                swap(A[left], A[right]);
                left++;
                right--;
            }
        }
        
        // recurse
        quickSort(A, start, left - 1); // left is the partition index; right may be invalid index
        quickSort(A, left, end);
    }
    // merge sort
    
    void mergeSort(vector<int> &A, int start, int end)
    {
        if (start == end) return;
        int mid = start + (end-start)/2;
        
        //recurse
        mergeSort(A, start, mid);
        mergeSort(A, mid+1, end);
        
        // merge
        vector<int> temp(end - start + 1);
        
        int left(start),right(mid+1);
        
        for(int i = 0; i < temp.size();i++)
        {
            if ( (A[left] <= A[right] && left <= mid) || right > end)
            {
                temp[i] = A[left];
                left++;
            }
            else
            {
                temp[i] = A[right];
                right++;
            }

        }
        
        // copy array
        for (int i = 0; i < temp.size(); i++)
            A[start + i] = temp[i];
    }
};