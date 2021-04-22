class Solution {
public:
    string longestPalindrome(string s) {
    int n = s.length();
	int best_len = 0;
	string best_s = "";

	for (int mid = 0; mid < n; mid++) {
		for (int x = 0; mid - x >= 0 and mid + x < n; x++) {
			int len = 2 * x + 1;
			if (s[mid - x] != s[mid + x]) {break;}

			else {
				if (len > best_len) {
					best_len = len;
					best_s = s.substr(mid - x, len);
				}
			}
		}
	}

	for (int mid = 0; mid < n - 1 ; mid++) {
		for (int x = 1; mid - x + 1 >= 0 and mid + x < n; x++) {
			int len = 2 * x;
			if (s[mid - x + 1] != s[mid + x]) break;
			else {
				if (len > best_len) {
					best_len = len;
					best_s = s.substr(mid - x + 1, len);
				}
			}
		}
	}

	return best_s;
    }
};