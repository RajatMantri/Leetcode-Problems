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
    int depth=0;
    void f(TreeNode*root,int d){
        if(!root) return;
        if(!root->left&&!root->right){
            depth=max(d,depth);
            return;
        }

        f(root->right,d+1);
        f(root->left,d+1);
    }
    TreeNode* ff(TreeNode*root,int d){
        if(!root||(!root->left&&!root->right)){
            if(depth==d) return root;
            else return NULL;
        }

        TreeNode*l=ff(root->left,d+1);
        TreeNode*r=ff(root->right,d+1);

        if(l&&r){
            return root;
        }

        if(l) return l;
        return r;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        f(root,0);
        return ff(root,0);
    }
};