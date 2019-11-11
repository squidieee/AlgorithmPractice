/* 
1351. Fraction to Recurring Decimal

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example
Example1

Input: numerator = 1, denominator = 2
Output: "0.5"
Example2

Input: numerator = 2, denominator = 3
Output: "0.(6)"
*/

class Solution {
public:
    /**
     * @param numerator: a integer
     * @param denominator: a integer
     * @return: return a string
     */
    string fractionToDecimal(int numerator, int denominator) {
        bool isNeg = (numerator > 0 && denominator < 0) ||
                     (numerator < 0 && denominator > 0);
        unordered_map<int, int> map;
        long long num = abs((long long) numerator);
        long long den = abs((long long) denominator);
        long long residue = num % den;
        string result = to_string(num / den);
        if (residue == 0)
        {
            return isNeg? "-" + result : result;
        }
        
        result += ".";
        int pos = result.size();
        while(residue != 0)
        {
            if (map.find(residue) != map.end())
            {
                result.insert(map[residue], "(");
                result += ")";
                return isNeg? "-" + result : result;
            }
            map[residue] = pos;
            result = result + to_string((residue * 10) / den);
            residue = (residue * 10) % den;
            pos++;
        }
        
        return isNeg? "-" + result : result;
    }
};

// Sol1: hash map
// for any nume & deno: get fractional part by:
// nume = (nume  * 10 % deno);  
// then frac = nume / deno
// if nume % deno == 0, then there is not repeated part
// otherwise get the next factional number by updating nume = nume % deno

// how to tell whether it is repeated?

// WRONG:
// store the pattern in a string
// ex: 1/6 = 0.166666
// repeated part starts at second fractional decimal
// so we need to store all potential patterns from the last one to all prev
// and compre it to all prev ones

// CORRECT:
// store nume % deno as key 
// if nume % deno is the same as any prev residue
// it means the rest of fraction will repeat