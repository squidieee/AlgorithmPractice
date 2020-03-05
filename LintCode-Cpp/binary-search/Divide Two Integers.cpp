/* 
414. Divide Two Integers

Divide two integers without using multiplication, division and mod operator.

If it will overflow(exceeding 32-bit signed integer representation range), return 2147483647

The integer division should truncate toward zero.

Example
Example 1:

Input: dividend = 0, divisor = 1
Output: 0
Example 2:

Input: dividend = 100, divisor = 9
Output: 11
*/

class Solution {
public:
    /**
     * @param dividend: the dividend
     * @param divisor: the divisor
     * @return: the result
     */
    int divide(int dividend, int divisor) {
        if(divisor == 0) return INT_MAX;
        if( dividend >= 0 && divisor > 0 && dividend < divisor) return 0;
        if( dividend <= 0 && divisor < 0 && dividend > divisor) return 0;
        
        bool sameSign = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);
        long abs_dividend = std::abs((long) dividend);
        long abs_divisor = std::abs((long) divisor);
        
        long ub_mult = 1;
        long ub_div = abs_divisor;
        while(ub_div < abs_dividend)
        {
            ub_div = ub_div << 1;
            ub_mult = ub_mult << 1;
        }
        
        long lb_div = ub_div >> 1;
        long lb_mult = ub_mult >> 1;
        
        while(lb_div + 1 < ub_div)
        {
            long target = (lb_div + ub_div) >> 1;
            if(target > abs_dividend)
            {
                ub_div = target;
                ub_mult = (lb_mult + ub_mult) >> 1;
            }
            else
            {
                lb_div = target;
                lb_mult = (lb_mult + ub_mult) >> 1;
            }
        }
        
        // prevent overflow: int = [-2147483648, 2147483647]
        if(ub_div <= abs_dividend) return sameSign? min(ub_mult, (long) INT_MAX): -ub_mult;
        return sameSign? min(lb_mult, (long) INT_MAX):-lb_mult;
    }

/*FIRST PASS: NOT PASSED*/
/*
    int divide(int dividend, int divisor) {
        if (divisor == 0) return 2147483647;

        int m = std::abs(dividend);
        int n = std::abs(divisor);

        if (dividend == 0 || m < n) return 0;

        int answer = 0;
        
        while( m >= n )
        {
            int shift = 0;
            // find the upperbound
            while(m >= (n << shift))
            {
                shift++;
            }
            // once find the upperbound
            // subtract the lowerbound
            if (shift > 0)
            {
                 m = m - n << (shift - 1);
                answer += 1 << (shift - 1);               
            }

        }

        
        bool sign = ((dividend > 0) && (divisor > 0)) ||
                    ((dividend < 0) && (divisor < 0)) ? 1:-1;
        
        return sign? answer:-answer;
    }
    
    // linear:
    // keep adding abs(divisor) until the added val > abs(dividend)
    // keep track of the times of adding
    // if adding linearly one by one of the divisor: n * k > m => O(m/n)
    // if double the divisor each time: 2^k *n > m => O(log(m/n))
    
    // further improvement:
    // when after finding the upperbound, 
    // start binary search again by subtracting the lowerbound
*/
};