/* 
57. 3Sum
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Example
For example, given array S = {-1 0 1 2 -1 -4}, A solution set is:

(-1, 0, 1)
(-1, -1, 2)
Notice
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)

The solution set must not contain duplicate triplets.
*/

class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @return: Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int>> threeSum(vector<int> &numbers) {
        vector<vector<int>> triplets;
        if (numbers.empty() || numbers.size() < 3) return triplets;
        
        sort(numbers.begin(), numbers.end());

        for (int i = 0; i < numbers.size() - 2; i++ )
        {
            int target = -numbers[i];
            if (i > 0 && numbers[i] == numbers[i - 1])
                continue;
                
            int start(i+1), end(numbers.size()-1);
            
            while (start < end)
            {
                int twosum = numbers[start] + numbers[end];
                if (twosum > target)
                {
                    end--;
                }
                else if (twosum < target)
                {
                    start++;
                }
                else
                {
                    vector<int> triplet(3);
                    triplet[0] = numbers[i];
                    triplet[1] = numbers[start];
                    triplet[2] = numbers[end];
                    start++;
                    end--;
                    
                    if ( !triplets.empty() && (triplets[triplets.size()-1][1] == triplet[1] && triplets[triplets.size()-1][2] == triplet[2]))
                    continue;
                    triplets.push_back(triplet);
                }
            }
        }
        
    }
    
};