/* 
486. Merge K Sorted Arrays

Given k sorted integer arrays, merge them into one sorted array.

Example
Example 1:

Input: 
  [
    [1, 3, 5, 7],
    [2, 4, 6],
    [0, 8, 9, 10, 11]
  ]
Output: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
Example 2:

Input:
  [
    [1,2,3],
    [1,2]
  ]
Output: [1,1,2,2,3]
Challenge
Do it in O(N log k).

N is the total number of integers.
k is the number of arrays.

*/

class Node{
public:
    int row;
    int col;
    int val;
    Node(int r, int c, int v){ row = r; col = c; val = v; }
    bool operator > (const Node& node) const{
        return val > node.val;
    }
};

class Solution {
public:
    /**
     * @param arrays: k sorted integer arrays
     * @return: a sorted array
     */
    vector<int> mergekSortedArrays(vector<vector<int>> &arrays) {
       if (arrays.empty()) return vector<int>();
       return mergeInHeap(arrays);
       //return mergekSortedArraysHelper(arrays, 0, arrays.size() - 1);
    }
    
    vector<int> mergeInHeap(vector<vector<int>> &arrays)
    {
        priority_queue<Node, vector<Node>, std::greater<vector<Node>::value_type>> minHeap;
        for(int i = 0;i < arrays.size(); i++)
        {
            if(arrays[i].size() == 0) continue;
            minHeap.push(Node(i, 0, arrays[i][0]));
        }
        
        vector<int> result;
        while(!minHeap.empty())
        {
            Node curr = minHeap.top();
            minHeap.pop();
            result.push_back(curr.val);
            if(curr.col < arrays[curr.row].size() - 1)
            {
                minHeap.push(Node(curr.row, curr.col + 1, arrays[curr.row][curr.col + 1]));
            }
        }
        
        return result;
    }
    
    // O(NK^2) get min out of k for each num out of NK
    // O(NKlogK) merge sort or heap
    
    vector<int> merge2SortedArray(vector<int>& a, vector<int>& b)
    {
        if (a.empty()) return b;
        if (b.empty()) return a;
        
        vector<int> mergedArray;
        int ia(0), ib(0);
        while(ia < a.size() || ib < b.size())
        {
            if (ib > b.size() - 1 || (ia < a.size() && a[ia] <= b[ib]))
            {
                mergedArray.push_back(a[ia]);
                ia++;
            }
            else
            {
                mergedArray.push_back(b[ib]);
                ib++;
            }
        }
        return mergedArray;
    }
    
    vector<int> mergekSortedArraysHelper(vector<vector<int>> &arrays, int start, int end)
    {
        if (start == end) return arrays[start];
        if (start + 1 == end) return merge2SortedArray(arrays[start], arrays[end]);
        
        int mid = start + (end - start)/2;
        vector<int> firstHalf = mergekSortedArraysHelper(arrays, start, mid);
        vector<int> secondHalf = mergekSortedArraysHelper(arrays, mid+1, end);
        
        return merge2SortedArray(firstHalf, secondHalf);
    }
    
    
};