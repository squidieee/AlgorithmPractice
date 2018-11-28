/* 
642. Moving Average from Data Stream
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Example
MovingAverage m = new MovingAverage(3);
m.next(1) = 1 // return 1.00000
m.next(10) = (1 + 10) / 2 // return 5.50000
m.next(3) = (1 + 10 + 3) / 3 // return 4.66667
m.next(5) = (10 + 3 + 5) / 3 // return 6.00000
*/

class MovingAverage {
public:
    /*
    * @param size: An integer
    */MovingAverage(int size) {
        _wsize = size;
    }

    /*
     * @param val: An integer
     * @return:  
     */
    double next(int val) {
        if (_window.size() >= _wsize)
        {
            _sum = _sum - _window.front();
            _window.pop();
        }
        _window.push(val);
        _sum += val;

        return _sum / _window.size();
    }
private:

    std::queue<int> _window;
    int _wsize;
    double _sum;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param = obj.next(val);
 */