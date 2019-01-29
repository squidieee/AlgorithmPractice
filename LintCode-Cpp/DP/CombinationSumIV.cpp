/* 
564. Combination Sum IV
Given an integer array nums with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example
Given nums = [1, 2, 4], target = 4

The possible combination ways are:
[1, 1, 1, 1]
[1, 1, 2]
[1, 2, 1]
[2, 1, 1]
[2, 2]
[4]
return 6

Notice
A number in the array can be used multiple times in the combination.
Different orders are counted as different combinations.
*/

class Solution {
public:

    int backPackVI(vector<int> &nums, int target)
    {
        vector<int> f(target + 1, 0);
        f[0] = 1;
        
        for(int i = 1; i <= target; i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                if (nums[j] <= i) // assuming adding nums[j] to subset
                {
                    f[i] += f[i - nums[j]]; // remaining number
                }
            }
        }
        
        return f[target];
    }
    /// Time Exceed Limit
    /*
    int backPackVI(vector<int> &nums, int target) {
        // sort first
        std::sort(nums.begin(), nums.end());
        // dfs
        int result = 0;
        vector<int> subset;
        dfs(nums, target, 0, 0, subset, result);
        return result;
    }
    
    void dfs(vector<int> &nums, int target, int sum, int start, vector<int>& subset, int& result)
    {
        if (start > nums.size() - 1) return;
        
        for(int i = start; i < nums.size(); i++)
        {
            if (sum + nums[i] > target)
                return;
            
            if (sum + nums[i] == target)
            {
                subset.push_back(nums[i]);
                result += computePermutation(subset);
                subset.pop_back();
                return;
            }
            // sum + nums[i] < target
            subset.push_back(nums[i]);
            sum += nums[i];
            dfs(nums, target, sum, i, subset, result);
            // back trace
            subset.pop_back();
            sum -= nums[i];
        }
    }
    
    int computePermutation(vector<int>& nums)
    {
        int result(0);
        vector<bool> visited(nums.size(), false);
        permutationHelper(nums, 0, result, visited);
        return result;
    }
    
    // get a num from nums, add it to subset if not dup
    // if subset's size == nums.size()
    // result++
    void permutationHelper(vector<int>& nums, int subset_size, int& result, vector<bool>& visited)
    {
        if (subset_size > nums.size() - 1) return;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if (visited[i]) continue;
            if (i > 0 && nums[i] == nums[i-1] && !visited[i-1]) continue;
            
            // add to result
            subset_size++;
            if (subset_size == nums.size()) result++;
            visited[i] = true;
            permutationHelper(nums, subset_size, result, visited);
            
            //back-trace
            subset_size--;
            visited[i] = false;
        }
    }
    */

};
// Solution TLE:
// sort them first
// get a num from nums, add it to the subset
// iterate from this num till the end of array
// if sum < target, recursion from this num again
// if sum == target, add it to the result
// if sum > target, do nothing

// backtracing:
// pop this num from subset, remove it from sum

// finally we return the size of result

// DP SOLUTION: target varies from 0 to target
// build solution of target based on target - 1