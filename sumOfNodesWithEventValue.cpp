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
    int sumAllChild(TreeNode* parent)
    {
      int sum = 0;
      if(parent->left)
        sum += parent->left->val;
      if(parent->right)
        sum += parent->right->val;
      
      return sum;
    }
  
    int sumEvenGrandparent(TreeNode* root) 
    {
      queue<TreeNode*> nodes;
      nodes.push(root);
      
      int count = 0;
      while(!nodes.empty()) {
        auto* node = nodes.front();
        nodes.pop();
        
        if(node->val % 2 == 0) {
          if(node->left) {
            count += sumAllChild(node->left);
            nodes.push(node->left);
          }
          if(node->right) {
            count += sumAllChild(node->right);
            nodes.push(node->right);
          }
          
          continue;
        }
        
        if(node->left)
          nodes.push(node->left);
        if(node->right)
          nodes.push(node->right);
      }
      
      return count;
    }
};