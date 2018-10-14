/* 
521. Remove Duplicate Numbers in Array
Given an array of integers, remove the duplicate numbers in it.

You should:

Do it in place in the array.
Move the unique numbers to the front of the array.
Return the total number of the unique numbers.
Example
Given nums = [1,3,1,4,4,2], you should:

Move duplicate integers to the tail of nums => nums = [1,3,4,2,?,?].
Return the number of unique integers in nums => 4.
Actually we don't care about what you place in ?, we only care about the part which has no duplicate integers.

Challenge
Do it in O(n) time complexity.
Do it in O(nlogn) time without extra space.
Notice
You don't need to keep the original order of the integers.
*/


class Solution {
public:
    /**
     * @param nums: an array of integers
     * @return: the number of unique integers
     */
    int deduplication(vector<int> &nums) {
        // write your code here
        if (nums.empty() ) return 0;
        if (nums.size()==1) return 1;
        
        /*
            Solution 1: in-place, O(nlogn)
        */
        
        sort(nums.begin(), nums.end());
        int fast(0), slow(0);
        while(fast < nums.size())
        {
            if (nums[fast]!=nums[slow]) // unique
            {
                slow++;
                nums[slow] = nums[fast];
            }
            fast++;
        }
        return slow + 1;
        /*
            Solution 2: not in-place, O(n) time complexity
        */
        // which are unique
        /*
        unordered_map<int,int> map;
        int uniq(0);
        for(int i = 0; i < nums.size(); i++)
        {
            if (map.count(nums[i]))
            {
                map.at(nums[i])++;
            }
            else
            {
                map.insert({nums[i], 1});
                uniq++;
            }
        }
        
        // move unique
        int fast(0), slow(0);
        while (fast < nums.size())
        {
            if (map.at(nums[fast]) == 1) // unique fast
            {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        
        // fill in not unique
        for(auto it = map.begin(); it != map.end(); it++)
        {
            if (it->second > 1)
                nums[slow++] = it->first;
        }
        
        return uniq;
        */
    }
};