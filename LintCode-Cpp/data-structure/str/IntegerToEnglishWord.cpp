/* 
1305. Integer to English Words
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 2^31 - 1.

Example
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
*/

class Solution {
public:
    /**
     * @param num: a non-negative integer
     * @return: english words representation
     */
    string numberToWords(int num) {
        vector<string> nums1 = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine","Ten", "Eleven", "Twelve","Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> nums2 = {"", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string units[5] = {"", " Thousand", " Million", " Billion"};
        
        if ( num == 0) return "Zero";
        
        string result;
        int cnt(0);
        while (num > 0)
        {
            string sub = convertThousandToString(num, nums1, nums2);
            if (sub != "")
            {
                result = sub + units[cnt] + put_space(result) + result;
            }
            num = num / 1000;
            cnt++;
        }
        return result;
    }
    
    string convertThousandToString(int num, vector<string>& nums1, vector<string>& nums2)
    {
        string result;
        
        num = num % 1000; // make sure num < 1000
        int hundred = num / 100; // get hundred
        if (hundred > 0)  result = nums1[hundred - 1] + " Hundred";
        
        // get the rest
        int residue = num - hundred * 100;
        if (residue < 1) return result;
        
        if (residue < 20)
        {
            result += put_space(result) + nums1[residue - 1];
        }
        else
        {
            result += put_space(result) + nums2[residue / 10 - 1];
            if (residue % 10 > 0) result += put_space(result) + nums1[residue % 10 - 1];
        }
        
        return result;
    }
    
    inline string put_space(string& str)
    {
        return str == "" ? "" : " ";
    }
};

// need an array for words
// need an array for units

// get each digit:
// convert it into sub problem: express a number < 1000;
// then use it in each 1000
// note that space can be messy