/* 
82. Single Number

Given 2 * n + 1 numbers, every numbers occurs twice except one, find it.

Example
Example 1:

Input：[1,1,2,2,3,4,4]
Output：3
Explanation:
Only 3 appears once
Example 2:

Input：[0,0,1]
Output：1
Explanation:
Only 1 appears once
Challenge
One-pass, constant extra space.

Notice
n≤100
*/

class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumber(vector<int> &A) {
        int ans = 0;
        for (int i = 0; i < A.size(); i++)
        {
            ans = ans ^ A[i];
        }
        return ans;
        /*
        unordered_set<int> set;
        for(int i = 0; i < A.size(); i++)
        {
            if (set.find(A[i])!=set.end())
            {
                set.erase(A[i]);
            }
            else
                set.insert(A[i]);
        }
        return *set.begin();
        */
    }
};

/*
83. Single Number II

Given 3*n + 1 non-negative integer, every numbers occurs triple times except one, find it.

Example
Example 1:

Input:  [1,1,2,3,3,3,2,2,4,1]
Output:  4
Example 2:

Input: [2,1,2,2]
Output:  1	
Challenge
One-pass, constant extra space.
*/

#include <bitset>

class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumberII(vector<int> &A) {
        const int NUM_BITS = 32;
        
        vector<int> bits_sum(NUM_BITS, 0);
        for(int num: A)
        {
            std::bitset<NUM_BITS> bits(num);
            for(int i =0; i < NUM_BITS; i++)
            {
                bits_sum[i] += bits[i];
                bits_sum[i] = bits_sum[i] % 3;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < NUM_BITS; i++)
        {
            ans += (1 << i) * bits_sum[i];
        }
        
        return ans;
    }
};

/*
84. Single Number III

Given 2*n + 2 numbers, every numbers occurs twice except two, find them.

Example
Example 1:
	Input:  [1,2,2,3,4,4,5,3]
	Output:  [1,5]

Example 2:
	Input: [1,1,2,3,4,4]
	Output:  [2,3]
	
Challenge
O(n) time, O(1) extra space.
*/

class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer array
     */
    vector<int> singleNumberIII(vector<int> &A) {
        int xor_res = 0;
        for(int num: A)
        {
            xor_res = num ^ xor_res;
        }
        
        int bit_num = 1;
        while(xor_res % 2 == 0)
        {
            xor_res = xor_res >> 1;
            bit_num = bit_num << 1;
        }
        
        vector<int> result = vector<int>(2);
        for(int num: A)
        {
            
            if( (num & bit_num) == 0)
            {
                result[0] = result[0] ^ num;
            }
            else
            {
                result[1] = result[1] ^ num;
            }
        }
        
        return result;
    }
};