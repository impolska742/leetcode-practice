class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA, sumB;
        sumA = sumB = 0;
        for(auto it : aliceSizes) sumA += it;
        for(auto it : bobSizes) sumB += it;
        
        int diff = (sumA - sumB)/2;
        
        unordered_set<int> set;
        for(auto it : aliceSizes) set.insert(it);
        
        for(auto it : bobSizes) {
            if(set.count(it + diff))
                return {it + diff, it};
        }
        
        return {};
    }
};