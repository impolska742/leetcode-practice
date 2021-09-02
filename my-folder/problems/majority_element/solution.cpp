class Solution {
public:
    int majorityElement(vector<int>& arr) {
        // Finding a candidate
        int res = 0, cnt = 1;
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            if(arr[res] == arr[i]) cnt++;
            else cnt--;
            
            if(cnt == 0) {
                cnt = 1;
                res = i;
            }
        }
        
        return arr[res];
    }
};