class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD = 1'000'000'007;
        vector<int> sub;
        for( int i = 0; i < n; ++i ){
            int currsum = 0;
            for( int j = i; j < n; ++j ) {
                currsum += nums[j];
                sub.push_back(currsum);
            }
        }
        sort( sub.begin(), sub.end() );
        int long long  res = 0;
        for( int i = left - 1; i < right; ++i ){
            res = ( res + sub[i] ) % MOD;
        }
        return res;
    }
};