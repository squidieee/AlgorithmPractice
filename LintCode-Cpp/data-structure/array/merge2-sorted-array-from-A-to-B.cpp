/* 
64. Merge Sorted Array
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Example
A = [1, 2, 3, empty, empty], B = [4, 5]

After merge, A will be filled as [1, 2, 3, 4, 5]

Notice
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
*/

class Solution {
public:
    /*
     * @param A: sorted integer array A which has m elements, but size of A is m+n
     * @param m: An integer
     * @param B: sorted integer array B which has n elements
     * @param n: An integer
     * @return: nothing
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        if (m < 0 || n <= 0) return;
        
        int ia(m-1), ib(n-1), im(m+n-1);
        
        while(ib >= 0)
        {
            if (A[ia] <= B[ib])
            {
                A[im] = B[ib];
                ib--;
            }
            else
            {
                A[im] = A[ia];
                ia--;
            }
            im--;
        }
    }
    
    // start to fill array A from the back
    // use three pointer to control the index
    // return when ib <0
};