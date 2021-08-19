class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int maxAltitude = 0;
        int currAltitude = 0;
        for(int i = 0; i < n; i++) {
            currAltitude += gain[i];
            maxAltitude = max(maxAltitude, currAltitude);
        }
        
        return maxAltitude;
    }
};