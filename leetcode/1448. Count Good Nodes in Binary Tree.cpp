int ans=0;
class Solution {
public:
        int solve(TreeNode* root,int hi){
        if (root){
            int k=solve(root->left, max(hi,root->val)) + solve(root->right, max(hi,root->val));
            if (root->val>=hi){
                k++;
            }
            return k;
        }
        return 0;
    }
    int goodNodes(TreeNode* root) {
        return solve(root,-10001);
    }
};
