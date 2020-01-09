/* 
590. Connecting Graph II

Given n nodes in a graph labeled from 1 to n. There is no edges in the graph at beginning.

You need to support the following method:

connect(a, b), an edge to connect node a and node b
query(a), Returns the number of connected component nodes which include node a.
Example
Example 1:

Input:
ConnectingGraph2(5)
query(1)
connect(1, 2)
query(1)
connect(2, 4)
query(1)
connect(1, 4)
query(1)
Output:[1,2,3,3]
Example 2:

Input:
ConnectingGraph2(6)
query(1)
query(2)
query(1)
query(5)
query(1)

Output:
[1,1,1,1,1]
*/

class ConnectingGraph2 {
public:
    /*
    * @param n: An integer
    */ConnectingGraph2(int n) {
        _parent.resize(n+1, 0);
        _numOfCom.resize(n+1, 1);
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
        {
            _parent[p_a] = p_b;
            _numOfCom[p_a] += _numOfCom[p_b];
            _numOfCom[p_b] = _numOfCom[p_a];
        }
            
    }

    /*
     * @param a: An integer
     * @return: An integer
     */
    int query(int a) {
        int p_a = find(a);
        return _numOfCom[p_a];
    }

private:
    int find(int a)
    {
        if(_parent[a] == 0) return a;
        
        _parent[a] = find(_parent[a]);
        return _parent[a];
    }
    
    vector<int> _parent;
    vector<int> _numOfCom; // only record cnt in root nodes 
};