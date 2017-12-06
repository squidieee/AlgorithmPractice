/* 
Given an integer array, find a subarray with sum closest to zero. Return the indexes of the first number and last number.

Example
Given [-3, 1, 1, -3, 5], return [0, 2], [1, 3], [1, 1], [2, 2] or [0, 4].

*/

class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> &nums) {
        // write your code here
        unordered_map<int,int> sums;
        sums[0]= -1;
        int sum =0;
        vector<int> idx(2);
        for(int i = 0;i < nums.size();i++)
        {
            sum+=nums[i];
            unordered_map<int,int>::iterator it = sums.find(sum);
            if(it==sums.end())
                sums.insert(pair<int,int>(sum,i));
            else
            {
                idx[0] = it->second;
                idx[1] = i;
                if (idx[0] > idx[1])
                {
                    idx[1]++;
                    swap(idx[1], idx[0]);
                }
                else if (idx[0] < idx[1])
                {
                    idx[0]++;
                }                
                return idx;
            }
        }
        
        int diff = INT_MAX;
        unordered_map<int,int>::iterator prev_it = sums.begin();
        for (unordered_map<int,int>::iterator it = sums.begin(); it != sums.end(); ++it)
        {
            if (it!=sums.begin())
            {
                int temp = abs(it->first - prev_it->first);
                if (temp <= diff)
                {
                    diff = temp;
                    
                    idx[0] = it->second;
                    idx[1] = prev_it->second;
                }                
            }
            prev_it = it;
        }
        
        if (idx[0] > idx[1])
        {
            idx[1]++;
            swap(idx[1], idx[0]);
        }
        else if (idx[0] < idx[1])
        {
            idx[0]++;
        }
        

        return idx;
    }
};