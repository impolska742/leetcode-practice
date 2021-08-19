class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> characters;
        for(auto character : sentence)
            characters.insert(character);
        return (characters.size() == 26);
    }
};