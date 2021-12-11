/**
 * Possible solution to https://leetcode.com/problems/validate-binary-search-tree
 * Marvin Manese
 **/

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
    bool isValidBST(TreeNode* root)
    {
        if(!root)
            return true;

        // Check the root value
        int64_t root_val = static_cast<int64_t>(root->val);
        if(!checkLeftChild(root->left, root_val, INT64_MIN) || !checkRightChild(root->right, root_val, INT64_MAX))
           return false;

        bool rst = true;
        treeTraverse(root->left, INT64_MIN, root_val, rst);
        treeTraverse(root->right, root_val, INT64_MAX, rst);

        return rst;
    }

    void treeTraverse(TreeNode* node, int64_t min, int64_t max, bool& rst)
    {
        if(node == NULL)
            return;

        int64_t node_val = static_cast<int64_t>(node->val);
        if(!checkLeftChild(node->left, node_val, min) || !checkRightChild(node->right, node_val, max)) {
            rst = false;
            return;
        }

        treeTraverse(node->left, min, node_val, rst);
        treeTraverse(node->right, node_val, max, rst);
    }

private:
    bool checkLeftChild(TreeNode* node_left, int64_t node_val, int64_t min)
    {
        if(node_left) {
            int64_t left_val = static_cast<int64_t>(node_left->val);
            if(left_val >= node_val || left_val <= min) {
                return false;
            }
        }
        return true;
    }

    bool checkRightChild(TreeNode* node_right, int64_t node_val, int64_t max)
    {
        if(node_right) {
            int64_t right_val = static_cast<int64_t>(node_right->val);
            if(right_val <= node_val || right_val >= max) {
                return false;
            }
        }
        return true;
    }
};
