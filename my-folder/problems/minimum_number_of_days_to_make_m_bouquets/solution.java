class Solution {
    public int maxElement(int[] bloomDay) {
        int mx = Integer.MIN_VALUE;
        for(int day : bloomDay) mx = Math.max(mx, day);
        return mx;
    }
    
    public int minElement(int[] bloomDay) {
        int mn = Integer.MAX_VALUE;
        for(int day : bloomDay) mn = Math.min(mn, day);
        return mn;
    }
    
    public boolean validBouquetsSize(int[] bloomDay, int bouquetSize, int k, int m) {
        int count = 0;
        int bouquets = 0;
        
        for(int i = 0; i < bloomDay.length; i++) {
            if(bloomDay[i] > bouquetSize) count = 0;
            else count++;
            
            if(count == k) {
                bouquets++;
                count = 0;
            }
        }
        
        if(bouquets >= m) return true;
        else return false;
    }
    
    public int minDays(int[] bloomDay, int m, int k) {
        if(m * k > bloomDay.length) return -1;
        
        int lo = minElement(bloomDay), hi = maxElement(bloomDay);
        int ans = 0;
        
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if(validBouquetsSize(bloomDay, mid, k, m)) {
                ans = mid;
                hi = mid - 1;
            } else{
                lo = mid + 1;
            }
        }
        
        return ans;
    }
}