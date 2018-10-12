/* 
140. Fast Power
Calculate the an % b where a, b and n are all 32bit integers.

Example
For 231 % 3 = 2

For 1001000 % 1000 = 0

Challenge
O(logn)
*/

class Solution {
public:
    /**
     * @param a: A 32bit integer
     * @param b: A 32bit integer
     * @param n: A 32bit integer
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code here
        if (b==0) return -1;
        if (a==0) return 0;
        if (b==1) return 0;
        
        return halfpower(a,b,n);
    }
    
    int halfpower(int a, int b, int n)
    {
        if (n==0) return 1;
        if (n==1) return a % b;
        
        long result = halfpower(a,b,n/2); /// use long to avoid overflow
        result = (result * result) % b; 
        if (n%2==1) result = result * (a % b);
        result = result % b;
        
        return (int) result;
    }

};