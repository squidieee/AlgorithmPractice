/* 
235. Prime Factorization
Prime factorize a given integer.

Example
Given 10, return [2, 5].

Given 660, return [2, 2, 3, 5, 11].

Notice
You should sort the factors in ascending order.
*/

class Solution {
public:
    /**
     * @param num: An integer
     * @return: an integer array
     */
    vector<int> primeFactorization(int num) {
       vector<int> results;
       primeFactorizationHelper(num, results);
       return results;
    }
    
    void primeFactorizationHelper(int num, vector<int>& factors)
    {
        if (num == 1) return;
        
        int f;
        int upperBound = std::sqrt(num);
        for(f = 2; f <= upperBound; f++)
        {
            if ( num % f == 0 )
            {
                factors.push_back(f);
                primeFactorizationHelper( num / f , factors);
                break;
            }
        }
        
        if (f > upperBound) factors.push_back(num);
    }
    
    // prime number:
    // 1, 2, 3, 5, 7 ...
    // how to define a prime number?
    // it can only be divided by 1 or itself to get mod = 0
    // all prime numbers smaller than the given num could be its factor
    // A1:
    // for factor = 2 : num-1, see if num % factor == 0
    // -> once satisfy, recursively call the function again with num/factor
    // it will not push natural numbers since they are composed by factors smaller
    // than them
    // Improvement:
    // reduce upperBound of for loop from num - 1 to sqrt(num)
    // reason: sqrt(num) * sqrt(num) = num
    // so if num is a natural number:
    // num = a * b: either a = b or a != b
    // in the case of a!= b, one of a and b must < sqrt(num) in order to satisfy
    // num = a * b = sqrt(num) * sqrt(num)
    // so there must exist at least one factor < sqrt(num)
};