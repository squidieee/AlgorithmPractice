/* 
652. Factorization
A non-negative numbers can be regarded as product of its factors.
Write a function that takes an integer n and return all possible combinations of its factors.

Example
Given n = 8
return [[2,2,2],[2,4]]
// 8 = 2 x 2 x 2 = 2 x 4.

Given n = 1
return []

Given n = 12
return [[2,6],[2,2,3],[3,4]]

Notice
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combination.
*/

class Solution {
public:
    /**
     * @param n: An integer
     * @return: a list of combination
     */
    vector<vector<int>> getFactors(int n) {
        vector<int> subset;
        vector<vector<int>> results;
        
        if (n <= 1) return results;
        
        dfs(n, 2, subset, results);
        return results;
    }
    
    void dfs(int num, int start, vector<int>& subset, vector<vector<int>>& results)
    {
        if (num == 1)
        {
            if (subset.size() > 1)
                results.push_back(subset);
            return;
        }
        
        int up = std::sqrt(num);
        
        for(int i = start; i <= up; i++)
        {
            if( num % i == 0)
            {
                subset.push_back(i);
                dfs(num / i, i, subset, results);
                subset.pop_back();
            }
        }
        
        // push remain as one unit
        subset.push_back(num);
        dfs(1, start, subset, results);
        subset.pop_back();            

    }
    
    // first thought:
    // first find all factors of a number from 2 to sqrt(num)
    // then find all combinations of factors: not a good approach, hard to combine factors
    
    // second thought:
    // add to results while finding factors
    // divide number with i = from 2 to sqrt(num)
    // once mod == 0, add i to subset, go next level by num/i
    // back-trace by removing i from the subset
    // if num == 1, add subset to results
    // problem: repeated subsets, same value will be added multiple times
    // solution: each level, only add number >= previous factor
    
};