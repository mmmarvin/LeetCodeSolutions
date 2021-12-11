/**
 * Possible solution to https://leetcode.com/problems/path-sum
 * Marvin Manese
 **/
#include <vector>

class Solution
{
public:
    bool hasPathSum(TreeNode* root, int sum)
    {
        // Basic error checking first
        if(root == NULL)
            return false;

        // Array of nodes and sums
        std::vector<TreeNode*>  tree_nodes;
        std::vector<int>        node_sums;
        std::vector<TreeNode*>  temporary_tree_nodes;
        std::vector<int>        temporary_node_sums;

        // Reserve enough
        tree_nodes.reserve(100);
        temporary_tree_nodes.reserve(100);
        node_sums.reserve(100);
        temporary_node_sums.reserve(100);

        // First, we insert the root node to the tree node array
        // and add the sum to the node array
        tree_nodes.push_back(root);
        node_sums.push_back(root->val);

        while(!tree_nodes.empty()) {
            for(std::size_t i = 0; i < tree_nodes.size(); ++i) {
                // We can assume that tree_nodes.size() == node_sums.size()
                TreeNode* current_node = tree_nodes[i];
                int current_sum = node_sums[i];

                // Grab the branches
                TreeNode* branch_node_left = current_node->left;
                TreeNode* branch_node_right = current_node->right;

                // Check if the current sum is good enough
                if(current_sum == sum && branch_node_left == NULL && branch_node_right == NULL)
                    return true;

                // Check if the left child is valid
                if(branch_node_left != NULL) {
                    // Calculate the current sum
                    int sum_of_node = branch_node_left->val + current_sum;
                    if(sum_of_node == sum && branch_node_left->left == NULL && branch_node_left->right == NULL) {
                        return true;
                    }

                    // If valid, add it to temporary tree nodes array
                    temporary_tree_nodes.push_back(branch_node_left);
                    // And add the sum to the temporar node sums array
                    temporary_node_sums.push_back(sum_of_node);
                }

                // Check if the right child is valid
                if(branch_node_right != NULL) {
                    // Calculate the current sum
                    int sum_of_node = branch_node_right->val + current_sum;

                    // Temporary node
                    if(sum_of_node == sum && branch_node_right->left == NULL && branch_node_right->right == NULL) {
                        return true;
                    }

                    // If valid, add it to temporary tree nodes array
                    temporary_tree_nodes.push_back(branch_node_right);
                    // And add the sum to the temporar node sums array
                    temporary_node_sums.push_back(sum_of_node);
                }
            }

            // Copy the temporary_tree_nodes and temporary_node_sums to the
            // original
            tree_nodes = temporary_tree_nodes;
            node_sums = temporary_node_sums;

            // Clear the temporaries
            temporary_tree_nodes.clear();
            temporary_node_sums.clear();
        }

        return false;
    }
};
