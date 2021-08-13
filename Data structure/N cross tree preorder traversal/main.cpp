#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<int> vec;

    vector<int> preorder(Node *root) {
        if (root == NULL) return vec;
        stack<Node *> sta;
        Node *tmp;
        sta.push(root);
        while (!sta.empty()) {
            tmp = sta.top();
            sta.pop();
            vec.push_back(tmp->val);
            for (int i = tmp->children.size() - 1; i >= 0; i--) {
                sta.push(tmp->children[i]);
            }
        }
        return vec;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
