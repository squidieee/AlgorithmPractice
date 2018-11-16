/* 
793. Intersection of Arrays
Give a number of arrays, find their intersection, and output their intersection size.

Example
Given [[1,2,3],[3,4,5],[3,9,10]], return 1

explanation:
Only element 3 appears in all arrays, the intersection is [3], and the size is 1.
Given [[1,2,3,4],[1,2,5,6,7][9,10,1,5,2,3]], return 2

explanation:
Only element 1,2 appear in all arrays, the intersection is [1,2], the size is 2.
Notice
The total number of all array elements is not more than 500000.
There are no duplicated elements in each array.
*/

class Solution {
public:
    /* Merge two pointer version
    */
    int intersectionOfArrays(vector<vector<int>> &arrs){
        if (arrs.empty()) return 0;
        if (arrs.size() == 1) return arrs[0].size();
        
        std::sort(arrs[0].begin(), arrs[0].end());
        vector<int> mergedArray = intersectionOfTwpArrays(arrs[0], arrs[1]);
        
        for(int i = 2; i < arrs.size(); i++)
        {
            mergedArray = intersectionOfTwpArrays(mergedArray, arrs[i]);
        }
        
        return mergedArray.size();
    }
    
    vector<int> intersectionOfTwpArrays(vector<int>& sortedArray, vector<int>& nextArray)
    {
        if (sortedArray.empty()) return sortedArray;
        
        std::sort(nextArray.begin(), nextArray.end());
        vector<int> mergedArray;
        
        for(int num: nextArray)
        {
            if (binarySearch(num, sortedArray))
                mergedArray.push_back(num);
        }
        
        return mergedArray;
    }
    
    bool binarySearch(int num, vector<int>& nums)
    {
        int start(0), end(nums.size()-1);
        
        while(start + 1 < end)
        {
            int mid = start + (end - start)/2;
            if (num > nums[mid])
                start = mid;
            else if (num < nums[mid])
                end = mid;
            else
                return true;
        }
        
        return nums[start] == num || nums[end] == num;
    }
    
    /** hash map version
     * @param arrs: the arrays
     * @return: the number of the intersection of the arrays
     */
    int intersectionOfArrays1(vector<vector<int>> &arrs) {
        if (arrs.empty()) return 0;
        
        int min_size(INT_MAX);
        int min_idx(0);
        for (int i = 0; i < arrs.size(); i++)
        {
            if (arrs[i].size() < min_size )
            {
                min_size = arrs[i].size();
                min_idx = i;
            }
        }
        
        if ( min_size == 0) return 0;
        
        unordered_map<int, int> map;
        for (int num: arrs[min_idx])
        {
            if (map.find(num) == map.end())
                map.insert({num, 1});
        }
        
        for (int i = 0; i < arrs.size(); i++)
        {
            if (i == min_idx) continue;
            hashHelper(arrs[i], map);
        }
        
        int result(0);
        for (auto it = map.begin(); it != map.end(); it++)
        {
            if (it->second == arrs.size()) result++;
        }
        return result;
    }
    
    void hashHelper(const vector<int>& nums, unordered_map<int, int>& map)
    {
        for (int num: nums)
        {
            if (map.find(num) != map.end())
            {
                map.at(num)++;
            }
        }
    }
};