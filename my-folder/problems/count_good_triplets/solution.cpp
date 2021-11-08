class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int ans = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    if(abs(arr[i] - arr[j]) <= a) {
                        if(abs(arr[j] - arr[k]) <= b) {
                            if(abs(arr[i] - arr[k]) <= c) {
                                if(i != j and j != k and k != i) 
                                {
                                    // cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};