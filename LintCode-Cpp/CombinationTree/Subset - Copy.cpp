/* 
135. Combination Sum
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Example
Given candidate set [2,3,6,7] and target 7, a solution set is:

[7]
[2, 2, 3]
Notice
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
*/

class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target: An integer
     * @return: A list of lists of integers
     */
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> result;
        vector<int> subset;
        
        if (candidates.empty()) return result;
        
        std::sort(candidates.begin(), candidates.end());
        dfsRecur(candidates, target, 0, subset, result);
        
        return result;
    }
    
    // get a component from candidates, add it to a subset, push the subset to result if == target
    // remove the component from subset
    // recursion returns when sum > target
    // since numbers can be repeated, each parent can have child that has parent's value added again
    void dfsRecur(vector<int>& candidates, int target, int index, vector<int>& subset, vector<vector<int>>& result)
    {
        for(int i = index; i < candidates.size(); i++)
        {
            // if duplicates
            if (i > 0 && candidates[i] == candidates[i-1] && i != index)
                continue;
            
            subset.push_back(candidates[i]);
            
            int s = sum(subset); // this part is not optimal: sum is computed each time; can be improved by using (target - candidates[i]) for each node
            if (s == target)
            {
                result.push_back(subset);
            }
            else if(s < target)
            {
                dfsRecur(candidates, target, i, subset, result);
            }
            
            subset.pop_back();
        }
    }
    
    int sum( vector<int>& nums)
    {
        int result(0);
        for(auto num: nums)
        {
            result += num;
        }    
        return result;
    }
};