class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        // Write your code here
        int i = 0, j = 0;
        while(i < name.length() and j < typed.length()) {
            // cout << "i :: " << i << " " << name.substr(i) << endl;
            // cout << "j :: " << j << " " << typed.substr(j) << endl;

            if(name[i] == typed[j]) {
                i++, j++;
            } else if(i > 0 and name[i - 1] == typed[j]){
               j++;
            } else {
                return false;
            }
        }

        if(j == typed.length() and i == name.length())
            return true;
        else {
            if(i != name.length()) return false;
            else {
                if(j != typed.length()) {
                    bool ans = true;
                    while(j < typed.length()) {
                        if(typed[j] == name.back()) j++;
                        else {
                            ans = false;
                            break;
                        }
                    }

                    return ans;
                }
            }
        }
        return true;
    }
};