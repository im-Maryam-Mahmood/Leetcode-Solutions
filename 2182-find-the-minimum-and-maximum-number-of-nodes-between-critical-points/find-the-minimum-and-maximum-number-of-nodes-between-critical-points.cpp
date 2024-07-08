/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    if (!head || !head->next || !head->next->next) return {-1, -1};
    vector<int> criticalPoints;
    int index = 1;
    ListNode* prev = head;
    ListNode* curr = head->next;
    ListNode* next = curr->next;
    while (next) {
        if ((curr->val > prev->val && curr->val > next->val) ||
            (curr->val < prev->val && curr->val < next->val)) {
            criticalPoints.push_back(index);
        }
        prev = curr;
        curr = next;
        next = next->next;
        ++index;
    }
    if (criticalPoints.size() < 2) return {-1, -1};
    int minDistance = INT_MAX;
    int maxDistance = criticalPoints.back() - criticalPoints.front();
    for (size_t i = 1; i < criticalPoints.size(); ++i) {
        minDistance = min(minDistance, criticalPoints[i] - criticalPoints[i - 1]);
    }

    return {minDistance, maxDistance};
    }
};