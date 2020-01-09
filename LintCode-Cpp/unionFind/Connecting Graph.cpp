/* 
589. Connecting Graph

Given n nodes in a graph labeled from 1 to n. There is no edges in the graph at beginning.

You need to support the following method:

connect(a, b), add an edge to connect node a and node b`.
query(a, b), check if two nodes are connected
Example
Example 1:

Input:
ConnectingGraph(5)
query(1, 2)
connect(1, 2)
query(1, 3) 
connect(2, 4)
query(1, 4) 
Output:
[false,false,true]

Example 2:

Input:
ConnectingGraph(6)
query(1, 2)
query(2, 3)
query(1, 3)
query(5, 6)
query(1, 4)

Output:
[false,false,false,false,false]*/
class ConnectingGraph {
private:
    vector<int> _parent;
    
    int find(int a)
    {
        if(_parent[a] == 0) return a;
        
        _parent[a] = find(_parent[a]);
        return _parent[a];
    }

public:
    /*
    * @param n: An integer
    */ConnectingGraph(int n) {
        _parent.resize(n + 1, 0);
    }

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */
    void connect(int a, int b) {
        int p_a = find(a);
        int p_b = find(b);
        if(p_a != p_b)
            _parent[p_a] = p_b; // modify the parent, not the node 
    }

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: A boolean
     */
    bool query(int a, int b) {
        int p_a = find(a);
        int p_b = find(b);
        return p_a == p_b;
    }
};

// brutal force:
// connecting O(1) query O(n) TLE 

// Union find:
// each node has a parent
// if 0: parent is itself 
// when two nodes are connected, set one node as the parent of the other
