class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int cnt = 0;
        
        while(z) {
            cnt += (z % 2);
            z /= 2;
        }
        
        return cnt;
    }
};