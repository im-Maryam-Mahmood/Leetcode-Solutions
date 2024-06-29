class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
         vector<vector<int>> adj(n), ans(n);

        for (auto& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        for (int i = 0; i < n; i++) {
            dfs(adj,ans,i,i);
        }
        
        return ans;
    }
    void dfs(vector<vector<int>>& adj, vector<vector<int>>& ans, int& parent, int& child) {
        for (auto& ch: adj[child]) {
            if (ans[ch].size() == 0 || ans[ch].back() != parent) {
                ans[ch].push_back(parent);
                dfs(adj,ans,parent,ch);
            }
            
        }
    }
};