class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        vector<int> answer;
        int i = 0; 
        int n = arr.size();
        while(i < n) {
            int correct = arr[i] - 1;
            if(arr[i] != arr[correct]) {
                swap(arr[i], arr[correct]);
            } else {
                i++;
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(arr[i] - 1 != i) {
                answer.push_back(arr[i]);
            } 
        }
        
        return answer;
    }
};