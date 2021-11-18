class Solution {
public:
    bool isPossibleToShip(vector<int> &weights, int days, int mid) {
        int tempDays = 1;
        int tempSum = 0;
        for(int i = 0; i < weights.size(); i++) {
            if(tempSum + weights[i] > mid) {
                tempSum = 0;
                tempDays++;
            }
            tempSum += weights[i];
        }
        
        // cout << tempDays << " :: " << mid << endl;
        if(tempDays <= days) return true;
        else return false;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *std::max_element(weights.begin(), weights.end());
        int high = 0;
        for(int weight : weights) high += weight;
        int ans = 0;
        while(low <= high) {
            int mid = low + (high - low)/2;
            
            if(isPossibleToShip(weights, days, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};