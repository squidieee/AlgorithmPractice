/* 
1281. Top K Frequent Elements

Given a non-empty array of integers, return the k most frequent elements.

Example
Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Notice
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

class Solution {
public:
    /**
     * @param nums: the given array
     * @param k: the given k
     * @return: the k most frequent elements
     */
    vector<int> topKFrequent(vector<int> &nums, int k) {
        /* Sol3 */
        unordered_map<int,int> map;
        vector<std::pair<int,int>> pairs;
        for(int i = 0; i < nums.size(); i++)
        {
            if(map.find(nums[i])!=map.end())
            {
                pairs[map[nums[i]]].first += 1;
            }
            else
            {
                pairs.push_back(std::make_pair(1, nums[i]));
                map.insert({nums[i], pairs.size() - 1});
            }
        }        
        
        int targetIdx = pairs.size() - k;
        quickSelectHelper(pairs, 0, pairs.size() - 1, targetIdx);
        
        vector<int> result;
        for(int i = pairs.size() - 1; i >= targetIdx; i--)
        {
            result.push_back(pairs[i].second);
        }
        
        return result;
        
        /* Sol1 */
        /*
        unordered_map<int,int> elemCntMap;
        for(int i = 0; i < nums.size(); i ++)
        {
            elemCntMap[nums[i]]++;
        }
        
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> minHeap;
        for(auto& p: elemCntMap)
        {
            minHeap.push(std::make_pair(p.second, p.first));
            if(minHeap.size() > k)
            {
                minHeap.pop();
            }
        }
        
        vector<int> result;
        while(!minHeap.empty())
        {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return result;
        */
    }
    
    /*Sol3 helper func*/
    void quickSelectHelper(vector<std::pair<int,int>>& pairs, int start, int end, int targetIdx)
    {
        if (start >= end) return;
        
        int left(start), right(end);
        int pivot = pairs[start + (end-start)/2].first;
        while(left <= right)
        {
            while(left <= right && pairs[left].first < pivot)
            {
                left++;
            }
            
            while(left <= right && pairs[right].first > pivot)
            {
                right--;
            }
            
            if(left <= right)
            {
                pairs[left].swap(pairs[right]);
                left++;
                right--;
            }
        }
        
        if (left < targetIdx)
            quickSelectHelper(pairs, left, end, targetIdx);
        if (right >= targetIdx)
            quickSelectHelper(pairs, start, left - 1, targetIdx);
    }
    
};



// Sol 1: hashMap + Heap
// hash map: key = number, val = count
// Space O(k) Time O(n)
// the use a maxHeap to insert count as key and element as val
// then pop the top of maxHeap 
// Space O(n) Time O(nlogn)
// Total: Space O(n) Time O(nlogn)

// Improvement1: 
// use a minHeap instead of maxHeap
// compare if cnt > minHeap top, then pop the top and insert the cnt
// since only k numbers are in the tree, each insertion costs logk
// Space O(n) Time O(nlogk)

// Sol 2: hashMap + sort by frequency
// hash map: key = number, val = count
// Space O(k) Time O(n)
// then sort the keys based on val of hash map 
// Time O(nlogn)
// pick up the top k
// TIme O(k)

// Sol 3: hashMap + QuickSelect
// hash map: key = number, val = count
// Space O(k) Time O(n)
// then do a top k largest quick select on the val (need to first put pairs in an array)
// pop first k from the array
// Space O(n) Time O(n)