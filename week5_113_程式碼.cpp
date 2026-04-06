class Solution {
public:

       vector<vector<int>> result;
       vector<int> path;

       void dfs(TreeNode*root , int target){
        if(!root) return;

        path.push_back(root->val);
        target = target - root->val;

        if(!root->left && !root->right && target==0){
            result.push_back(path);
        }

        dfs(root->left, target);
        dfs(root->right, target);

        path.pop_back();

       }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return result;
    }
};