class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int idx = 0;
        int n = arr.size();
        if(n == 1 || n == 2) return false;
        bool up = false, down = false;
        while(idx < n - 1 and arr[idx] < arr[idx + 1]) {
            if(!up) up = true;
            idx++;
        }
        while(idx < n - 1 and arr[idx] > arr[idx + 1]) {
            if(!down) down = true;
            idx++;
        }
        if(!up or !down) return false;
        return idx == n - 1;
    }
};