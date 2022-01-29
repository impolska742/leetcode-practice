class Solution {
public:
    vector<string> codes = {
                   "---", 
            "---", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };
    vector<string> answer;
    void help(string &digits, string asf) {
        if(digits.size() == 0) {
            if(asf.length() > 0)
                answer.push_back(asf);
            return;
        }
        
        char fc = digits[0];
        string ros = digits.substr(1);
        string code = codes[fc - '0'];
        
        for(auto ch : code) {
            help(ros, asf + ch);
        }
    }
    vector<string> letterCombinations(string digits) {
        answer.clear();
        help(digits, "");
        return answer;
    }
};