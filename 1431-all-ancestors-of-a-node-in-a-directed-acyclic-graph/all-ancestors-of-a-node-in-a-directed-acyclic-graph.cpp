class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
         vector<vector<int>> graph(n), answer(n);
        vector<int> in_degree(n, 0);
        vector<set<int>> ancestors(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            in_degree[edge[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : graph[node]) {
                ancestors[neighbor].insert(node);
                ancestors[neighbor].insert(ancestors[node].begin(), ancestors[node].end());
                if (--in_degree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            answer[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
        }
        return answer;
    }
};