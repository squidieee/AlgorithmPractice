/* 
class Solution {
public:
    /**
     * @param nums: a mountain sequence which increase firstly and then decrease
     * @return: then mountain top
     */
     int mountainSequence(vector<int> &nums) {
        // write your code here
        if (nums.empty()) return 0;
        if (nums.size()==1) return nums[0];

        // binary search O(logN)
        int start(0), end(nums.size()-1);
        
        while(start +1 < end && start < nums.size() && end >= 0)
        {
            int mid = start + (end-start)/2;
            if (nums[mid + 1] > nums[mid])
                start = mid;
            else
                end = mid;
            
            // no need to compare two adjacent points
            /*
            if (mid == 0 || mid == nums.size()-1)
                return nums[0] > nums[nums.size()-1]? nums[0]:nums[nums.size()-1];
            
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) // peak
            {
                return nums[mid];
            }
            
            if (nums[mid] > nums[mid-1] && nums[mid] < nums[mid+1]) // increasing
            {
                start = mid;
            }
            
            if (nums[mid] < nums[mid-1] && nums[mid] > nums[mid+1])  // decreasing
            {
                end = mid;
            }
            */
        }
        
        return nums[start] > nums[end] ? nums[start]: nums[end];
    }
};
*/

class Solution {
public:
    /**
     * @param nums: a mountain sequence which increase firstly and then decrease
     * @return: then mountain top
     */
    int mountainSequence(vector<int> &nums) {
        // write your code here
        if (nums.empty()) return 0;
        if (nums.size()==1) return nums[0];

        // binary search O(logN)
        int start(0), end(nums.size()-1);
        
        while(start +1 < end && start < nums.size() && end >= 0)
        {
            int mid = start + (end-start)/2;
            if (nums[mid + 1] > nums[mid])
                start = mid;
            else
                end = mid;
            
            // no need to compare two adjacent points
            /*
            if (mid == 0 || mid == nums.size()-1)
                return nums[0] > nums[nums.size()-1]? nums[0]:nums[nums.size()-1];
            
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) // peak
            {
                return nums[mid];
            }
            
            if (nums[mid] > nums[mid-1] && nums[mid] < nums[mid+1]) // increasing
            {
                start = mid;
            }
            
            if (nums[mid] < nums[mid-1] && nums[mid] > nums[mid+1])  // decreasing
            {
                end = mid;
            }
            */
        }
        
        return nums[start] > nums[end] ? nums[start]: nums[end];
    }
};