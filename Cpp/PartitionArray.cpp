/* 
Given an array nums of integers and an int k, partition the array (i.e move the elements in "nums") such that:

All elements < k are moved to the left
All elements >= k are moved to the right
Return the partitioning index, i.e the first index i nums[i] >= k.

*/

class Solution {
public:
    /*
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        int idx, i(0);
        idx = nums.size();
        while(i < idx)
        {
            if(nums[i] >= k)
            {
                idx--;
                swap(nums[i], nums[idx]);
            }
            else
            {
                i++;
            }
        }
        return idx;
    }
};