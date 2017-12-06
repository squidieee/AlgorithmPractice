/* 
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
/*      //brutal force 
         int cnt=0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == k)
                cnt++;
            int residue = k - nums[i];
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] == residue)
                    cnt++;
                residue = residue - nums[j];
            }
        }
        return cnt;
        */
        map<int,int> sums;
        sums[0]=1;
        int sum(0),cnt(0);
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            
            if(sums.count(sum-k)!=0)
                    cnt += sums[sum-k];
           
            if(sums.count(sum)==0)
            {                
                sums.insert(pair<int,int>(sum, 1));                
            }
            else
                sums[sum]++; 
        }
        return cnt;

    }
};