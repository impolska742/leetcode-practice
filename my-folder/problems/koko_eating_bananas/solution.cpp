class Solution {
public:
    bool canFinishUnderTimeLimit(vector<int> &piles,long long int mid,int h) {
        long long int tempHours = 0;
        
        for(int i = 0; i < piles.size(); i++) {
            tempHours += (piles[i] + mid - 1) / mid;
        }
        if(tempHours <= h) return true;
        else return false;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int  lo = 1;
        long long int  hi = 0;
        for(auto &it: piles) hi += it;
        int ans = 0;
        while(lo <= hi) {
            long long int mid = lo + (hi - lo)/2;
            if(canFinishUnderTimeLimit(piles, mid, h)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};