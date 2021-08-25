class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        long long int power = n;
        if(n == 0) return 1;
        if(n < 0) {
            x = (double) (1/x);
            power *= (-1);
        }
        while(power != 0) {
            if(power & 1) {
                power = power - 1;
                res = (res * x);
            }
            else {
                x *= x;
                power = power/2;
            }
        }
        
        return res;
    }
};