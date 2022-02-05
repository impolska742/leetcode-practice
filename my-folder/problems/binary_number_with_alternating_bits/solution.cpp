class Solution {
public:
    bool hasAlternatingBits(int n) {
        if(n <= 2) return true;
        int prev = n % 2;
        n /= 2;
        
        while(n) {
            if(prev == n % 2) return false;
            prev = 1 - prev;
            n /= 2;
        }
        
        return true;
    }
};