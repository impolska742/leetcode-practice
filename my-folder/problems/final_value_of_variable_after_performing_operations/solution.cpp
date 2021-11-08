class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for(auto op : operations) {
            if(op == "++X" or op == "X++") ans++;
            else ans--;
        }
        
        return ans;
    }
};