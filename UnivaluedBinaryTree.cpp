// Faster than 100%, Uses less memory than 100%

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isUnivalTree(TreeNode* root) 
    {
      int val = -1;
      
      stack<TreeNode*> nodes;
      val = root->val;
      if(root->left)
        nodes.push(root->left);
      if(root->right)
        nodes.push(root->right);
      
      while(!nodes.empty()) {
        auto* node = nodes.top();
        nodes.pop();
        
        if(node->val != val)
          return false;
        
        if(node->left)
          nodes.push(node->left);
        if(node->right)
          nodes.push(node->right);
      }
      
      return true;
    }
}; 
