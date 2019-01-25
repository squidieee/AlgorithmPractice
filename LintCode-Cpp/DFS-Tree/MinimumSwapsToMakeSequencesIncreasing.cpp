/*
1016. Minimum Swaps To Make Sequences Increasing
We have two integer sequences A and B of the same non-zero length.

We are allowed to swap elements A[i] and B[i]. Note that both elements are in the same index position in their respective sequences.

At the end of some number of swaps, A and B are both strictly increasing. (A sequence is strictly increasing if and only if A[0] < A[1] < A[2] < ... < A[A.length - 1].)

Given A and B, return the minimum number of swaps to make both sequences strictly increasing. It is guaranteed that the given input always makes it possible.

Example
Input: A = [1,3,5,4], B = [1,2,3,7]
Output: 1
Explanation: 
Swap A[3] and B[3].  Then the sequences are:
A = [1, 3, 5, 7] and B = [1, 2, 3, 4]
which are both strictly increasing.
Notice
1.A, B are arrays with the same length, and that length will be in the range [1, 1000].
2.A[i], B[i] are integer values in the range [0, 2000].
*/

class Solution {
public:
    /**
     * @param A: an array
     * @param B: an array
     * @return: the minimum number of swaps to make both sequences strictly increasing
     */
    int minSwap(vector<int> &A, vector<int> &B) {
        if (A.size() < 2 || B.size() < 2 ) return 0; 
        int result = INT_MAX;
        dfs(A, B, 1, 0, result);
        return result;
    }
    
    // start from index of 1
    void dfs(vector<int> &A, vector<int> &B, int i, int curr, int& ans)
    {
        if (curr >= ans) return; // trimming, no need to run if curr > ans
        
        if ( i >= A.size() )
        {
            ans = min(ans, curr); // push it to answer only when reaching the end
            return;
        }
        
        int cnt1(INT_MAX), cnt2(INT_MAX);
        
        if (A[i] > A[i-1] && B[i] > B[i-1])
        {
            dfs(A, B, i + 1, curr, ans);
        }
        
        if (A[i] > B[i-1] && B[i] > A[i-1])
        {
            std::swap(A[i], B[i]);
            dfs(A, B, i + 1, curr+1, ans);
            std::swap(A[i], B[i]);
        }
    }
};

// dfs: brutal force
// time limit exceeds
// but a good practice for a dfs
// keep a curr and best answer so far as ans
// record curr as ans if reaching the end of array
// if any branch has curr >= ans, there is no need to run since it must not be the best answer

// dp version:
// TODO
