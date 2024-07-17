class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;
        root = deleteNodes(root, toDeleteSet, forest);
        if (root) forest.push_back(root);
        return forest;
    }
    TreeNode* deleteNodes(TreeNode* node, unordered_set<int>& toDeleteSet, vector<TreeNode*>& forest) {
        if (!node) return nullptr;
        node->left = deleteNodes(node->left, toDeleteSet, forest);
        node->right = deleteNodes(node->right, toDeleteSet, forest);
        if (toDeleteSet.count(node->val)) {
            if (node->left) forest.push_back(node->left);
            if (node->right) forest.push_back(node->right);
            delete node;
            return nullptr;
        }
        return node;
    }
};
