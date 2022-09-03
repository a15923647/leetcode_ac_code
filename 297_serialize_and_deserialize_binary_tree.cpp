/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      stringstream ss;
      preorder_s(root, ss);
      return ss.str();
    }
    
    void preorder_s(TreeNode *parent, stringstream& ss) {
      if (!parent) {
        ss << "# ";
        return;
      }
      ss << to_string(parent->val) + ' ';
      preorder_s(parent->left, ss);
      preorder_s(parent->right, ss);
    }
    
    void preorder_d(TreeNode **loc, stringstream& ss) {
      string val;
      ss >> val;
      if (val == "#") return;
      *loc = new TreeNode(stoi(val));
      preorder_d(&((*loc)->left), ss);
      preorder_d(&((*loc)->right), ss);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
      stringstream ss(data);
      TreeNode *root = NULL;
      preorder_d(&root, ss);
      return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));