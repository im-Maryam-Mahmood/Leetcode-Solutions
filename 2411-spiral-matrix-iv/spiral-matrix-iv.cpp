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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        ListNode* curr = head;
        
        while (top <= bottom && left <= right && curr) {
            for (int j = left; j <= right && curr; ++j) 
            matrix[top][j] = curr->val, curr = curr->next;
            top++;
            for (int i = top; i <= bottom && curr; ++i) 
            matrix[i][right] = curr->val, curr = curr->next;
            right--;
            for (int j = right; j >= left && curr; --j) 
            matrix[bottom][j] = curr->val, curr = curr->next;
            bottom--;
            for (int i = bottom; i >= top && curr; --i)
            matrix[i][left] = curr->val, curr = curr->next;
            left++;
        }
        
        return matrix;
    }
};