/* 
17. Subsets
Given a set of distinct integers, return all possible subsets.

Example
If S = [1,2,3], a solution is:

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
Challenge
Can you do it in both recursively and iteratively?

Notice
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.)
*/

// Solution: Recursive use DFS
class Solution_Recur {
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> result;
        vector<int> array;
        
        result.push_back(array);
        if (nums.empty()) return result;
        
        std::sort(nums.begin(), nums.end());
        dfsHelper(nums, array, result, 0);
        
        return result;
    }
    
    // get one element from nums, add it to array, then push the array to result
    void dfsHelper(vector<int>& nums, vector<int>& array, vector<vector<int>>& result, int index)
    {
        for (int i = index; i < nums.size(); i++) // each level of the tree
        {
            array.push_back(nums[i]);
            result.push_back(array);
            dfsHelper(nums, array, result, i + 1);
            // backtracing
            array.pop_back();
        }
    }
};


// Solution: Iterative use BFS
class Solution_Iter {
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> result;
        vector<int> array;
        
        result.push_back(array);
        if (nums.empty()) return result;
        
        std::sort(nums.begin(), nums.end());
        
        queue< vector<int> > Q;
        for (auto num: nums)
        {
            array.push_back(num);
            Q.push(array);
            array.pop_back();
        }
        
        while(!Q.empty()) 
        {
            array = Q.front();
            Q.pop();
            result.push_back(array);
            
            for(int i = 0; i < nums.size(); i++)
            {
                if (nums[i] > array[array.size() - 1]) // find the start index by comparing with nums[i] since it is sorted
                {
                    vector<int> arrayChild = array;
                    arrayChild.push_back(nums[i]);
                    Q.push(arrayChild);
                }
            }
        }
        
        return result;
    }

};