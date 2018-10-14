/* 
539. Move Zeroes
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example
Given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Notice
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/


class Solution {
public:
    /**
     * @param nums: an integer array
     * @return: nothing
     */
    void moveZeroes(vector<int> &nums) {
        // write your code here
        /*
            Solution 1: In-Place, keep order, min operations
        */
        if (nums.empty() || nums.size()==1) return;
        
        int fast(0), slow(0);
        
        while(fast < nums.size())
        {
            if (nums[fast]!=0 )
            {
                if (fast!=slow)
                    nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        
        while(slow < nums.size())
        {
            nums[slow] = 0;
            slow++;
        }
        
    }
        /*
            Solution 2
            In-Place
            Keep order
            Without minimizing total number of operations
        */
        /*
        if (nums.empty() || nums.size()==1) return;
        
        int fast(1), slow(0);
        
        while(fast < nums.size())
        {
            if (nums[slow]==0)
            {
                if (nums[fast]!=0)
                {   
                    swap(nums[slow], nums[fast]);
                    slow++;
                }
            }
            else
                slow++;
            fast++;
        }
    }
    void swap(int& a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    */
};