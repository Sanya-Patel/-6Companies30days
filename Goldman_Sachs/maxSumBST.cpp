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
class Info{
public:
    int sum;
    int max;
    int min;
    
    Info(int x,int y,int z)
    {
        sum=x;
        max=y;
        min=z;
    }
};
class Solution {
public:
    int ans=0;
    Info* helper(TreeNode *root)
    {
        if(root==NULL)
            return new Info(0,INT_MIN,INT_MAX);
        Info* left=helper(root->left);
        Info* right=helper(root->right);

        if(left->max < root->val && root->val < right->min)
        {
            int s=left->sum+right->sum+root->val;
            int ma=max(root->val,right->max);
            int mi=min(root->val,left->min);
            ans=max(ans,s);
            return new Info(s,ma,mi);
        }
        else
        {
            int s=max(left->sum,right->sum);
            int ma=INT_MAX;
            int mi=INT_MIN;
            return new Info(s,ma,mi);
        }
    }
    int maxSumBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};