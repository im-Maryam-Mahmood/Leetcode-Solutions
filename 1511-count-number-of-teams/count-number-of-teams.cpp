class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        if (n < 3) return 0;
        int count = 0;
        for (int j = 0; j < n; ++j) {
            int less_left = 0, more_left = 0;
            int less_right = 0, more_right = 0;
            for (int i = 0; i < j; ++i) {
                if (rating[i] < rating[j]) ++less_left;
                if (rating[i] > rating[j]) ++more_left;
            }
            for (int k = j + 1; k < n; ++k) {
                if (rating[k] < rating[j]) ++less_right;
                if (rating[k] > rating[j]) ++more_right;
            }
            count += less_left * more_right; 
            count += more_left * less_right; 
        }
        
        return count;
    }
};