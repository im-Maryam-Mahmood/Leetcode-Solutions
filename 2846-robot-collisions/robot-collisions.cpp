class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<pair<int, int>> robots(n);
        for (int i = 0; i < n; ++i) robots[i] = {positions[i], i};
        sort(robots.begin(), robots.end());
        stack<int> st;
        for (const auto& robot : robots) {
            int idx = robot.second;
            if (directions[idx] == 'R') st.push(idx);
            else {
                while (!st.empty() && healths[idx] > 0) {
                    int top = st.top();
                    if (healths[top] > healths[idx]) {
                        healths[top]--;
                        healths[idx] = 0;
                    } else if (healths[top] == healths[idx]) {
                        healths[top] = 0;
                        healths[idx] = 0;
                        st.pop();
                    } else {
                        healths[idx]--;
                        healths[top] = 0;
                        st.pop();
                    }
                }
            }
        }
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (healths[i] > 0) result.push_back(healths[i]);
        }

        return result;
    }
};
