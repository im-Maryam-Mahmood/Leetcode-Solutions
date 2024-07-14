class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> stk;
        map<string, int> count;
        int n = formula.size();

        for (int i = 0; i < n;) {
            if (formula[i] == '(') {
                stk.push(count);
                count.clear();
                i++;
            } else if (formula[i] == ')') {
                map<string, int> temp = count;
                count = stk.top(); stk.pop();
                int iStart = ++i, multiplicity = 1;
                while (i < n && isdigit(formula[i])) i++;
                if (i > iStart) multiplicity = stoi(formula.substr(iStart, i - iStart));
                for (auto &p : temp) count[p.first] += p.second * multiplicity;
            } else {
                int iStart = i++;
                while (i < n && islower(formula[i])) i++;
                string name = formula.substr(iStart, i - iStart);
                iStart = i;
                while (i < n && isdigit(formula[i])) i++;
                int multiplicity = i > iStart ? stoi(formula.substr(iStart, i - iStart)) : 1;
                count[name] += multiplicity;
            }
        }

        string result;
        for (auto &p : count) result += p.first + (p.second == 1 ? "" : to_string(p.second));
        return result;
    }
};