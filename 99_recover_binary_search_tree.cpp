class Solution {
  public:
    void recoverTree(TreeNode* root) {
      prev = new TreeNode(INT_MIN);
      first = second = nullptr;
      inorder(root);
      swap(first->val, second->val);
    }
    
    void inorder(TreeNode* cur) {
      if (cur->left != nullptr) inorder(cur->left);
      if (first == nullptr && cur->val < prev->val) first = prev;
      if (first != nullptr && cur->val < prev->val) second = cur;
      prev = cur;
      if (cur->right != nullptr) inorder(cur->right);
    }
    TreeNode *prev, *first, *second;
};