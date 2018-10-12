/* 
428. Pow(x, n)
Implement pow(x, n).

Example
Pow(2.1, 3) = 9.261
Pow(0, 1) = 0
Pow(1, 0) = 1
Challenge
O(logn) time

Notice
You don't need to care about the precision of your answer, it's acceptable if the expected answer and your answer 's difference is smaller than 1e-3.
*/

class Solution {
public:
    /**
     * @param x: the base number
     * @param n: the power number
     * @return: the result
     */
    double myPow(double x, int n) {
        // write your code here
        if (x==0) return 0;
        if (x!=0 && n == 0) return 1; 
        
        if(n>=0)
            return powPositive(x,n);
        else
           return powPositive(1/x, -n);
    }
    
       double powPositive(double x, int n) {
        if (n==0) return 1;
        double prev = powPositive(x, n/2);
        double current = prev * prev;
        if (n%2!=0) current = current * x;
        return current;
    }
};