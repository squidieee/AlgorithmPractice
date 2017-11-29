/* 
Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

Example 1:
Input: [1,4,3,2]

Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).

Note:
n is a positive integer, which is in the range of [1, 10000].
All the integers in the array will be in the range of [-10000, 10000].

*/

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        // solution 1:
        if (nums.empty())
            return 0;
        if (nums.size() % 2==1)
            return 0;
       
        // sort nums O(NlogN)       
        sort(nums.begin(), nums.end());
        
        // partition O(logN)
        int sum = 0;
        for (int i = 0; i < nums.size()/2; i++)
        {
            sum+= min(nums[i*2], nums[2*i+1]);
        }
        return sum;
                
    }
};