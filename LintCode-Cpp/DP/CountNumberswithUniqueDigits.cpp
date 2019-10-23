/* 
1279. Count Numbers with Unique Digits

Given a non-negative integer n, count all numbers with unique digits, x, where 0 \leq x \lt 10^n0≤x<10
​n​ .

Example
Example1

Input: 2
Output: 91
Explanation:
The answer should be the total numbers in the range of 0 ≤ x < 100, excluding `[11,22,33,44,55,66,77,88,99]`)
Example2

Input: 3
Output: 739
*/

class Solution {
public:
    /**
     * @param n: a non-negative integer
     * @return: number of numbers with unique digits
     */
    int countNumbersWithUniqueDigits(int n) {
        if (n < 0) return 0;
        if (n == 0) return 1;
        
        int maxN = std::min(n, 10);
        
        vector<int> fi;
        fi.push_back(10);
        fi.push_back(81);
        for(int i = 3; i <= maxN; i++)
        {
            int currFi = fi.back() * (10 - (i - 1));
            fi.push_back(currFi);
        }
        
        int sumFi = 0;
        for(int i = 0; i < maxN; i++)
        {
            sumFi += fi[i];
        }
        
        return sumFi;
    
    }
};


// a problem of combination:
// i = 0: 1
// i = 1: 10
// i = 2: 9 * (10 - 1) = 81
// i = 3: 9 * (10 - 1) * (10 - 2) = 9 * 9 * 8

// F(i) = 9 * (10 - 1) * (10 - 2) * ... * (10 - (i - 1))
// --------------F(i-1)----------------- 
// F(i) = F(i-1) * (10 - (i-1))