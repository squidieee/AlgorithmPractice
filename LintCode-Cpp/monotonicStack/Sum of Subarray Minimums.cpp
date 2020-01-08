/* 
1734. Sum of Subarray Minimums

Given an array of integers A, find the sum of min(B), where B ranges over every (contiguous) subarray of A.

Since the answer may be large, return the answer modulo 10^9 + 7.

Example
Example 1:

Input: [3,1,2,4]
Output: 17
Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.
Example 2:

Input: [95,58,46,67,100]
Output: 859
Explanation: Subarrays are [95], [58], [46], [67], [100], [98,58], [58,46], [46,67], [67,100], [95,58,67],[46,67,100],[95,58,46,67],[58,46,67,100],[95,58,46,67,100]. 
Minimums are 95, 58, 46, 67, 100, 58, 46, 46, 67, 46, 46, 46, 46, 46, 46.  Sum is 859.
Notice
1 \leq A \leq 300001≤ A ≤30000
1 \leq A[i] \leq 300001≤ A[i] ≤30000
*/

class Solution {
public:
    /**
     * @param A: an array
     * @return: the sum of subarray minimums
     */
    int sumSubarrayMins(vector<int> &A) {
        stack<int> monostk;
        
        const int MOD = 1e9 + 7;
        int result(0);
        for(int i = 0; i <= A.size(); i++)
        {
            while(!monostk.empty() && A[monostk.top()] > (i ==  A.size() ? 0 : A[i] ))
            {
                int currIdx = monostk.top();
                monostk.pop();
                // left: number of elements > A[currIdx] on the left side of curr element
                int left = currIdx - ( monostk.empty()? 0 : (monostk.top() + 1) ); 
                int right = i - currIdx - 1;
                result = (result % MOD + A[currIdx] * (left + right + left * right + 1) % MOD) % MOD;
            }
            
            monostk.push(i);
        }
        
        return result;
    }
};

// brutal force: 
// find all continuous subarray: O(n^2)

// monotonic stack:
// mono-increasing from bottom to top 
// if meeting A[i] < stack top 
// pop stack top and compute number of elements based on the range: curr stack top as left and i as right boundary
