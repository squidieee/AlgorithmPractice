/* 
494. Implement Stack by Two Queues
Implement a stack by two queues. The queue is first in first out (FIFO). That means you can not directly pop the last element in a queue.

Example
push(1)
pop()
push(2)
isEmpty() // return false
top() // return 2
pop()
isEmpty() // return true
*/

class Stack {
public:
    /*
     * @param x: An integer
     * @return: nothing
     */
    void push(int x) {
        if (_qid == 0) // initialization
            _qid = 1;
        
        if (_qid == 1)
            _q1.push(x);
        else
            _q2.push(x);
    }

    /*
     * @return: nothing
     */
    void pop() {
        if (_qid == 1)
        {
            moveQueue(_q1, _q2); 
            _qid = 2;
            _q1.pop();

        }
        else if (_qid == 2)
        {
            moveQueue(_q2, _q1); 
            _qid = 1;
            _q2.pop();
        }
    }

    /*
     * @return: An integer
     */
    int top() {
        if (_qid == 1)
        {
            moveQueue(_q1, _q2);
            return _q1.front();
        }
        else if (_qid == 2)
        {
            moveQueue(_q2, _q1);
            return _q2.front();
        }
        
        return -1;
    }

    /*
     * @return: True if the stack is empty
     */
    bool isEmpty() {
       return _q1.empty() && _q2.empty();
    }

private:
    queue<int> _q1;
    queue<int> _q2;
    
    int _qid; // most recent que
    
    // return true: to is empty so we move from to
    // return false: from has size of 1, we do not move
    bool moveQueue(queue<int>& from, queue<int>& to)
    {
        if (from.size() == 1)
            return false;
        
        // move from to, until one element left in from
        int len = from.size();
        for(int i = 0; i < len - 1; i++)
        {
            to.push(from.front());
            from.pop();
        }
        
        return true;
    }
};