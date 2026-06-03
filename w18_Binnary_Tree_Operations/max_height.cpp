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

    // If the values is -1 don't create root & set root to NULL
    if(val == -1) root = NULL;
    else root = new Bnode(val);

    // Queue of nodes
    queue<Bnode*> q;

    // If root is not NULL push it into queue
    if(root) q.push(root);

    while(!q.empty()) {
    // 1. Ber kore ana from queue
        Bnode* p = q.front();
        q.pop();

    // 2. Oi node dia kaj
        int l, r; cin >> l >> r;
        Bnode* myLeft, *myRight;

        // Creating nodes if the value is not -1, If -1 set pointer to NULL
        if(l == -1) myLeft = NULL;
        else myLeft = new Bnode(l);
        if(r == -1) myRight = NULL;
        else myRight = new Bnode(r);

        // Connecting current node with new 2 nodes
        p->left = myLeft;
        p->right = myRight;

    // 3. Node ar childen push in queue (thakle)
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }

    return root;
}

int max_height(Bnode* root) {
    // Base case
    if(!root) return 0;
    // The lead node height is 0
    if(!root->left && !root->right) return 0;
    
    int l = max_height(root->left);
    int r = max_height(root->right);

    return max(l, r) + 1;
}

int main() {
    // Taking input
    Bnode* root = input_tree();

    cout << max_height(root) << endl;

    return 0;
}
