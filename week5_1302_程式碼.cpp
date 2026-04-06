class Solution {
public:

    int Maxdeep = 0;
    int sum = 0;

    void dfs(TreeNode*root, int deep){
    if(!root) return;

    if (deep > Maxdeep){
        Maxdeep = deep;
        sum = root->val;
    }  else if (deep == Maxdeep){
        sum = sum + root->val; 
    } 

    dfs(root->left, deep+1);
    dfs(root->right, deep+1);

    }

    int deepestLeavesSum(TreeNode* root) {
        dfs(root,1);
        return sum;
    }
};