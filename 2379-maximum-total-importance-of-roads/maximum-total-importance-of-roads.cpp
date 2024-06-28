class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
    vector<int> connections(n, 0);
    for (const auto& road : roads) {
        connections[road[0]]++;
        connections[road[1]]++;
    }
    sort(connections.begin(), connections.end());
    long long total_importance = 0;
    for (int i = 0; i < n; ++i) {
        total_importance += (long long)(i + 1) * connections[i];
    }
    return total_importance;

    }
};