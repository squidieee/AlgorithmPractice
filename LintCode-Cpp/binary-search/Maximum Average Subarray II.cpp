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

/// WRITE WITHOUT TEST
// if n >= 0:
double power(double x, int n)
{
  if (n == 0) return 1;
  if (n == 1) return x;
  
  double result = power(x, n/2);
  result = result * result;
  if (n%2 == 1)
  {
    result = result * x;
  }
  
  return result;
}

// if n <= 0:
// do the same thing but with 1/x


// -------------
// if brutal force:
// y = y * x
// O(n)
// exponetial:
// x = x * x
// x, x^2, x^4, .. 8
// keep track on k <= n
// lowerbound, upperbound
// range of int range: upperbound
// meet lowerbound: linear until n?
// x^n = x^lb * x^(n - lb)
// call it again with new n as n - lb?

// think from the result, not the beginning
// n == even
// x^n = x^(n/2) * x^(n/2)
// x^(n/2) = x^(n/4) * x^(n/4)
// ...
// n == odd
// x^n = x * x^(n/2) * x^(n/2)
// n == 0: 1
// n == 1: fine
// n == 2: fine