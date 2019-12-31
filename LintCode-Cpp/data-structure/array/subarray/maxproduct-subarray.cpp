/* 
191. Maximum Product Subarray
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example
For example, given the array [2,3,-2,4], the contiguous subarray [2,3] has the largest product = 6.
*/

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An integer
     */
    int maxProduct(vector<int> &nums) {
        // [0] -> max 0 min 0 
        // [0, 1] -> 1 or 1 * prevMin or 1 * prevMax
        
        if (nums.empty()) return 0;
        
        int iMax = nums[0];
        int iMin = nums[0];
        int subMax = nums[0];
        
        for(int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                iMax = std::max(iMax * nums[i], nums[i]);
                iMin = std::min(iMin * nums[i], nums[i]);
            }
            else
            {
                int temp = iMax;
                iMax = std::max(iMin * nums[i], nums[i]);
                iMin = std::min(temp * nums[i], nums[i]);                
            }
            subMax = std::max(subMax, iMax);
        }
        
        return subMax;
    }
};