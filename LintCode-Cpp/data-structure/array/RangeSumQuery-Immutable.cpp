/* 
943. Range Sum Query - Immutable
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Notice
You may assume that the array does not change.
There are many calls to sumRange function.
*/

class NumArray {
public:
    NumArray(vector<int> nums) {
        if (!nums.empty())
        {
            _prefixSum.resize(nums.size());
            _prefixSum[0] = nums[0];
            for(int i = 1; i < nums.size();i++)
            {
                _prefixSum[i] = _prefixSum[i-1] + nums[i];
            }            
        }
        else
        {
            // throw invalid arg error
        }
    }
    
    int sumRange(int i, int j) {
        if (i == 0) return _prefixSum[j];
        return _prefixSum[j] - _prefixSum[i-1];
    }
    
    vector<int> _prefixSum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
 
 // compute all prefix sum start from 0 to i
 // store the result in an array