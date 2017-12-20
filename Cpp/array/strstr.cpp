/* 
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int len = haystack.size();
        int nsub = needle.size();
        if (nsub < 1)
            return 0;
        if(nsub > len || len < 1)
            return -1;
        for(int i =0; i < len; i++)
        {
            if (haystack[i] == needle[0] && len - i >= nsub)
            {
                int j = 1;
                while(j < nsub)
                {
                    if (haystack[i+j]!=needle[j])
                        break;
                    j++;
                }
                if (j == nsub)
                    return i;
            }
        }
        return -1;
    }
};

//todo: KMP