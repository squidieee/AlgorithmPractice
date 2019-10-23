/* 
657. Insert Delete GetRandom O(1)
Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
Example
// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 2 is the only number in the set, getRandom always return 2.
randomSet.getRandom();
*/

class RandomizedSet {
public:
    RandomizedSet() {
        // do intialization if necessary
    }

    /*
     * @param val: a value to the set
     * @return: true if the set did not already contain the specified element or false
     */
    bool insert(int val) {
        if (_map.find(val) != _map.end())
        { 
            return false;
        }
        
        _map.insert({val, _array.size()});
        _array.push_back(val);
        return true;
    }

    /*
     * @param val: a value from the set
     * @return: true if the set contained the specified element or false
     */
    bool remove(int val) {
        if (_map.find(val) == _map.end())  return false;
        
        int idx = _map.at(val);
        _map.erase(val);
        
        _array[idx] = _array.back();
        if (_map.find(_array[idx]) != _map.end()) _map.at(_array[idx]) = idx;
        _array.pop_back();
        return true;
    }

    /*
     * @return: Get a random element from the set
     */
    int getRandom() {
        if (_array.size() == 0) return -1;
        int idx = std::rand() % _array.size();
        return _array[idx];
    } 
    
private:
    // if use hash map, insert/remove O(1), but how about random? 
    // need a mapping from random 1~n to keys
    // if use array to store the mapping, getRandom O(1)
    // insert: if not exist in map, add to map and array O(1)
    // remove: if exist in map, remove key, use map val to go to array
    //         erase the slot in array (by copying the last val to this slot, pop_back())
    std::unordered_map<int, int> _map;
    std::vector<int> _array;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param = obj.insert(val);
 * bool param = obj.remove(val);
 * int param = obj.getRandom();
 */