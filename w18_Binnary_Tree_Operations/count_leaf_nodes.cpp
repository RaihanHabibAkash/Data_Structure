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

    // If value is -1 put the pointer to null other wise create an root element
    if(val == -1) root = NULL;
    else root = new Bnode(val);

    // Queue of nodes
    queue<Bnode*> q;
    if(root)q.push(root);

    while(!q.empty()) {
    // 1. node ber kore ana from queue
        Bnode* p = q.front();
        q.pop();

    // 2. node dia kaj kora
        int l, r; cin >> l >> r;
        Bnode* myLeft, *myRight;

        // If the input value is -1 put it to null, other wise create new node
        if(l == -1) myLeft = NULL;
        else myLeft = new Bnode(l);
        if(r == -1) myRight = NULL;
        else myRight = new Bnode(r);

        // Connecting children with current node
        p->left = myLeft;
        p->right = myRight;

    // 3. node ar children queue te push kora
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }

    return root;
}

int count_Leaf_Nodes(Bnode* root) {
    // Base case
    if(!root) return 0; // root is in null
    if(!root->left && !root->right) return 1; // root left & right is null

    int l = count_Leaf_Nodes(root->left);
    int r = count_Leaf_Nodes(root->right);
    return l+r;
}


int main() {
    // Taking input
    Bnode* root = input_tree();
    
    cout << count_Leaf_Nodes(root);
    
    return 0;
}
