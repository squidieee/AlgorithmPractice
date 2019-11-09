/* 
1318. Contains Duplicate III

Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

Example
Example1

Input: nums = [1,3,1], k = 1, t = 1
Output: false
Explanation: 
nums[2] = 1, nums[1] = 3, nums[1] - nums[2] = 2 > t
nums[0] = 1, nums[2] = 1, nums[1] - nums[2] = 0 < t,
2 - 0 = 2 > k
Example2

Input: nums = [1,3,1], k = 1, t = 2
Output: true
Explanation: 
nums[2] = 1, nums[1] = 3, nums[1] - nums[2] = 2 = t,
2 - 1 = 1 = k

*/

class Solution {
public:
    /**
     * @param nums: the given array
     * @param k: the given k
     * @param t: the given t
     * @return: whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
     */
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        
        std::set<int> set;
        for(int i = 0; i < nums.size(); i++)
        {
           if (i > k) set.erase(nums[i - k - 1]);
           
           std::set<int>::iterator it = set.lower_bound(nums[i]);
           if (it != set.end() && *it - nums[i] <= t)   return true;
           
           if (it != set.begin() && i > 0)
           {
               it--;
               if( nums[i] - *it <= t) return true;
           }
           
           set.insert(nums[i]);
        }
        
        return false;
        
        /* Brutal Force 
        for(int i = 0; i < nums.size() - 1; i++)
        {
            int maxJ = min((int)nums.size() - 1, i + k);
            for(int j = i + 1; j <= maxJ; j++)
            {
                if (abs(nums[j] - nums[i]) <= t) return true;
            }
        }
        
        return false;
        */
    }
};

// Sol1: brutal force
// for each number at index i, 
//    check if numbers at indices i + 1, i + 2 ... i + k <= nums[i] + t
// if not, return false
// O(n * k)

// Sol2: sliding window
// for a sliding window with len of k
// for each new number i, 
// see if prev k numbers in the window have the cloest lowerbound/upperbound of nums[i] which:
// nums[i] - lb >= t || up - nums[i] >= t
// add nums[i] into the window and remove nums[i - k] from the window
// no need to take care of the right k numbers since it is a pair

// O(nlogk)