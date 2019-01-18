/* 
130. Heapify
Given an integer array, heapify it into a min-heap array.

For a heap array A, A[0] is the root of heap, and for each A[i], A[i * 2 + 1] is the left child of A[i] and A[i * 2 + 2] is the right child of A[i].
Example
Given [3,2,1,4,5], return [1,2,3,4,5] or any legal heap array.

Challenge
O(n) time complexity

Clarification
What is heap?

Heap is a data structure, which usually have three methods: push, pop and top. where "push" add a new element the heap, "pop" delete the minimum/maximum element in the heap, "top" return the minimum/maximum element.

What is heapify?
Convert an unordered integer array into a heap array. If it is min-heap, for each element A[i], we will get A[i * 2 + 1] >= A[i] and A[i * 2 + 2] >= A[i].

What if there is a lot of solutions?
Return any of them.
O(logn)
*/

class Solution {
public:
    /*
     * @param A: Given an integer array
     * @return: nothing
     */
    void heapify(vector<int> &A) {
        if (A.empty()) return;
        
        // sift-up
        // compare with parent, doing it in ascending order makes sure the swapped node can be re-visited later
        // also it is a local -> global sorting; equivalent to adding nodes to a "locally sorted" heap
        //for(int i = 1; i < A.size() ; i++)  
        //{
        //    siftup(A, i);
        //}
        
        // sift-down
        // compare with min(two-children)
        // starts from internal nodes: 
        // The number of internal nodes in a complete binary tree of n nodes is n/2
        for(int i = (A.size()-1)/2; i >= 0; i--)
        {
            siftdown(A,i);
        }
    }
    
    void siftup(vector<int> &A, int k)
    {
        while(k!=0)
        {
            int parent = (k - 1)/2;
            
            if (A[k] <= A[parent])
            {
                std::swap(A[k], A[parent]);
                k = parent;
            }
            else
                break; // in the right spot
        }
    }
    
    void siftdown(vector<int> &A, int k)
    {
        while(k < A.size())
        {
            int leftChild = numeric_limits<int>::max();
            int rightChild = numeric_limits<int>::max();
            if ( 2*k + 1 < A.size()) leftChild = A[ 2*k + 1];
            if ( 2*k + 2 < A.size()) rightChild = A[ 2*k + 2];
            
            int nextK = leftChild > rightChild? 2*k + 2 : 2*k + 1;
            
            if (A[k] > std::min(leftChild, rightChild)) 
            {
                std::swap(A[k], A[nextK]);
                k = nextK;
            }
            else
                break;
        }
    }
    
};