/* 
12. Min Stack

Implement a stack with following functions:

push(val) push val into the stack
pop() pop the top element and return it
min() return the smallest number in the stack
All above should be in O(1) cost.

Example
Example 1:

Input:
  push(1)
  pop()
  push(2)
  push(3)
  min()
  push(1)
  min()
Output:
  1
  2
  1
Example 2:

Input:
  push(1)
  min()
  push(2)
  min()
  push(3)
  min()
Output:
  1
  1
  1
Notice
min() will never be called when there is no number in the stack.
*/

class MinStack {
public:
    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) {
        _stk.push(number);
        if(_minStk.empty()) _minStk.push(number);
        else _minStk.push(std::min(_minStk.top(), number));
    }

    /*
     * @return: An integer
     */
    int pop() {
        _minStk.pop();
        int result = _stk.top();
        _stk.pop();
        return result;
    }

    /*
     * @return: An integer
     */
    int min() {
        return _minStk.top();
    }
    
private:
    stack<int> _stk;
    stack<int> _minStk;
};