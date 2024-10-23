// https://leetcode.com/problems/cousins-in-binary-tree-ii/description/
// 2641 - Cousins in Binary Tree II

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

    void sum_by_level (int level, TreeNode* node, vector<int>& sum){
        if(node==nullptr)
            return;

        if(sum.size()<=level)
            sum.push_back(node->val);
        else sum[level]+=(node->val);

        sum_by_level(level+1, node->left, sum);
        sum_by_level(level+1, node->right, sum);
    }

    void att_by_level (int level, int brother, TreeNode* node, vector<int>& sum){
        if(node==nullptr)
            return;
        
        node->val = sum[level] - node->val - brother;

        int left = node->left== nullptr? 0 : node->left->val;
        int right = node->right== nullptr? 0 : node->right->val;

        att_by_level(level+1, left, node->right, sum);
        att_by_level(level+1, right, node->left, sum);
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> sum(1);
        sum_by_level(1,root,sum);

        att_by_level(1,0,root,sum);

        return root;
    }
};
