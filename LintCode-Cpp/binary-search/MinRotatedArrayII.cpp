/* 
160. Find Minimum in Rotated Sorted Array II

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

Example
Example 1:

Input :[2,1]
Output : 1.
Example 2:

Input :[4,4,5,6,7,0,1,2]
Output : 0.
Notice
The array may contain duplicates.
*/

class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        if (nums.size() < 1) return -1;
        
        int start(0), end(nums.size() - 1);
        
        while(start + 1 < end)
        {
            int mid = start + (end - start)/2;
            int pivotNum = nums[end];

            if (nums[mid] < pivotNum)
            {
                end = mid;
            }
            else if (nums[mid] > pivotNum)
            {
                start = mid;
            }
            else
            {
                end--; // worst case O(n)
            }
        }
        
        return min(nums[start], nums[end]);
    }
};