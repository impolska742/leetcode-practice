class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(right.size() > 0 && right.top() <= num) {
            right.push(num);
        } else {
            left.push(num);
        }
        
        // balancing
        if(left.size() - right.size() == 2) {
            right.push(left.top());
            left.pop();
        }
        
        if(right.size() - left.size() == 2) {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        // cout << left.top() << " " << right.top() << '\n';
        if(left.size() > right.size()) return double(left.top());
        else if(left.size() < right.size()) return double(right.top());
        else return double(left.top() + right.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */