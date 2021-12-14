class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        deque<int> dq;
	int n = arr.size();
	vector<int> ans;

	for (int i = 0; i < n; i++) {
		// Pop the elements from the front if they are out
		// of the range
		if (!dq.empty() and dq.front() <= i - k)
			dq.pop_front();

		// Pop the elements from the back if they are less
		// than or the current item and push current item
		while (!dq.empty() and arr[dq.back()] <= arr[i])
			dq.pop_back();

		dq.push_back(i);

		if (i >= k - 1)
			ans.push_back(arr[dq.front()]);
	}

	return ans;
    }
};