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
    unordered_map<int, int> freq;
    int maxfreq = 1;
    int solve(TreeNode* root){
        if(!root) return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        int sum = left + right + root->val;
        freq[sum]++;
        if(freq[sum] > maxfreq) maxfreq = freq[sum];
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(!root) return {};
        vector<int>ans;
        solve(root);
        for(auto it : freq){
            if(it.second == maxfreq){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};