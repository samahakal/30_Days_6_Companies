// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/description/

class Solution {
public:
    int ans = 0;
    pair<int,int> solve(TreeNode* root){
        if(root == NULL) return {0,0};
        
        auto call_1 = solve(root->left);
        auto call_2 = solve(root->right);

        int sum = call_1.second + call_2.second + root->val;
        int k = call_1.first + call_2.first + 1;
        
        if(sum/k == root->val) ans++;

        return {k,sum};

    }
    
    int averageOfSubtree(TreeNode* root) {
        auto temp = solve(root);
        return ans;
    }
};
