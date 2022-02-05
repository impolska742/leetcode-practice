class Solution {
public:
    vector<string> res;
    string str = string(10, '0');
    
    string convertToTime() {
        int hours = 0, minutes = 0;
        int pow = 1;
        for(int i = 3; i >= 0; i--) {
            if(str[i] == '1') hours += pow;
            pow *= 2;
        }
        
        pow = 1;
        for(int i = 9; i >= 4; i--) {
            if(str[i] == '1') minutes += pow;
            pow *= 2;
        }
        
        if(minutes >= 60 or hours > 11)
            return "";
        
        string hrs = to_string(hours);
        string min = "";
        // if(hours < 10) hrs += '0';
        if(minutes < 10) min += '0';
        min += to_string(minutes);

        
        return hrs + ":" + min;
    }
    
    void help(int idx, int bits) {
        if(idx == 10) {
            if(bits == 0) {
                string time = convertToTime();
                if(time.size() > 0)
                    res.push_back(time);
            }
            return;
        }
        
        help(idx + 1, bits);
        
        str[idx] = '1';
        help(idx + 1, bits - 1);
        str[idx] = '0';
    }
    
    vector<string> readBinaryWatch(int turnedOn) {
        res.clear();
        if(turnedOn <= 8)
            help(0, turnedOn);
        return res;
    }
};