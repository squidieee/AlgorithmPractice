/* 
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
*/
class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1;
    queue<int> q2;
    int size;
    queue<int>* ptr_q;
    
    MyStack() {
        size = 0;
        ptr_q = &q1;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
            ptr_q->push(x);
            size++;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (size <= 0)
            throw runtime_error("empty stack");
        queue<int>* backup = ptr_q == &q1? &q2: &q1;

        for(int i = 0;i < size-1;i++){
            backup->push(ptr_q->front());
            ptr_q->pop();
        }
        int backNum = ptr_q->front();
        ptr_q->pop();
        size--;
        ptr_q = backup;
        return backNum;
    }
    
    /** Get the top element. */
    int top() {
        return ptr_q->back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if (size <= 0)
            return true;
        else
            return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */