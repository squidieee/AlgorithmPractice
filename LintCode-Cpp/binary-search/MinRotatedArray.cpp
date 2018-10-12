/* 
159. Find Minimum in Rotated Sorted Array
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

Example
Given [4, 5, 6, 7, 0, 1, 2] return 0

Notice
You may assume no duplicate exists in the array.
*/

class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        // write your code here
        if (nums.empty()) return -1;
        if (nums.size()==1) return nums[0];
        
        int last = nums[nums.size()-1];
        
        int start(0), end(nums.size()-1);
        while(start + 1 < end)
        {
            int mid = start + (end-start)/2;
            if (nums[mid] > last)
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        
        return std::min(nums[start], nums[end]);
    }
};