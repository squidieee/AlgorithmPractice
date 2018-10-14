/* 
607. Two Sum III - Data structure design
Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

Example
add(1); add(3); add(5);
find(4) // return true
find(7) // return false
*/


 class TwoSum {
public:
    /**
     * @param number: An integer
     * @return: nothing
     */
    void add(int number) {
        // write your code here
        if (nums.count(number)==0)
        {
            nums.insert({number,1});
        }
        else
            nums.at(number)++;
    }

    /**
     * @param value: An integer
     * @return: Find if there exists any pair of numbers which sum is equal to the value.
     */
    bool find(int value) {
        // write your code here
        if (nums.empty()) return false;
        for(auto it = nums.begin(); it != nums.end(); it++)
        {
            if (nums.count(value - it->first))
            {
                if (value == it->first * 2 && it->second == 1)
                    continue;
                return true;
            }
        }
        return false;
    }
    
    private:
    unordered_map<int,int> nums;
};