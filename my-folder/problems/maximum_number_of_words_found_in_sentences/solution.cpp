class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxCnt = INT_MIN;
        for(auto line : sentences) {
            int cnt = 1;
            for(auto ch : line) if(ch == ' ') cnt++;
            maxCnt = max(maxCnt, cnt);
        }
        return maxCnt;
    }
};