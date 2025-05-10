#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 1; i <= size; i++) {
                TreeNode* top = q.front();
                q.pop();

                if (i == size) { 
                    ans.push_back(top->val);
                }

                if (top->left) {
                    q.push(top->left);
                }

                if (top->right) {
                    q.push(top->right);
                }
            }
        }

        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution sol;
    vector<int> result = sol.rightSideView(root);

    cout << "Right side view of the binary tree: ";
    for (int num : result) {
        cout << num << " ";
    }
    
    return 0;
}