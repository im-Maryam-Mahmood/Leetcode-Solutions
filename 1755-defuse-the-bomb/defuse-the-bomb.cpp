class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n,0);
        if(k==0) return ans;
        int start = 1;
        int end = k;
        if(k<0) {
            k = k*-1;
            start = n-k;
            end = n-1;
        }
        int sum =0;
        for(int i=start ; i<=end; i++)  sum = sum + code[i];
        for(int i=0; i<n; i++) {
            ans[i] = sum;
            sum = sum - (code[start++ % n]);
            sum = sum + (code[++end % n]);
        }
        return ans;
    }
};