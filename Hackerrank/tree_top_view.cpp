#include <iostream>
#include <map>
#include <queue>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void topView(Node* root) {
    if (!root) return;
    queue<pair<Node*, int>> q;
    map<int, int> mp;
    q.push({ root, 0 });
    while (q.size()) {
        auto temp = q.front();
        q.pop();
        int horizontal_distance = temp.second;
        Node* node = temp.first;
        if (!mp[horizontal_distance]) {
            mp[horizontal_distance] = node->data;
        }
        if (node->left) {
            q.push({ node->left, horizontal_distance - 1 });
        }
        if (node->right) {
            q.push({ node->right, horizontal_distance + 1 });
        }
    }
    for (auto node : mp) {
        cout << node.second << ' ';
    }
}