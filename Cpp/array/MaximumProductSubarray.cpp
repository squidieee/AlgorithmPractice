/* 

Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int max_end, max_prod, min_end;
        max_end = nums[0];
        max_prod = nums[0];
        min_end = nums[0];
        max_prod = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int num1 = nums[i];
            int num2 = nums[i] * max_end;
            int num3 = nums[i] * min_end;
            max_end = max(max(num1, num2), num3);
            min_end = min(min(num1, num2), num3);
                        
            max_prod = max(max_prod, max_end);
        }
        return max_prod;
    }
};