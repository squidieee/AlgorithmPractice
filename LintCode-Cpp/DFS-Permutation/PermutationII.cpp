/*
16. Permutations II
Given a list of numbers with duplicate number in it. Find all unique permutations.

Example
For numbers [1,2,2] the unique permutations are:

[
  [1,2,2],
  [2,1,2],
  [2,2,1]
]
Challenge
Using recursion to do it is acceptable. If you can do it without recursion, that would be great!
*/
class Solution {
public:

    /* Recursion Version
     * @param :  A list of integers
     * @return: A list of unique permutations
     */
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> results;
        vector<int> subset;

        if (nums.empty()) 
        {
            results.push_back(subset);
            return results;
        }
        
        std::sort(nums.begin(), nums.end());
        
        vector<bool> visited(nums.size(), false);
        
        dfs(nums, visited, subset, results);
        return results;
    }
    
    // take a num from nums, add it to subset if not repeated
    // if size of subset == nums.size(), push it to the result
    // unique answer:
    // create a visited vector to make sure the recursion tree will not repeat
    // if nums[i] == nums[i-1] and visited[i-1] is false -> repeat
    // 
    void dfs(vector<int>& nums, vector<bool>& visited, vector<int>& subset, vector<vector<int>>& results )
    {
        for(int i = 0; i < nums.size(); i++)
        {
            if (visited[i])
                continue;
                
            if (i > 0 && nums[i] == nums[i-1] && !visited[i-1]) // if repeated
                continue;
            
            // add to subset
            subset.push_back(nums[i]);
            visited[i] = true;
            // push to results
            if (subset.size() == nums.size())
            {
                results.push_back(subset);
            }
            else // recursively visit other branch
            {
                dfs(nums, visited, subset, results);
            }
            // back trace
            visited[i] = false;
            subset.pop_back();
        }
    }
};