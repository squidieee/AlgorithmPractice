/* 
458. Last Position of Target
Find the last position of a target number in a sorted array. Return -1 if target does not exist.

Example
Given [1, 2, 2, 4, 5, 5].

For target = 2, return 2.

For target = 5, return 5.

For target = 6, return -1
*/

class Solution {
public:
    /**
     * @param nums: An integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int lastPosition(vector<int> &nums, int target) {
        // write your code here
        if (nums.empty()) return -1;
        int start(0), end(nums.size()-1);
        while( start + 1 < end && start < nums.size() && end >=0)
        {
            int mid = start + (end - start)/2;
            if (target > nums[mid])
                start = mid;
            if (target < nums[mid])
                end = mid;
            if (target == nums[mid])
                start = mid; // if to find first, end = mid
        }
        
        if (end >=0 && nums[end] == target)
            return end;
        if( start < nums.size() && nums[start] == target )
            return start;

        
        return -1;
    }
};

// How to make sure go last one?
// go right half if equal
// in an extreme case, think of an array that has same numbers
// we will want our algorithm to find the last element of that array
// so when equal, we should go second half