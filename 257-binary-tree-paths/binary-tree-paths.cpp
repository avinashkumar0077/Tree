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
    
    void solve(TreeNode* root, string path, vector<string>& ans) {
        
        // Base case
        if(root == NULL)
            return;

        // Add current node value to path
        path += to_string(root->val);

        // If leaf node, store path
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(path);
            return;
        }

        // Add arrow before going to children
        path += "->";

        // Traverse left subtree
        solve(root->left, path, ans);

        // Traverse right subtree
        solve(root->right, path, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> ans;
        string path = "";

        solve(root, path, ans);

        return ans;
    }
};