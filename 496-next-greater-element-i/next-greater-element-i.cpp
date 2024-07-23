class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next;
        stack<int> s;
        for (int num : nums2) {
            while (!s.empty() && s.top() < num) {
                next[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
        for (int& num : nums1) 
        num = next.count(num) ? next[num] : -1;
        return nums1;
    }
};