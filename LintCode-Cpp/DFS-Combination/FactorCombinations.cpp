/* 
1308. Factor Combinations

Numbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.

Example
Example1

Input: 12
Output: 
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
Explanation:
2*6 = 12
2*2*3 = 12
3*4 = 12
Example2

Input: 32
Output: 
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
Explanation:
2*16=32
2*2*8=32
*/

class Solution {
public:
    /**
     * @param n: a integer
     * @return: return a 2D array
     */
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> result;
        if (n < 3) return result;
        
        vector<int> subset;
        dfs(n, 2,subset, result);
        return result;
    }
    
    void dfs(int target, int start, vector<int>& subset, vector<vector<int>>& results)
    {
        if (target == 1) 
        {
            if( subset.size() > 1)
                results.push_back(subset);
            return;
        }
        
        for(int factor = start; factor <= target; factor++)
        {
            if (factor > target) return;
            if (target % factor != 0 ) continue;
            
            subset.push_back(factor);
            dfs(target / factor, factor, subset, results);
            subset.pop_back();
        }
    }
};

// factors: number within [2, n / 2]
// for each factor, 
// if factor > target, quit
// if target % factor != 0, factor++
// when == 0, add factor to the subset
// if residue( which is target / factor) >= factor, add subset + residue to results 
// else quit
// go to the next dfs with target = target/factor
// when target == 1,  quit
// backtracing: remove the last factor