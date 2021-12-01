class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        if(words.size() == 1) return 1;
        vector<string> table = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> uniqueMorseCodes;
        for(auto word : words) {
            string s = "";
            for(auto ch : word) {
                s += table[ch - 'a'];
            }
            uniqueMorseCodes.insert(s);
        }
        
        return uniqueMorseCodes.size();
    }
};