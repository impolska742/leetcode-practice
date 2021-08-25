class Solution {
public:  
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> map;
        for(int i = 0; i < arr.size(); i++) {
            map[arr[i]]++;
        }
        
        // for(int i = 0; i < arr.size(); i++) {
        //     cout << arr[i] << " " << map[arr[i]] << endl;
        // }
        
        for(int i = 0; i < arr.size(); i++) {
            if(map[arr[i]] > 0 and map[arr[i] * 2] > 0) {
                if(arr[i] == 0) {
                    if(map[0] > 1) return true;
                } else {
                    return true;
                }
            }
        }
        return false;
    }
};