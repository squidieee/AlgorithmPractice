/* 
152. Combinations
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example
Given n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4]
]
Notice
You don't need to care the order of combinations, but you should make sure the numbers in a combination are sorted.
*/

class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int>> combine(int n, int k) {
        return dfs(n,k);

    }
    
    // dfs is better than bfs in this problem since n >= k
    // their time complexity are the same but dfs space complexity depends on height (always k)
    // and bfs space complexity depends on width (n grows exponetially)
    
    vector<vector<int>> dfs(int n, int k){
        vector<vector<int>> result;
        vector<int> subset;
        
        if (k==0) 
        {
            result.push_back(subset);
            return result;
        }
        
        dfsHelper(n, k, 1, subset, result);
        return result;
    }
    
    // take a component from start to n, add it to subset, 
    // push the subset to result if the size of subset == k
    // if size < k, recursively call itself
    void dfsHelper(int n, int k, int start, vector<int>& subset, vector<vector<int>>& result)
    {
        for (int i = start; i <= n; i++)
        {
            subset.push_back(i);
            if (subset.size() == k)
            {
                result.push_back(subset);
            }
            else if(subset.size() < k)
            {
                dfsHelper(n, k, i + 1, subset, result);
            }
            
            subset.pop_back();
        }
    }
    
};