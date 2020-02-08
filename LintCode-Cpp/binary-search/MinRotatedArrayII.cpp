/* 
617. Maximum Average Subarray II

Given an array with positive and negative numbers, find the maximum average subarray which length should be greater or equal to given length k.

Example
Example 1:

Input:
[1,12,-5,-6,50,3]
3
Output:
15.667
Explanation:
 (-6 + 50 + 3) / 3 = 15.667
Example 2:

Input:
[5]
1
Output:
5.000
Notice
It's guaranteed that the size of the array is greater or equal to k.
*/

class Solution {
public:
    /**
     * @param nums: an array with positive and negative numbers
     * @param k: an integer
     * @return: the maximum average
     */
    double maxAverage(vector<int> &nums, int k) {
        // def left and right 
        double left = INT_MAX;
        double right = INT_MIN;
        
        for(int num: nums)
        {
            left = min(left, (double)num);
            right = max(right, (double)num);
        }
        
        // binary search
        const double step = 1e-12;
        vector<double> sumArray(nums.size() + 1, 0);
        while(left + step < right)
        {
            // apply average
            double avg = (left + right) / 2;
            for(int i = 1; i < sumArray.size(); i++)
            {
                sumArray[i] = sumArray[i-1] + nums[i-1] - avg;
            }
            
            // get max subarray sum with size >= k
            double maxSum = INT_MIN;
            double minPre = 0;
            for(int i = k; i < sumArray.size(); i++)
            {
                maxSum = max(maxSum, sumArray[i] - minPre);
                minPre = min(minPre, sumArray[i - k + 1]);
            }
            
            // go left or right
            if(maxSum > 0)
            {
                left = avg;
            }
            else
            {
                right = avg;
            }
        }
        
        return left;
    }
};

// sliding window of O(n) will not work
// require O(n^2)

// binary search over answer: O(log(max - min) * N)
