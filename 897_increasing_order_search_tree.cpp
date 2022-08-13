class Solution {
  public:
    TreeNode* increasingBST(TreeNode* root) {
      ans = tail = new TreeNode(0);
      traversal(root);
      return ans->right;
    }
    void traversal(TreeNode* cur) {
      if (cur->left != nullptr) traversal(cur->left);
      TreeNode* new_p = new TreeNode(cur->val);
      tail = tail->right = new_p;
      if (cur->right != nullptr) traversal(cur->right);
    }
    TreeNode* ans;
    TreeNode* tail;
};