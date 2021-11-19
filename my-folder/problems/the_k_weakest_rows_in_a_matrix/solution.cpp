class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> table(mat.size());
        int rows = mat.size();
        int cols = mat[0].size();
        
        vector<int> ans;
        for(int i = 0; i < rows; i++) {
            int lo = 0;
            int hi = cols - 1;
            int soldiers = -1;
            while(lo <= hi) {
                int mid = lo + (hi - lo)/2;
                if(mat[i][mid] == 1) {
                    soldiers = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            
            if(soldiers != -1)
                table[i].first = soldiers + 1;
            else
                table[i].first = 0;
            table[i].second = i;
        }
        for(auto it : table) {
            cout << it.first << " " << it.second << endl;
        }
        
        sort(table.begin(), table.end());
        
       
        for(int i = 0; i < k; i++) {
            ans.push_back(table[i].second);
        }
        return ans;
    }
};