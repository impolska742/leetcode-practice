class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rows(matrix.size()), columns(matrix[0].size());

	fill(rows.begin(), rows.end(), 1);
	fill(columns.begin(), columns.end(), 1);

	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[i].size(); j++) {
			if (matrix[i][j] == 0) {
				rows[i] = 0;
				columns[j] = 0;
			}
		}
	}

	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[i].size(); j++) {
			if (rows[i] == 0 or columns[j] == 0) {
				matrix[i][j] = 0;
			}
		}
	}
    }
};