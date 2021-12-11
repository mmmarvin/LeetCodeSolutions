/**
 * Solution to: https://leetcode.com/problems/average-of-levels-in-binary-tree/submissions/
 * Faster than 100% Uses less memory than 100%
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
#include <vector>
#include <queue>

class Solution
{
public:
    vector<double> averageOfLevels(TreeNode* root)
    {
        vector<double> ret;
        queue<TreeNode*> node_queue;

        if(root)
            node_queue.push(root);

        int na = 1;         // Number of nodes added on level
        int ni = 0;         // Node index
        int tna = 0;        // Temporary number of nodes added

        double aval = 0;    // Average value per level
        while(!node_queue.empty()) {
            TreeNode* node = node_queue.front();
            node_queue.pop();

            if(node->left) {
                node_queue.push(node->left);
                ++tna;
            } if(node->right) {
                node_queue.push(node->right);
                ++tna;
            }
            aval += node->val;

            if(++ni == na) {
                double avg = aval / static_cast<double>(na);
                ret.push_back(avg);

                aval = 0;
                na = tna;
                ni = tna = 0;
            }
        }

        return ret;
    }
};
