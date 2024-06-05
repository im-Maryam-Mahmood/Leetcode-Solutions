class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int cnt[26] = {0};
        for (char c : words[0]) cnt[c - 'a']++;
        for (int i = 1; i < words.size(); ++i) {
            int temp[26] = {0};
            for (char c : words[i]) temp[c - 'a']++;
            for (int j = 0; j < 26; ++j) cnt[j] = min(cnt[j], temp[j]);
        }
        vector<string> res;
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < cnt[i]; ++j)
                res.push_back(string(1, 'a' + i));
        return res;
    }
};