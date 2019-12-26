/*
556. Standard Bloom Filter

Implement a standard bloom filter. Support the following method:

StandardBloomFilter(k) The constructor and you need to create k hash functions.
add(string) Add a string into bloom filter.
contains(string) Check a string whether exists in bloom filter.
Example
Example1

Input:
    StandardBloomFilter(3)
    add("lint")
    add("code")
    contains("lint")
    contains("world")
Output: [true,false]
Example2

Input:
    StandardBloomFilter(10)
    add("hello")
    contains("hell")
    contains("helloa")
    contains("hello")
    contains("hell")
    contains("helloa")
    contains("hello")
Output: [false,false,true,false,false,true]
*/

class SimpleHashFunction{
public:
    int weight;
    int capacity;
    SimpleHashFunction(int w, int c) { weight = w; capacity = c;}
    int Hash(string& str)
    {
        int result = 0;
        for(int i = 0; i < str.size(); i++)
        {
            result += str[i] + result * weight;
            result = result % capacity;
        }
        
        return result;
    }
};

class StandardBloomFilter {
public:
    /*
    * @param k: An integer
    */StandardBloomFilter(int k) {
        int m = NUM_OF_WORDS * k / LN2;
        _bitset.resize(m, false);
        for(int i = 0; i < k; i++)
        {
            _hashFuncs.push_back(new SimpleHashFunction(i * 2 + 23, m));
        }
    }

    /*
     * @param word: A string
     * @return: nothing
     */
    void add(string &word) {
        
        for(int i = 0; i < _hashFuncs.size(); i++)
        {
            int result = _hashFuncs[i]->Hash(word);
            _bitset[result] = true;
        }
    }

    /*
     * @param word: A string
     * @return: True if contains word
     */
    bool contains(string &word) {
        for(int i = 0; i < _hashFuncs.size(); i++)
        {
            int result = _hashFuncs[i]->Hash(word);
            if(!_bitset[result]) return false;
        }
        
        return true;
    }

private:
    vector<SimpleHashFunction*> _hashFuncs;
    vector<bool> _bitset;
    const int NUM_OF_WORDS = 1e4;
    const double LN2 = 0.69;
};

// goal: create k hash functions 
// each hasn function generates key with a uniform distribution in a bit array 
// Bloom filter has one big bit array bit[]
// each hash function output a number num, we set bit[num] to 1 
// when checking if a number exists or not, we compute k nums with all hash functions 
// then check each bit[num] where num comes from nums == 1 or not 