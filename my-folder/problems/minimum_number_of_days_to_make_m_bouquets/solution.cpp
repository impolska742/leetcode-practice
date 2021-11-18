class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m * k > bloomDay.size()) return -1;
        int lo = *std::min_element(bloomDay.begin(), bloomDay.end());
        int hi = *std::max_element(bloomDay.begin(), bloomDay.end());
        
        long long int ans = 0;
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            int bouquets = 0;
            int count = 0;
            for(int i = 0; i < bloomDay.size(); i++) {
                if(bloomDay[i] > mid) count = 0;
                else {
                    count++;
                }
                
                if(count == k) {
                    bouquets++;
                    count = 0;
                }
            }
            
            if(bouquets >= m) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};