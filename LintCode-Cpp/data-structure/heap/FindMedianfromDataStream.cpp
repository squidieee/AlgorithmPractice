/* 
81. Find Median from Data Stream
Numbers keep coming, return the median of numbers at every time a new number added.

Example
For numbers coming list: [1, 2, 3, 4, 5], return [1, 1, 2, 2, 3].

For numbers coming list: [4, 5, 1, 3, 2, 6, 0], return [4, 4, 4, 3, 3, 3, 3].

For numbers coming list: [2, 20, 100], return [2, 2, 20].

Challenge
Total run time in O(nlogn).

Clarification
What's the definition of Median?

Median is the number that in the middle of a sorted array. If there are n numbers in a sorted array A, the median is A[(n - 1) / 2]. For example, if A=[1,2,3], median is 2. If A=[1,19], median is 1.
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: the median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        _maxHeapSize = 0;
        _minHeapSize = 0;
        if (nums.empty()) return nums;
        
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
        {
            ans.push_back( addNumber(nums[i], i + 1) );
        }
        return ans;
    }
    
    int addNumber (int num, int totalSize)
    {
        if (!_minHeap.empty() && _minHeap.top() < num) // add it to min heap
        {
            _minHeap.push(num);
            _minHeapSize++;
            
            if (_minHeapSize > _maxHeapSize) // min heap has too many numbers
            {
                _maxHeap.push(_minHeap.top());
                _minHeap.pop();
                _maxHeapSize++;
                _minHeapSize--;                
            }
        }
        else // add it to max heap
        {
            _maxHeap.push(num); 
            _maxHeapSize++;
            
            if (_maxHeapSize > (totalSize + 1)/2 ) // max heap has too many numbers
            {
                _minHeap.push(_maxHeap.top());
                _minHeapSize++;
                _maxHeap.pop();
                _maxHeapSize--;
            }
        }
        return _maxHeap.top();
    }
    
private:
    int _maxHeapSize, _minHeapSize;
    priority_queue<int, vector<int>> _maxHeap;
    priority_queue<int, vector<int>, std::greater<int>> _minHeap;
};

// start from 0:
// add a number, sort them completely: O(nlogn), total o(n^2*logn)
// not necessary
// binary search to find the index, then do insertion: O(n + logn) * n = O(n^2)
// brutal force: linear search and insertion O(n^2)

// assuming we have median for the array with length k
// adding a new number requires comparing it with the current median
// in an sorted array, this may result in four cases:
// 1. median remains
// 2. median's index - 1 is the new median
// 3. median's index + 1 is the new median
// 4. the new number is the new median

// median is the max of all elements in front of it, including itself
// maxheap to record the first half including median
// minheap to record the second half including median's index + 1
// so maxheap size >= min heap size

// each time we insert a new number into the maxheap
// maxheap should have size = (n + 1)/2 
// if its size > (n + 1)/2
// we move the top one into the minheap
