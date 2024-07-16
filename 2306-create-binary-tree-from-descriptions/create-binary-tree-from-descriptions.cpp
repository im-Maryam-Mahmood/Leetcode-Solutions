class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;
        for (const auto& desc : descriptions) {
            int parent = desc[0], child = desc[1], isLeft = desc[2];
            
            if (nodes.find(parent) == nodes.end())
                nodes[parent] = new TreeNode(parent);
            if (nodes.find(child) == nodes.end())
                nodes[child] = new TreeNode(child);
            
            if (isLeft) nodes[parent]->left = nodes[child];
            else nodes[parent]->right = nodes[child];
            children.insert(child);
        }
        TreeNode* root = nullptr;
        for (const auto& desc : descriptions) {
            if (children.find(desc[0]) == children.end()) {
                root = nodes[desc[0]];
                break;
            }
        }
        
        return root;
    }
};

void printTree(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}