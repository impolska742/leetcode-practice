class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        long long int p = pow(2, 31);
        uint32_t x = 0;
        int cnt = 0;
        while(n and cnt < 32) {
            if(n % 2 == 1)
                x += p;
            p /= 2;
            n /= 2;
            cnt++;
        }
        
        return x;
    }
};