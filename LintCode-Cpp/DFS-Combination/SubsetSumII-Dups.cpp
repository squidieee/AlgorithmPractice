/* 
153. Combination Sum II
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Example
Given candidate set [10,1,6,7,2,1,5] and target 8,

A solution set is:

[
  [1,7],
  [1,2,5],
  [2,6],
  [1,1,6]
]
Notice
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
*/

class Solution {
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    vector<vector<int>> combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> result;
        vector<int> subset;
        
        if (num.empty()) return result;
        
        std::sort(num.begin(), num.end());
        
        dfsRecur(num, target, 0, subset, result);
        
        return result;
    }
    
    // take a component from num, add it to subset, if target == 0, push it to result
    // if target < 0 then return
    void dfsRecur(vector<int>& nums, int target, int index, vector<int>& subset, vector<vector<int>>& result)
    {
        for(int i = index; i < nums.size(); i++)
        {
            // if duplicates
            if( i > 0 && nums[i] == nums[i-1] && i!=index)
                continue;
            
            subset.push_back(nums[i]);
            int res = target - nums[i];
            if ( res == 0)
            {
                result.push_back(subset);
            }
            else if ( res > 0 )
            {
                dfsRecur(nums, res, i + 1, subset, result);
            }
            
            subset.pop_back();
        }
    }
    
};