/* 
5. Kth Largest Element
Find K-th largest element in an array.

Example
In array [9,3,2,4,8], the 3rd largest element is 4.

In array [1,2,3,4,5], the 1st largest element is 5, 2nd largest element is 4, 3rd largest element is 3 and etc.

Challenge
O(n) time, O(1) extra memory.

Notice
You can swap elements in the array
*/

class Solution {
public:
    /**
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int n, vector<int> &nums) {
        // quick sort
        if (nums.empty() || n <= 0 || n > nums.size()) return -1;
        //return partition(nums, 0, nums.size() - 1, nums.size() - n);
    
    return divideConquer(nums, 0, nums.size()-1, nums.size() - n + 1);
}

int divideConquer(vector<int>& num, int start, int end, int k)
{
    if (start >= end) return num[start];
    
    int left(start), right(end);
    int mid = start + (end - start)/2;
    
    while(left <= right)
    {
        while(left <= right && num[left] < num[mid]) left++;
        while(left <= right && num[right] > num[mid]) right--;
        
        if (left <= right)
        {
            swap(num[left], num[right]);
            left++;
            right--;
        }
    }
    
    if (k <= right - start + 1)
        return divideConquer(num, start, right, k);
    
    if (k >= left - start + 1)
        return divideConquer(num, left, end, k - (left - start));
    
    return num[right + 1];
}
    int partition(vector<int>& nums, int start, int end, int ki)
    {
        if (start >= end) return nums[ki];
        
        int mid = start + (end - start)/2;
        int pivot = nums[mid];
        
        int left(start), right(end);
        while(left <= right)
        {
            while (left <= right && nums[left] < pivot)
            { left++; }
            
            while (left <= right && nums[right] > pivot)
            { right--;}
            
            if (left <= right)
            {
                swap(nums[left++], nums[right--]);
            }
        }
        
        if (ki >= left)
            return partition(nums, left, end, ki);
        if (ki <= right)
            return partition(nums, start, right,ki);
        
        return nums[ki];
    }
};