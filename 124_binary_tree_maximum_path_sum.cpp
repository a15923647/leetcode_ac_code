/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*
If a node is in path, it has two situations.
1. on left - parent - right
2. on child - parent - ascendent
*/
class Solution {
  public:
    int maxPathSum(TreeNode* root) {
      ans = -0x7fffffff;
      dfs(root);
      return ans;
    }
    int dfs(TreeNode* parent) {
      int cur_val = parent->val, left_best = 0, right_best = 0;
      if (parent->left) left_best = max(0, dfs(parent->left));
      if (parent->right) right_best = max(0, dfs(parent->right));
      //left - parent - right
      ans = max(ans, cur_val + left_best + right_best);
      //child - parent - ascendent
      //can only select one branch
      return cur_val + max(left_best, right_best);
    }
    int ans;
};