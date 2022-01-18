class Solution {
public:
    void dfs(int i, int num, vector<int> &order) {
        if (i > num) return;

        order.push_back(i);
        for (int j = 0; j <= 9; j++) {
            dfs((10 * i) + j, num, order);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> order;
        
        for(int i = 1; i <= 9; i++)
            dfs(i, n, order);
        return order;
    }
};