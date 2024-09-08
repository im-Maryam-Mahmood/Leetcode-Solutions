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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int totalNodes = 0;
        ListNode* current = head;
        while (current) {
            totalNodes++;
            current = current->next;
        }
        int partSize = totalNodes / k;
        int extraNodes = totalNodes % k;
        vector<ListNode*> result(k, nullptr);
        current = head;
        for (int i = 0; i < k && current; ++i) {
            result[i] = current;
            int currentPartSize = partSize + (i < extraNodes ? 1 : 0);
            for (int j = 1; j < currentPartSize; ++j) {
                current = current->next;
            }
            ListNode* nextPart = current->next;
            current->next = nullptr;
            current = nextPart;
        }
        return result;
    }
};