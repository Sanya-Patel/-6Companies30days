/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void Make_AdjList(TreeNode* root, TreeNode* parent,
                      map<int, vector<int>>& AdjList) {
        if (root == NULL) {
            return;
        }

        if (parent) {
            AdjList[root->val].push_back(parent->val);
        }
        if (root->left) {
            AdjList[root->val].push_back(root->left->val);
            Make_AdjList(root->left, root, AdjList);
        }
        if (root->right) {
            AdjList[root->val].push_back(root->right->val);
            Make_AdjList(root->right, root, AdjList);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        map<int, vector<int>> AdjList;
        TreeNode* Parent = root;
        Make_AdjList(root, Parent, AdjList);
        map<int, bool> visited;
        visited[start] = true;
        int time = 0;
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int size = q.size();
            while (size > 0) {
                int x = q.front();
                q.pop();
                size--;
                for (auto Nbr : AdjList[x]) {
                    if (!visited[Nbr]) {
                        q.push(Nbr);
                        visited[Nbr] = true;
                    }
                }
            }
            time += 1;
        }
        return time - 1;
    }
};