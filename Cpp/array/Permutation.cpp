/* 
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> allSol;
        vector<int> sol = nums;
        allSol.push_back(sol);
        if (len < 1)
            return allSol;
       int idx = len-2;
        while(idx >= 0)
        {
            int N = allSol.size();
            for(int k = 0; k < N; k++)
            {
                for (int j = idx+1; j < len; j++)
                {
                    sol = allSol[k];
                    swap(sol[idx],sol[j]);
                    allSol.push_back(sol);
                }              
            }
            idx--;
        }
        return allSol;
    }
};