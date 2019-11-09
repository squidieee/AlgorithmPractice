/* 
1319. Contains Duplicate II

Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Example
Example 1：

Input：nums = [1,2,1], k = 0
Output：False
Example 2：

Input：nums = [1,2,1], k = 2
Output：True
Explanation：nums[0] = nums[2] and 2 - 0 <= 2

*/

class Solution {
public:
    /**
     * @param nums: the given array
     * @param k: the given number
     * @return:  whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k
     */
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        /* Sol2 */
        unordered_set<int> window;
        for(int i = 0; i < nums.size(); i++)
        {
            if (i > k) window.erase(nums[i-k-1]);
            if (window.find(nums[i]) != window.end())
                return true;
            window.insert(nums[i]);
        }
        
        return false;
        
        /* Sol1
        unordered_map<int, vector<int>> map;
        for(int i = 0; i< nums.size(); i++)
        {
            map[nums[i]].push_back(i);
        }
        
        for(auto& p: map)
        {
            if(p.second.size() < 2) continue;
            for(int i = 1; i < p.second.size(); i++)
            {
                if(std::abs(p.second[i] - p.second[i-1]) <= k) return true;
            }
        }
        
        return false; 
        */
    }
};

// Sol1: hashmap
// record num as key, indices as val 
// since indices are sorted
// then check if abs(indices[i] - indices[i-1]) <= k
// Time O(n) Space O(n)

// Sol2:sliding window
// a window with the size of k
// use a hashset to represent the window
// Time O(n) Space O(k)