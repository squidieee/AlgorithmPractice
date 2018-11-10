/* 
90. k Sum II
Given n unique integers, number k (1<=k<=n) and target.

Find all possible k integers where their sum is target.

Example
Given [1,2,3,4], k = 2, target = 5. Return:

[
  [1,4],
  [2,3]
]
*/

class Solution {
public:
    /*
     * @param A: an integer array
     * @param k: a postive integer <= length(A)
     * @param target: an integer
     * @return: A list of lists of integer
     */
    
    vector<vector<int>> kSumII(vector<int> &A, int k, int target) {
        vector<vector<int>> results;
        
        if (k <= 0 || A.empty() || target <= 0) return results;
        
        vector<int> subset;
        
        std::sort(A.begin(), A.end());
        
        dfs(A, k, target, 0, subset, results);
        return results;
    }
    
    // take a number from A, add it to the subset if size < k
    // if subset meets the size of k and sum(subset) == target
    // result += 1
    // if sum >  target, return
    void dfs(vector<int>& A, int k, int target, int start, vector<int>& subset, vector<vector<int>>& results)
    {
        for( int i = start; i < A.size(); i++)
        {
            subset.push_back(A[i]);
            
            if (subset.size() == k)
            {
                if (target - A[i] <= 0)
                {
                    if (target == A[i])   
                        results.push_back(subset);
                    subset.pop_back();
                    return;
                }
            }
            else if (subset.size() < k)
            {
                if (target - A[i] > 0)
                    dfs (A, k, target - A[i], i + 1, subset, results);
                else
                {
                    subset.pop_back(); 
                    return;
                }
            }
            // back trace
            subset.pop_back();
        }
    }
};