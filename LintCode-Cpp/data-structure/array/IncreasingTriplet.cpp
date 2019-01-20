/* 
1287. Increasing Triplet Subsequence
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Example
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.
*/

class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: return a boolean
     */
    bool increasingTriplet(vector<int> &nums) {
        if (nums.size() < 3)
            return false;
        int cnt = 2;
        for(int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
                cnt --;
        }
        
        return cnt <= 0;
    }
};

// suppose [1 ? 3 ? 5]
// we insert 0 and 2 to make it decrease from 1->0 and 3->2
// [1 0 3 2 5]
//   \ / \ /

// since 0 < 1, but 0 < 3, so it finally increases continuously anyway.