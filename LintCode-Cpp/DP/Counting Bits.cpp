/* 
664. Counting Bits

Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example
Example1

Input: 5
Output: [0,1,1,2,1,2]
Explanation:
The binary representation of 0~5 is:
000
001
010
011
100
101
the count of "1" in each number is: 0,1,1,2,1,2
Example2

Input: 3
Output: [0,1,1,2]
Challenge
It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

*/

class Solution {
public:
    /**
     * @param num: a non negative integer number
     * @return: an array represent the number of 1's in their binary
     */
    vector<int> countBits(int num) {
        vector<int> ans(num + 1, 0);
        int next_two_power = 2;
        ans[1] = 1;
        for(int i = 2; i <= num; i++)
        {
            if(i == next_two_power) 
            {
                ans[i] = 1;
                next_two_power *= 2;
            }
            else
            {
                int curr_two_power = next_two_power / 2;
                ans[i] = ans[curr_two_power] + ans[i - curr_two_power];
            }
        }
        
        return ans;
    }
};
