class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
	vector<vector<int>> Triangle(numRows);

	for (int i = 0; i < numRows; i++) {
		// Changing the size of each row
		Triangle[i].resize(i + 1);
		// Setting the first and the last values as 1
		Triangle[i][0] = Triangle[i][i] = 1;

		for (int j = 1; j < i; j++) {
			Triangle[i][j] = Triangle[i - 1][j - 1] + Triangle[i - 1][j];
		}
	}

	return Triangle;
}
};