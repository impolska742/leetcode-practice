class Solution {
public:
    int binToDecimal(string bin) {
        int n = bin.size();
        int res = 0;
        int p = 1;
        int idx = n - 1;
        while (idx >= 0) {
            res += (bin[idx] - '0') * p;
            idx--;
            p *= 2;
        }

        return res;
    }
    
    vector<string> help(int n) {
        if (n == 1) return {"0", "1"};
        vector<string> recursionResult = help(n - 1);
        vector<string> myResult;
        for (int i = 0; i < recursionResult.size(); i++)
            myResult.push_back("0" + recursionResult[i]);
        for (int i = recursionResult.size() - 1; i >= 0; i--)
            myResult.push_back("1" + recursionResult[i]);
        return myResult;
    }
    
    vector<int> grayCode(int n) {
        vector<int> result;
        vector<string> temp = help(n);
        for (auto it : temp) result.push_back(binToDecimal(it));
        return result;
    }
};