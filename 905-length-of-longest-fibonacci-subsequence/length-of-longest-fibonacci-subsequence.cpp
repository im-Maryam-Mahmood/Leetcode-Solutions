class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
       int n = arr.size();
    if (n < 3) return 0;
    
    int max_len = 0;
    vector<vector<int>> array(n, vector<int>(n, 2)); 
    for (int j = 2; j < n; ++j) {
        int i = 0, k = j - 1;
        while (i < k) {
            int sum = arr[i] + arr[k];
            if (sum < arr[j]) {
                ++i;
            } else if (sum > arr[j]) {
                --k;
            } else {
                array[k][j] = array[i][k] + 1;
                max_len = max(max_len, array[k][j]);
                ++i;
                --k;
            }
        }
    }
    
    return max_len >= 3 ? max_len : 0;
    }
};