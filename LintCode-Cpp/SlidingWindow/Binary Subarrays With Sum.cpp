/* 
1712. Binary Subarrays With Sum

In an array A of 0s and 1s, how many non-empty subarrays have sum S?

Example
Example 1:

Input: A = [1,0,1,0,1], S = 2
Output: 4
Explanation: 
The 4 subarrays are bolded below:
[1,0,1]
[1,0,1]
[1,0,1,0]
[0,1,0,1]
Example 2:

Input: A = [0,0,0,0,0,0,1,0,0,0], S = 0
Output: 27
Explanation: 
And 27 subarrays for S.
Notice
A.length <= 30000
0 <= S <= A.length
A[i] is either 0 or 1.

*/

class Solution {
public:
    /**
     * @param A: an array
     * @param S: the sum
     * @return: the number of non-empty subarrays
     */
    int numSubarraysWithSum(vector<int> &A, int S) {
        /*
        unordered_map<int, int> prefix;
        int currSum = 0;
        int result = 0;
        
        prefix[0] = 1;
    
        for(int num: A)
        {
            currSum += num;
            if( currSum - S >= 0 ) result += prefix[currSum - S];
            prefix[currSum]++;
        }
        return result;
        */
        return slidingWindowSol(A, S);
    }
    
    int slidingWindowSol(vector<int> &A, int S)
    {
        int i_start(0), i_end(0), j(0), result(0);
        int sum1(0), sum2(0);
        while(j < A.size())
        {
            
            // lowerbound
            sum1 += A[j];
            while(sum1 > S && i_start < j)
            {
                sum1 -= A[i_start++];
            }
            
            // upperbound
            sum2 += A[j];  
            while( (sum2 > S || A[i_end] == 0) && i_end < j)
            {
                sum2 -= A[i_end++];
            }            
            
            if(sum1 == S) result += i_end - i_start + 1; //  i_end >= i >= i_start
            j++;            
        }
        return result;
    }
    
    
    
};

// record prefixSum in a hashmap
// prefixSum as key, number of such prefix as val 