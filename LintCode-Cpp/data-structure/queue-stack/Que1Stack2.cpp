/* 
40. Implement Queue by Two Stacks
As the title described, you should only use two stacks to implement a queue's actions.

The queue should support push(element), pop() and top() where pop is pop the first(a.k.a front) element in the queue.

Both pop and top methods should return the value of first element.

Example
push(1)
pop()     // return 1
push(2)
push(3)
top()     // return 2
pop()     // return 2
Challenge
implement it by two stacks, do not use any other data structure and push, pop and top should be O(1) by AVERAGE.
*/

class MyQueue {
public:
    MyQueue() {
        // do intialization if necessary
    }

    /*
     * @param element: An integer
     * @return: nothing
     */
    void push(int element) {
        _instack.push(element);
    }

    /*
     * @return: An integer
     */
    int pop() {
        if (_outstack.empty())
        {
            moveStack();
        }
        int num = _outstack.top();
        _outstack.pop();
        return num;
    }

    /*
     * @return: An integer
     */
    int top() {
        if (_outstack.empty())
        {
            moveStack();
        }
        return _outstack.top();
    }
    
    // move only when outStack is empty
    // this is to make sure the sequence is correct
    void moveStack()
    {
        while(!_instack.empty())
        {
            _outstack.push(_instack.top());
            _instack.pop();
        }
    }
    
private:

stack<int> _instack;
stack<int> _outstack; 
    
};