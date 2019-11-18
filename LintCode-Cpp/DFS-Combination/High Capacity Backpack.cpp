/* 
1382. High Capacity Backpack

Given a backpack capacity s, giving n items, the value of the i-th item is vi, the volume of the i-th item is ci, ask how much worth of the item the backpack can hold, and output this maximum value. (Each item can only be used once)

Example
Example 1:

Input:s = 10, v = [1,2,3], c = [3,5,7]
Output:4.
Explanation:Put the 0th item and the 2nd item in the backpack.
Example 2:

Input:s = 10, v = [1,5,3], c = [4,5,7].
Output:6
Explanation:Put the 0th item and the 1st item in the backpack.
Notice
1 <= s, vi, ci <= 10^13
1 <= n <= 31
*/

class Solution {
public:
    /**
     * @param s: The capacity of backpack
     * @param v: The value of goods 
     * @param c: The capacity of goods
     * @return: The answer
     */
    long long getMaxValue(int s, vector<int> &v, vector<int> &c) {
        vector<pair<int, int>> items;
        for(int i = 0; i < v.size(); i++)
        {
            items.push_back(std::make_pair(v[i], c[i]));
        }
        std::sort(items.begin(), items.end(), std::greater<pair<int, int>>());
        
        vector<long long> postSum(v.size());
        postSum[postSum.size() - 1] = items.back().second;
        for(int i = postSum.size() - 2; i >=0; i--)
        {
            postSum[i] = postSum[i + 1] + items.back().second;
        }

        long long result = 0;
        dfs(items, s, 0, 0, 0, postSum, result);
        
        return result;
    }
    
    void dfs(vector<pair<int,int>>& items, int s, int start, int sumCap, long long sumVal, vector<long long>& postSum, long long& result)
    {
        for(int i = start; i < items.size(); i++)
        {
            
            if (sumCap + items[i].second > s) continue;
            if (sumVal + postSum[i] <= result) return;

            sumCap += items[i].second;
            sumVal += items[i].first;
            result = max(result, sumVal);
            dfs(items, s, i + 1, sumCap, sumVal, postSum, result);
            // back trace
            sumCap -= items[i].second;
            sumVal -= items[i].first;
        }
        
    }
};

// Sol1: brutal force
// find all combinations from items
// quit if sum of ci exceeds capacity
// keep updating the largest value
// TLE 

// Improvement:
// How to prun?
// sort first and trim the branch based on sorted value
// 1. sort by capacity ascendingly: 
// prun branches when sumCap > s
// TLE
// 2. sort by value descendingly: 
// prun branches when current branch result + postSum of values < current best
// (the best we can do in this branch)
// PASS

// The first case helps when the data set has multiple combinations of items which
// have sum of capacities easily exceed s 
// So the branches containning "large" objects get trimmed
// It doesn't help when we have lots of objects with small capacities (compared to s) 
// and sum of majority does not exceed s
// then we have to go through all possibilities causing TLE

// The second case solves this problem
// It does not know sequence of capacities but it knows sequence of values
// It assumes "we are likely to find the result composed of items with top values"
// since top values are computed first, it also assumes we may find best result first
// So it pruns later branches which does not have full performance better than current result

