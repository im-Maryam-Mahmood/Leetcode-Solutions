class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0); 
        vector<int> result;
        function<bool(int)> dfs = [&](int node) {
            if (state[node] > 0) return state[node] == 2; 
            state[node] = 1; 
            for (int neighbor : graph[node]) {
                if (state[neighbor] == 2) continue;
                if (state[neighbor] == 1 || !dfs(neighbor)) return false;
            }
            state[node] = 2; 
            return true;
        };
        for (int i = 0; i < n; i++) if (dfs(i)) result.push_back(i); 
        return result;
    }
};
