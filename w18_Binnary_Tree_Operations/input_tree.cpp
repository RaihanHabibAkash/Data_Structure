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

    // If the val is -1 don't creating node
    if(val == -1) root = NULL;
    else root = new Bnode(val);

    // Queue of Nodes, to maintain the order
    queue<Bnode*> q;

    // If root is not NULL than pushing it into queue
    if(root) q.push(root);

    while(!q.empty()) {
    // 1. Ber kore nia ana from queue
        Bnode* p = q.front();
        q.pop();
    
    // 2. Oi node nia kaj kora
        int l, r; cin >> l >> r;
        // Creating empty pointer
        Bnode* myLeft, *myRight;

        // If the input is -1 placing pointer to NULL, other wise creating new node
        if(l == -1) myLeft = NULL;
        else myLeft = new Bnode(l);
        if(r == -1) myRight = NULL;
        else myRight = new Bnode(r);

        // Connecting with current node
        p->left = myLeft;
        p->right = myRight;

    // 3. Children thakle queue te push
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }

    // Returing the root
    return root;
}

void level_order_printing(Bnode* root) {
    if(!root) {
        cout << "No Tree" << endl;
        return;
    }
    queue<Bnode*> q;
    q.push(root);
    
    while(!q.empty()) {
    // 1. Ber kore nia ahsa
        Bnode* f = q.front();
        q.pop();
    
    // 2. Oi node nia kaj
        cout << f->val << " ";
    
    // 3. Oi node ar children push in queue
        if(f->left) q.push(f->left);
        if(f->right) q.push(f->right);
    }
}

int main() {
    // Taking input
    Bnode* root = input_tree();
    // Printing
    level_order_printing(root);

    return 0;
}