/* 
891. Valid Palindrome II

Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example
Example 1:

Input: s = "aba"
Output: true
Explanation: Originally a palindrome.
Example 2:

Input: s = "abca"
Output: true
Explanation: Delete 'b' or 'c'.
Example 3:

Input: s = "abc"
Output: false
Explanation: Deleting any letter can not make it a palindrome.
Notice
The string will only contain lowercase characters.
The maximum length of the string is 50000.
*/

/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

 class Solution {
public:
    /**
     * @param s: a string
     * @return: nothing
     */
    bool validPalindrome(string &s) {
        return isPalindromeHelper(s, 0, s.size() - 1, false);
    }
    
    bool isPalindromeHelper(string& s, int left, int right, bool deleted)
    {
        bool result = true;
        while (left < right)
        {
            if (s[left] == s[right])
            {
                left++;
                right--;
            }
            else
            {
                if (deleted) return false;
                result = isPalindromeHelper(s, left + 1, right, true) ||
                         isPalindromeHelper(s, left, right - 1, true);
                break;
            }
        }
        
        return result;
    }
};



// brutal force: try deleting each ch, see if remaining is palin
// O(n * (n-1)) = O(n^2)

// if left != right => check if the substring is a valid palindrome just like valid palindrome problem
// result should be either left+1 to right or left to right-1
// need to check both cases so should be O(2N)


// WRONG ANSWER:
// a b c d b c a
//   |       | 
// a b c d c z b a 
// if meet mismatch
// check next, if same, delete the other one (across the center of palin?)
// O(n)