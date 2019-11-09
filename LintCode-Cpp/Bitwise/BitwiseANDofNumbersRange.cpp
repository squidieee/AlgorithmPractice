/* 
1325. Bitwise AND of Numbers Range

Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.

Example
Example1

Input: m=5, n=7
Output: 4
Example2

Input: m=14, n=15
Output: 14
*/

class Solution {
public:
    /**
     * @param m: an Integer
     * @param n: an Integer
     * @return: the bitwise AND of all numbers in [m,n]
     */
    int rangeBitwiseAnd(int m, int n) {
        int bits = 0;
        while(m!=n)
        {
            m = m >> 1;
            n = n >> 1;
            bits++;
        }
        return m << bits;
        
        /* WRONG
        if (m==n) return m;
        int result = m & n;
        int bits = 0;
        
        while( ((result + 1) & result) != 0)
        {
            result = result >> 1;
            bits++;
        }

        return (result << bits);
        */
    }
};

// 5: 0101
// 6: 0110
// 7: 0111
//    0100
// common: left bits
// right bits will become 0
// m = 0101, n = 0111
// common left bits is 0100
// note common left bits do not have to be all 11111s, it can also be 110101..
