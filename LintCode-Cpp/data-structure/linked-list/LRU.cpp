/* 
134. LRU Cache
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/

class LRUCache {
    struct Node
    {
        int val;
        int key;
        shared_ptr<Node> next;
        Node( int key, int val)
        {
            this->val = val;
            this->key = key;
            this->next = nullptr;
        }
    };
    
public:
    /*
    * @param capacity: An integer
    */
    LRUCache(int capacity) {
       // set the capacity
       _capacity = capacity;
       _size = 0;
       _head = std::make_shared<Node>(-1, 0);
       _tail = _head;
    }

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) {
        if (_map.find(key)!=_map.end())
        {
            moveKeyToTail(key);
            return _tail->val;
        }
        else
        {
            return -1;
        }
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        if (_map.find(key) == _map.end())
        {
            if (_size >= _capacity)
            {
                shared_ptr<Node> nodeToDelete = _head->next;
                // remove the head from map
                _map.erase(nodeToDelete->key);
                // update the map
                if (nodeToDelete->next != nullptr)
                    _map.at(nodeToDelete->next->key) = _head;                
                // remove from the list
                _head->next = nodeToDelete->next;
                
                _size--;
            }
            
            _map.insert({key, _tail});
            shared_ptr<Node> newNode = make_shared<Node>(key, value);
            _tail->next = newNode; // link new Node with tail
            _tail = newNode; // this is the new _tail
            _size++;
        }
        else
        {
            moveKeyToTail(key);
            _tail -> val = value;
        }
    }
    
    void moveKeyToTail(int key)
    {
       if (_tail->key == key)
         return;

        shared_ptr<Node> prevNode = _map.at(key);
        shared_ptr<Node> thisNode = _map.at(key)->next;
        shared_ptr<Node> nextNode = thisNode->next;
        
        // insert it in the end
        _tail->next = thisNode;

        // reconnect prev to next
        prevNode->next = nextNode;

        // updata the map: two nodes, prev and next

        if (nextNode!=nullptr)
            _map.at(nextNode->key) = prevNode;
        _map.at(thisNode->key) = _tail;
        
        // update tail
        _tail = _tail->next;         
    }
    
    private:
    // use a hash map to store the key and shared_ptr<Node> (prev)
    // get()-> check if key exists, yes->return value
    // use a linked list to store the vals
    // set() -> if key not exists -> insert if cache < capacity
    // if cache >= capacity -> remove the head node, add new key to tail
    // if key exists, remove the Node, add it to the tail
    
    int _capacity;
    int _size;
    unordered_map<int, shared_ptr<Node>> _map;
    shared_ptr<Node> _head;
    shared_ptr<Node> _tail;
    

    
};