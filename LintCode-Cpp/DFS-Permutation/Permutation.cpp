/*
15. Permutations
Given a list of numbers, return all possible permutations.

Example
For nums = [1,2,3], the permutations are:

[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
Challenge
Do it without recursion.

Notice
You can assume that there is no duplicate numbers in the list.
*/



class Solution {
public:
    /* Iteration Version
    */
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> result;
        vector<int> subset;
        
        if (nums.empty())
        {
            result.push_back(subset);
            return result;
        }
        
        std::sort(nums.begin(), nums.end());
        
        for(int num: nums)
        {
            subset.push_back(num);
        }
        
        result.push_back(subset);
        
        while ( !nextPermutation(subset) )
        {
            result.push_back(subset);
        }
        return result;
    }
    
    // compute the next permutation: return true if reach the end
    bool nextPermutation(vector<int>& A)
    {
        // find the first element A[i] > A[i-1]
        int i = A.size() - 1;
        while( i > 0 && A[i] <= A[i-1])
        {
            i--;
        }
        
        if (i == 0)
            return true;
        // if i != 0, find the first element A[j] > A[i-1], swap them
        
        int j = A.size() - 1;
        
        while(A[j] <= A[i-1])
            j--;
        
        std::swap(A[j], A[i-1]);
        
        // reverse from A[i]
        reverse( A, i, A.size() - 1);
        return false;
    }
    
    void reverse(vector<int>& A, int start, int end)
    {
        while( start < end)
        {
            std::swap(A[start], A[end]);
            start++;
            end--;
        }
    }
    
    /* Recursion Version
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int>> permute_Recur(vector<int> &nums) {
        vector<vector<int>> result;
        vector<int> subset;
        
        if (nums.empty())
        {
            result.push_back(subset);
            return result;
        }
        
        vector<bool> visited(nums.size(), false);
        dfs(nums, visited, subset, result);
        
        return result;
    }
    
    // take a number from nums if not visited 
    // add it to subset, push the subset to results if == nums.size()
    
    void dfs(vector<int> &nums, vector<bool>& pvisited, vector<int>& subset, vector<vector<int>>& result)
    {
        for(int i = 0; i < nums.size(); i++) // for each child under this node
        {
            if (pvisited[i])
                continue;
            subset.push_back(nums[i]);
            pvisited[i] = true;
            
            if (subset.size() == nums.size())
                result.push_back(subset);
            else
                dfs(nums, pvisited, subset, result);
            
            subset.pop_back();
            pvisited[i] = false;
        }
    }
};