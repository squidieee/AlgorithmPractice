/* 
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> intmap;
        vector<int> indices(2);
        for (int i = 0; i < nums.size(); i++)
        {
            map<int,int>::iterator it = intmap.find( target-nums[i] );
            if(it!=intmap.end())
            {
                indices[0] = i;
                indices[1] = it->second;
                return indices;
            }
            intmap.insert(pair<int,int>(nums[i],i));              
        }

    }
};