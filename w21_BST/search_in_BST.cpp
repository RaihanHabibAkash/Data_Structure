#include <bits/stdc++.h>
using namespace std;

class Bnode {
public:
    int val;
    Bnode* left;
    Bnode* right;
    
    Bnode(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

Bnode* input_tree() {
    int val; cin >> val;
    Bnode* root;
    if(val == -1) {
        root = NULL;
        return root;
    }
    else root = new Bnode(val);

    queue<Bnode*> q;
    q.push(root);

    while(!q.empty()) {
    // 1. queue theke node ber kora
        Bnode* node = q.front();
        q.pop();
    // 2. oi node nia kaj
        int l, r; cin >> l >> r;
        Bnode* myLeft, *myRight;

        // Creating new node
        if(l == -1) myLeft = NULL;
        else myLeft = new Bnode(l);
        if(r == -1) myRight = NULL;
        else myRight = new Bnode(r);

        // Connectin parent node with child
        node->left = myLeft;
        node->right = myRight;

    // 3. queue te node ar children push thakle
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }

    return root;
}

bool search(Bnode* root, int val) {
    // Base case
    if(!root) return false;

    if(root->val == val) return true;
    else if(root->val < val) return search(root->right, val);
    else return search(root->left, val);
}

int main() {
    Bnode* root = input_tree();
    int val; cin >> val;
    cout << (search(root, val) ? "YES" : "NO") << endl;

    return 0;
}
