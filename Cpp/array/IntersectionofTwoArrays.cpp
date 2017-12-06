/* 
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.

*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersect;
        intersect.clear();
        if(nums1.empty() || nums2.empty())
            return intersect;
        map<int,int> num1map;
        for(int i =0; i < nums1.size(); i++)
        {
            if (num1map.find(nums1[i])==num1map.end())
                num1map.insert(pair<int,int>(nums1[i], i));            
        }
        
        for (int i=0; i < nums2.size(); i++)
        {
            map<int,int>::iterator it=num1map.find(nums2[i]);
            if (it!=num1map.end())
            {
                intersect.push_back(nums2[i]);
                num1map.erase(it);
                
            }
        }
        return intersect;
    }
};