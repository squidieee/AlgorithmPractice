/* 
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/
/* 
class ListNodeMin
{
public:
    int val;
    ListNodeMin* next;
    ListNodeMin* min;
    ListNodeMin(int x): val(x), next(NULL), min(this){}   
};

class MinStack {
public:
    ListNodeMin* head;
    MinStack(): head(NULL) {}
    
    void push(int x) {
        ListNodeMin* prev = head;
        head = new ListNodeMin(x);
        head->next = prev;
        if (prev!=NULL && prev->min->val < x)
        {
            head->min = prev->min;
        }
    }
    
    void pop() {
        ListNodeMin* prev = head;
        head = head->next;
        delete prev;
    }
    
    int top() {
        if(head==NULL)
            throw runtime_error("empty stack");
        return head->val;
    }
    
    int getMin() {
        if(head==NULL)
            throw runtime_error("empty stack");
        return head->min->val;
    }
};
*/
    
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> vals;
    stack<int> mins;
    
    MinStack() {}
    
    void push(int x) {
        vals.push(x);
        if (mins.empty() || x <= mins.top())
            mins.push(x);
    }
    
    void pop() {
        if (vals.top()==mins.top())
            mins.pop();            
        vals.pop();
    }
    
    int top() {
        return vals.top();
    }
    
    int getMin() {
        return mins.top();
    }
};    
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */