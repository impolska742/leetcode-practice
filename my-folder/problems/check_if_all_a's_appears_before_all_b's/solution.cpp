class Solution {
public:
    bool checkString(string s) {
        if(s.find("ba") == string::npos)
            return true;
        else
            return false;
    }
};