// https://leetcode.com/problems/house-robber-iii/description/

class Solution {
public:
    unordered_map<TreeNode*,int>mp;

    int rob(TreeNode* root) {
        if(root == NULL) return 0;

        int ans1 = root->val;
        int ans2 = 0;

        if(mp.count(root)) return mp[root];

        if(root->left){
            ans1 += rob(root->left->left) + rob(root->left->right);
            ans2 += rob(root->left);
        }

        if(root->right){
            ans1 += rob(root->right->left) + rob(root->right->right);
            ans2 += rob(root->right);
        }
        
        return mp[root] = max(ans1,ans2);
    }
};
