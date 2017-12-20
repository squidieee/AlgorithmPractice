/* 
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> allSol;
        if (len < 1)
            return allSol;
        vector<int> sol;
        allSol.push_back(sol); // push []
        for (int i = 0; i < len; i++)
        {
            findSubset(nums, i, allSol);
        }
        return allSol;
        
    }
    void findSubset(vector<int>& nums, int end, vector<vector<int>>& allSol)
    {
        int len = allSol.size();
        vector<int> sol;
        for(int i = 0; i < len; i++)
        {
            sol = allSol[i]; // get current sol sets
            sol.push_back(nums[end]); // add new element
            allSol.push_back(sol);
        }
    }
    
};