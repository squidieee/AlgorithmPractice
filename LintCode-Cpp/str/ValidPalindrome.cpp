/* 
415. Valid Palindrome
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example
"A man, a plan, a canal: Panama" is a palindrome.

"race a car" is not a palindrome.

Challenge
O(n) time without extra memory.

Notice
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/
class Solution {
public:
    /**
     * @param s: A string
     * @return: Whether the string is a valid palindrome
     */
    bool isPalindrome(string &s) {
        // write your code here
        if (s.empty()) return true;
        if (s.length()==1) return true;
        
        int start(0), end(s.length()-1);
        while (start <= end) // tocheck
        {
            if (!isAlpnum(s[start]))
            {
                start++;
                continue;
            }
            if (!isAlpnum(s[end]))
            {
                end--;
                continue;
            }
            if (isEqual(s[start], s[end]))
            {
                start ++;
                end --;
            }
            else
                return false;
        }
        
        return true;
    }
    
    bool isEqual(char a, char b)
    {
        if (a == b)
            return true; 
        if ((a >= 'A' && a <= 'Z') && (b - a == 32))
            return true;
        if ((b >= 'A' && b <= 'Z') && (a - b == 32))
            return true;
        return false;
    }
    
    bool isAlpnum(char c)
    {
        if (c >= 'a' && c <= 'z')
            return true;
        if (c >= 'A' && c <= 'Z')
            return true;
        if (c >= '0' && c <= '9')
            return true;
        return false;
    }
};