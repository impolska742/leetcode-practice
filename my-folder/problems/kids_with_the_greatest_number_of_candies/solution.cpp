class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = INT_MIN;
        for(int num : candies) {
            maxCandies = max(maxCandies, num);
        }
        
        int n = candies.size();
        vector<bool> result(n);
        for(int i = 0; i < n; i++) {
            if(candies[i] + extraCandies >= maxCandies) result[i] = true;
            else result[i] = false;
        }
            
            
        return result;
    }
};