/* 
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> allSol;
        
        int len = nums.size();
        if (len < 1)
            return allSol;
        sort(nums.begin(),nums.end());
        
        vector<int> sol;
        allSol.push_back(sol);
        int prevAdd;
        for(int i = 0; i < len; i++)
        {
            
            int N = allSol.size();
            int start=0;
            if ( i > 0 && nums[i-1] == nums[i])
            {
                start = N - prevAdd;
            }
            
            prevAdd = 0;
            for (int j = start; j < N; j++)
            {
                sol = allSol[j];
                sol.push_back(nums[i]);
                allSol.push_back(sol);
                prevAdd++;
            }
        }
        return allSol;
    }
};