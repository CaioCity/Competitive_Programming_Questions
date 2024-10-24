// https://leetcode.com/problems/flip-equivalent-binary-trees/
// 951 - Flip Equivalent Binary Trees

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
class Solution {
public:
    void level_by_level(int& number, TreeNode* node, vector<int>& tree){
        if(node == nullptr)
            return;

        ++number;

        if(node->left != nullptr){
            tree[node->left->val] = node->val;
            level_by_level(number,node->left,tree);
        }
        if(node->right != nullptr){
            tree[node->right->val] = node->val;
            level_by_level(number,node->right,tree);
        }
    }

    bool flipEquiv(TreeNode* node1, TreeNode* node2) {
        int n1 = 0, n2 = 0;
        vector<int> tree1(101,-1), tree2(101,-1);

        level_by_level(n1,node1,tree1);
        level_by_level(n2,node2,tree2);

        return (n1==n2 && tree1==tree2)? 1 : 0;
    }
};
