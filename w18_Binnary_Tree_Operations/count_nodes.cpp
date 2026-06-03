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

    // If the value is -1 don't create an node
    if(val == -1) root = NULL;
    else root = new Bnode(val);

    // Queue of nodes
    queue<Bnode*> q;

    // If the root is not NULL push it into the queue
    if(root) q.push(root);

    while(!q.empty()) {
    // 1. Ber kore ana from queue
        Bnode* p = q.front();
        q.pop();

    // 2. Oi node nia kaj kora
        int l, r; cin >> l >> r;
        Bnode* myLeft, *myRight;

        // Creating new node, if -1 that placing NULL
        if(l == -1) myLeft = NULL;
        else myLeft = new Bnode(l);
        if(r == -1) myRight = NULL;
        else myRight = new Bnode(r);

        // Connecting nodes
        p->left = myLeft;
        p->right = myRight;

    // 3. Node ar children queue te push kora thakle
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }

    return root;
}

int count_nodes(Bnode* root) {
    // Base case
    if(!root) return 0;

    int l = count_nodes(root->left);
    int r = count_nodes(root->right);
    return 1+l+r;
}

int main() {
    // Taking input
    Bnode* root = input_tree();

    // Printing the count of nodes
    cout << count_nodes(root) << endl;

    return 0;
}
