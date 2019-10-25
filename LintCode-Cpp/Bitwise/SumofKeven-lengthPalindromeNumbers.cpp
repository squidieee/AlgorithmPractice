/* 
744. Sum of first K even-length Palindrome numbers
Given a integer k, find the sum of first k even-length palindrome numbers.
Even length here refers to the number of digits of a number is even.

Example
Given k = 3, return 66 // 11 + 22 + 33 = 66 (Sum of first three even-length palindrome
numbers)

Given k = 10, return 1496
// 11 + 22 + 33 + 44 + 55 + 66 + 77 + 88 + 99 + 1001 = 1496
*/

class Solution {
public:
    /**
     * @param k: Write your code here
     * @return: the sum of first k even-length palindrome numbers
     */
    int sumKEven(int k) {
        if (k == 0) return 0;
        
        int base10 = 10;
        int ans(0);
        int num = 1;
        while(k > 0)
        {
            if (num == base10)
            {
                base10 *= 10;
            }
            ans += base10 * num + reverse(num);
            num++;
            k--;
        }
        return ans;
    }
    
    int reverse(int num)
    {
        int ans(0);
        while (num > 0)
        {
            ans = ans * 10; // shift left
            ans += num % 10;
            num = num / 10;
        }
        return ans;
    }
};
// brutal force:
// O(NP): add if num is even number palindrome until we find the answer

// 11 -> 10 + 01 : 1 * 10 + 1
// 22 -> 20 + 02 : 2 * 10 + 2
// ...
// 99 -> 90 + 09 : 9 * 10 + 9
// 1001 -> 1000 + 0001 : 10 * 100 + 01
// 1111 -> 1100 + 0011 : 11 * 100 + 11
// ...
// 2002 -> 2000 + 0002 : 20 * 100 + 02
// ...
// 100001 -> 100 * 1000 + 001
