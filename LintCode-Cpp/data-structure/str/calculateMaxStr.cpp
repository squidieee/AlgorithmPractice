/* 
719. Calculate Maximum Value
Given a string of numbers, write a function to find the maximum value from the string, you can add a + or * sign between any two numbers.

Example
Given str = 01231, return 10
((((0 + 1) + 2) * 3) + 1) = 10 we get the maximum value 10

Given str = 891, return 73
As 8 * 9 * 1 = 72 and 8 * 9 + 1 = 73 so 73 is maximum.
*/

class Solution {
public:
    /**
     * @param str: the given string
     * @return: the maximum value
     */
    int calcMaxValue(string &str) {
        if (str.size() < 1) return 0;
        int result = ch2Num(str[0]);
        for(int i = 1; i < str.size(); i++)
        {
            if (result > 1 && str[i] > '1')
            {
                result = result * ch2Num(str[i]);
            }
            else
            {
                result += ch2Num(str[i]);
            }
        }
        return result;
    }
    
    inline int ch2Num(char ch)
    {
        return ch -'0';
    }
};

// if all numbers are between 0 and 9
// and the sequence needs to be the same
// if num > 1, multiply
// other wise add