class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
	int n = arr.size();
	vector<int> ans;

	unordered_map<int, int> table;

	for (int i = 0; i < n; i++) {
		int B = target - arr[i];

		if (table.find(B) != table.end()) {
			ans.push_back(table[B]);
			ans.push_back(i);
			return ans;
		}

		table[arr[i]] = i;
	}

	return ans;
}
};