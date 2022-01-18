class Solution {
public:
    int help(vector<string>& words, vector<int>& freq, vector<int>& score, int idx = 0) {
        // base case
        if (idx == words.size()) {
            return 0;
        }

        // not included
        int not_included = help(words, freq, score, idx + 1);

        // current word to be included
        int curr_word_score = 0;
        string word = words[idx];

        bool flag = true; // flag :: true, if word can be included

        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];

            if (freq[ch - 'a'] == 0) {
                flag = false;
            }

            freq[ch - 'a']--;
            curr_word_score += score[ch - 'a'];
        }

        // included
        int included = 0;
        if (flag) {
            included = curr_word_score + help(words, freq, score, idx + 1);
        }

        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            freq[ch - 'a']++;
        }

        return max(not_included, included);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26, 0);
        for (auto &letter : letters)
            freq[letter - 'a']++;
        
        return help(words, freq, score);
    }
};