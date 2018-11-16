/* 
547. Intersection of Two Arrays
Given two arrays, write a function to compute their intersection.

Example
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Challenge
Can you implement it in three different algorithms?

Notice
Each element in the result must be unique.
The result can be in any order.
*/

class Solution {
public:
    /**
     * @param nums1: an integer array
     * @param nums2: an integer array
     * @return: an integer array
     */
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
       vector<int> results;
       if (nums1.empty() || nums2.empty()) return results;
       
       //if (nums1.size() > nums2.size()) 
    //        hashHelper(nums1, nums2, results);
      // else 
    //        hashHelper(nums2, nums1, results);
       
       twoPointer(nums1, nums2, results);
       return results;
    }
    
    // two pointer version
    // Time O(mlogm + nlogn + m + n) Space O(1)
    // sort two arrays first
    // if nums1[i1] > nums2[i2] -> i2++
    // else if n1 < n2 -> i1++
    // else if n1 == n2 -> push_back
    // before compare, see if n1 or n2 == prev n1 or n2
    void twoPointer(vector<int>& nums1, vector<int>& nums2, vector<int>& results)
    {
        int i1(0), i2(0);
        
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        
        while(i1 < nums1.size() && i2 < nums2.size())
        {
            if (i1 > 0 && nums1[i1-1] == nums1[i1])
            {
                i1++;
                continue;
            }
            
            if (i2 > 0 && nums2[i2-1] == nums2[i2])
            {
                i2++;
                continue;
            }
            
            if (nums1[i1] > nums2[i2])
            {
                i2++;
            }
            else if (nums1[i1] < nums2[i2])
            {
                i1++;
            }
            else
            {
                results.push_back(nums1[i1]);
                i1++;
                i2++;
            }
        }
    }
    
    // hash table version: num2 is the smaller array for a smaller memory cost
    // Time O(m+n) Space O(min(m+n))
    
    void hashHelper(vector<int> &nums1, vector<int> &nums2, vector<int> &results)
    {
        unordered_map<int,bool> map;
        
        for(int num: nums2)
        {
            if (map.find(num) == map.end())
            {
                map.insert({num, false});
            }
        }
        
        std::sort(nums1.begin(), nums1.end()); // add only to pass the test, the order should not matter
        
        for(int num: nums1)
        {
            if (map.find(num) != map.end() && map.at(num) == false)
            {
                results.push_back(num);
                map.at(num) = true;
            }
        }
    }
    
    
};