/* 
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
// solution 1: sort 0 and 2 only

        int idx0 = 0;
        int idx2 = nums.size()-1;
        
        int i = 0;
        
        while(i <= idx2)
        {
            if(nums[i] == 0)
            {
                swap(nums[i], nums[idx0]);
                idx0++;
                i++;
            }
            else if(nums[i] == 2)
            {
                swap(nums[i], nums[idx2]);
                idx2--;
            }
            else
            {
                i++;
            }
        }
        /*
        // solution 2: counting sort + rewriting
        int num0(0), num1(0), num2(0);
        for (int i = 0; i < nums.size(); i++)
        {
            switch(nums[i])
            {
                    case 0:
                    num0++;
                    break;
                case 1:
                    num1++;
                    break;
                case 2:
                    num2++;
                    break;

            }
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if(i < num0)
                nums[i]=0;
            else if(i < num0 + num1)
                nums[i]=1;
            else if(i < num0 + num1 + num2)
                nums[i]=2;
        }
*/

    }
    
};