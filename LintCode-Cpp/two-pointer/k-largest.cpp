/* 
544. Top k Largest Numbers
Given an integer array, find the top k largest numbers in it.

Example
Given [3,10,1000,-99,4,100] and k = 3.
Return [1000, 100, 10].
*/

class Solution {
public:
    /**
     * @param nums: an integer array
     * @param k: An integer
     * @return: the top k largest numbers in array
     */
    vector<int> topk(vector<int> &nums, int k) {
        vector<int> results;
        if (nums.empty() || k == 0) return results;
        
        // O(n): put top k largest on left
        quickSelect(nums, k - 1, 0, nums.size() - 1);
        
        // O(klogk) sort k elements
        quickSelect(nums, -1, 0, k - 1);
        
        for(int i = 0; i < k; i++)
        {
            results.push_back(nums[i]);
        }
        return results;
    }
    
    // parition: choose a pivot from start to end
    // paritition the array into two parts 
    // by putting elements < pivot on left and > pivot on right
    // if k <= the index of the end of left array, go left
    // if k >= the index of the begin of right array, go right
    
    void quickSelect(vector<int>& nums, int k, int start, int end)
    {
        if (start >= end) return;
        int left(start), right(end);
        
        int pivot = nums[start + (end - start)/2];
        
        while(left <= right)
        {
            while(left <= right && nums[left] > pivot)
            {
                left++;
            }
            
            while(left <= right && nums[right] < pivot)
            {
                right--;
            }
            
            if (left <= right)
            {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
        // full sort
        if (k < 0)
        {
            quickSelect(nums, k, start, right);
            quickSelect(nums, k, left, end);
            return;
        }
        
        // only first k
        if (k <= right)
            return quickSelect(nums, k, start, right);
        if (k >= left)
            return quickSelect(nums, k, left, end);
    }
};