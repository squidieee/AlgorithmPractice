/* 
1287. Increasing Triplet Subsequence

Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Example
Example1

Input: [1, 2, 3, 4, 5]
Output: true
Example2

Input: [5, 4, 3, 2, 1]
Output: false
*/

class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: return a boolean
     */
    bool increasingTriplet(vector<int> &nums) {
        if (nums.size() < 3) return false;
        
        /// Greedy
        
        int first = INT_MAX;
        int second = INT_MAX;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= first )
            {
                first = nums[i];
            }
            else if (nums[i] <= second)
            {
                second = nums[i];
            }
            else
            {
                return true;
            }
        }
        
        return false;
        
        
        // dp
        /*
        vector<int> fi(nums.size(), 1);
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    fi[i] = max(fi[i], fi[j] + 1);
                    if (fi[i] >= 3) return true;
                }
            }
        }
        
        return false;
        */
    }
};

// Sol1: Greedy
// record first and second 
// record first if num < first
// record second if first < num < second 
// return true if we find num > second
// note that this sol won't work if asked to return the answer since first may be wrong
// example: [10, 12, 1, 13]

// Sol2: dp
// fi: number of increasing subsequence in subarray[0~i] from the input array
// with the tail of valid subsequence at i
// f[0] = 0;
// f[1] = 1;
// f[i] = max_j( f[j+1] + 1 when nums[j] < nums[i]) with 0< j < i