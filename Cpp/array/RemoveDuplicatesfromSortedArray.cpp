/* 
Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.

*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int cnt(0), prev,l(1);
        prev = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == prev)
            {
                cnt++;
            }
            else
            {
                l++;
                prev = nums[i];               
                if (cnt > 0)
                    swap(nums[i], nums[i - cnt]);   
            }
        }
        return l;
    }

    // a better one:
    /*
    class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int index=0;
            if(nums.size()<=1) return nums.size();
            for(int i=1;i<nums.size();i++){
                if(nums[i]!=nums[i-1]) nums[++index]=nums[i];
            }   
            return index+1;
        }
};   
    */
};