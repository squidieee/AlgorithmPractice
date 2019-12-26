/*
562. Backpack IV

Given an integer array nums[] which contains n unique positive numbers, num[i] indicate the size of ith item. An integer target denotes the size of backpack. Find the number of ways to fill the backpack.

Each item may be chosen unlimited number of times

Example
Example1

Input: nums = [2,3,6,7] and target = 7
Output: 2
Explanation:
Solution sets are: 
[7]
[2, 2, 3]
Example2

Input: nums = [2,3,4,5] and target = 7
Output: 3
Explanation:
Solution sets are: 
[2, 5]
[3, 4]
[2, 2, 3]
*/
class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
    int backPackIV(vector<int> &nums, int target) {
        
        vector<int> f(target + 1, 0);
        vector<int> g(target + 1, 0);
        f[0] = 1;
        
        for(int i = 0; i < nums.size(); i++)
        {
            vector<int> prevf(target + 1, 0);
            for(int t = 0; t <= target; t++)
            {
                prevf[t] = f[t];
                g[t] = (t >= nums[i]) ? prevf[t - nums[i]] + g[t - nums[i]]: 0; 
                f[t] = prevf[t] + g[t];
            }
        }
        
        return f.back();
    }
};

// use two arrays to record status
// f array: total number of sols given a target t and an arrary from 0 to i
// g array: total number of sols when including num[i] given a target t and an arrary from 0 to i

/*
563. Backpack V

Given n items with size nums[i] which an integer array and all positive numbers. An integer target denotes the size of a backpack. Find the number of possible fill the backpack.

Each item may only be used once

Example
Given candidate items [1,2,3,3,7] and target 7,

A solution set is: 
[7]
[1, 3, 3]
return 2
*/
class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers
     * @param target: An integer
     * @return: An integer
     */
    int backPackV(vector<int> &nums, int target) {
        vector<int> f(target + 1, 0);
        f[0] = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int t = target; t >= 0; --t)
            {
                f[t] += t >= nums[i] ? f[t - nums[i]] : 0;
            }
        }
        
        return f.back();
    }
};

// f[i, t] = f[i-1, t] + f[i-1, t - nums[i]]


/* 
564. BackPackVI (Combination Sum IV) 

Given an integer array nums with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example
Example1

Input: nums = [1, 2, 4], and target = 4
Output: 6
Explanation:
The possible combination ways are:
[1, 1, 1, 1]
[1, 1, 2]
[1, 2, 1]
[2, 1, 1]
[2, 2]
[4]
Example2

Input: nums = [1, 2], and target = 4
Output: 5
Explanation:
The possible combination ways are:
[1, 1, 1, 1]
[1, 1, 2]
[1, 2, 1]
[2, 1, 1]
[2, 2]
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
                f[i] += nums[j] <= i ? f[i - nums[j]] : 0; // remaining number
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

// DP SOLUTION:
// ex [1,2,4]
// assuming grand total of combinations that add up to target t is: g[t]
// g[t] has three possibility: ends with 1, ends with 2, or ends with 4
// g[t] = f[1, t] + f[2, t] + f[4, t]
// note f[1, t] = g[t - 1], f[2, t] = g[t - 2], we have:
// g[t] = g[t - 1] + g[t - 2] + g[t - 4], as long as t >= 1,2 or 4
// so we construct g[t] from t=1 to t=target