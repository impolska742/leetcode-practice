class Solution {
public:
    bool isPowerOfTwo(int n) {
        return floor(log2(n)) == ceil(log2(n)) and abs(n);
    }
};