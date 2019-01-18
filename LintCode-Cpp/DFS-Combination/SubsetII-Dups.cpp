/* 
18. Subsets II
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Example
Input: [1,2,2]
Output:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
Challenge
Can you do it in both recursively and iteratively?

Notice
Each element in a subset must be in non-descending order.
The ordering between two subsets is free.
The solution set must not contain duplicate subsets.
*/

class Solution {
public:
    /**
     * @param nums: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        // dfs recursive approach
        vector<vector<int>> result;
        vector<int> subset;
        
        result.push_back(subset);
        if (nums.empty()) return result;
        
        std::sort(nums.begin(), nums.end());
        dfsRecur(nums, 0, subset, result);
        return result;
    }
    
    // get component from sorted nums, add it to a subset, push the subset to result
    // remove the component afterwards
    void dfsRecur(vector<int>& nums, int index, vector<int>& subset, vector<vector<int>>& result)
    {
        for(int i = index; i < nums.size(); i++) // for each child of the current subset
        {
            // if duplicate
            if (i > index && 
                nums[i] == nums[i - 1] )  // is it the first time we run it in this level? since [1,2]->[1,2,2] should be added 
                continue;
                
            subset.push_back(nums[i]);
            result.push_back(subset);
            
            dfsRecur(nums, i + 1, subset, result);
            
            subset.pop_back();
        }
    }
};