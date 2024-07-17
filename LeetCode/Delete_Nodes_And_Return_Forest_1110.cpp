// https://leetcode.com/problems/delete-nodes-and-return-forest/description
// 1110 - Delete Nodes And Return Forest

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
    vector<TreeNode*> ans;
    void del (TreeNode* node, unordered_map<int,int>& hash, queue<TreeNode*>& fila){
        if(node->right!=NULL){
            if(hash[node->right->val])
                del(node->right, hash, fila);
            else {
                ans.push_back(node->right);
                fila.push(node->right);
            } 
        }
        if(node->left!=NULL){
            if(hash[node->left->val])
                del(node->left, hash, fila);
            else {
                ans.push_back(node->left);
                fila.push(node->left);
            } 
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int,int> hash;
        for(auto i : to_delete)
            hash[i]=1;
        queue<TreeNode*> fila;
        fila.push(root);
        if(!hash[root->val])
            ans.push_back(root);

        if(root->right!=NULL)
            if(hash[root->right->val]){
                fila.push(root->right);
                root->right=NULL;
            }
        if(root->left!=NULL)
            if(hash[root->left->val]){
                fila.push(root->left);
                root->left=NULL;
            }

        while(!fila.empty()){
            TreeNode* node = fila.front();
            fila.pop();
            if(hash[node->val])
                del(node,hash,fila);
            else{
                if(node->right != NULL){
                    fila.push(node->right);
                    if(hash[node->right->val])
                        node->right=NULL;
                }
                if(node->left != NULL){
                    fila.push(node->left);
                    if(hash[node->left->val])
                        node->left=NULL;
                }
            }
        }
        return ans;
    }
};
