/* 
1219. Heaters
中文English
Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.

Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered by those heaters.

So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.

Example
Example 1:

Input: [1,2,3],[2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
Example 2:

Input: [1,2,3,4],[1,4]
Output: 1
Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.
Notice
1.Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
2.Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
3.As long as a house is in the heaters' warm radius range, it can be warmed.
4.All the heaters follow your radius standard and the warm radius will the same.
*/
class Solution {
public:
    /**
     * @param houses: positions of houses
     * @param heaters: positions of heaters
     * @return: the minimum radius standard of heaters
     */
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        if (heaters.empty() || houses.empty()) return -1;

        std::sort(heaters.begin(), heaters.end());
        int maxDist(0);
        for(int i = 0; i < houses.size(); i++)
        {
            int start(0), end(heaters.size() - 1);
            while(start + 1 < end)
            {
                int mid = start + (end - start)/2;
                if(heaters[mid] < houses[i])
                {
                    start = mid;
                }
                else
                {
                    end = mid;
                }
            }
            
            // compute the distance
            int currDist = min(abs(houses[i] - heaters[start]), 
                               abs(houses[i] - heaters[end]));
            maxDist = max(maxDist, currDist);
        }
        
        return maxDist;
    }
};

// m houses, n heaters
// 1. sort heaters O(nlogn)
// 2. for each house, find the closest heaters: 
//    binary search of target house in the heater array O(mlogn) 
//    record dist(house, closest_heater) = abs(house, closest_heater)
// 3. find max dist