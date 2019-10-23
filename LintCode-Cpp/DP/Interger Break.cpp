/* 
1284. Integer Break

Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

Example
Example1

Input: 2
Output: 1
Explanation: 2 = 1 + 1
Example2

Input: 10
Output: 36
Explanation: 10 = 3 + 3 + 4
Notice
You may assume that n is not less than 2 and not larger than 58.
*/

class Solution {
public:
    /**
     * @param n: a positive integer n
     * @return: the maximum product you can get
     */
    int integerBreak(int n) {
        if (n < 2 || n >= 58) return -1;
        
        vector<int> fi(n);
        fi[0] = 1;
        fi[1] = 1;
        for(int i = 3; i <= n; i++)
        {
            int currMax = i - 1; 
            for(int x = 2; x <= i/2; x++)
            {
                int subMax = max(i - x, fi[i - x - 1]);
                currMax = max(currMax, x * subMax);
            }
            fi[i - 1] = currMax;
        }
        
        return fi[n-1];
    }
};

// state:
// fi is the max product of the intergers broken down from the number i
// function:
// f[i] = max (x * max (i-x, f[i-x])), x >= 2 && x <= i/2
// buttom-up