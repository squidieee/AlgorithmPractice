/* 
14. First Position of Target
For a given sorted array (ascending order) and a target number, find the first index of this number in O(log n) time complexity.

If the target number does not exist in the array, return -1.

Example
If the array is [1, 2, 3, 3, 4, 5, 10], for given target 3, return 2.

Challenge
If the count of numbers is bigger than 2^32, can your code work properly?
*/

class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &nums, int target) {
        if (nums.empty()) return -1;
        
        int start(0), end(nums.size() - 1);
        while(start + 1 < end)
        {
            int mid = start + (end - start)/2;
            if (target <= nums[mid])
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }
        
        if (nums[start] == target) return start;
        if (nums[end] == target) return end;
        return -1;
    }
    
    // O(log n): binary search
    // How to make sure first position?
    // go left half if equal
};