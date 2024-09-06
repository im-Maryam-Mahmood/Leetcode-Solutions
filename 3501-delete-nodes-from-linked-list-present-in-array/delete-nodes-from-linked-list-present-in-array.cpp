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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(0); 
        dummy->next = head;
        ListNode* current = dummy;
        while (current->next) {
            if (numSet.count(current->next->val)) {
                current->next = current->next->next;
            } else current = current->next;
        }
        return dummy->next;
    }
};