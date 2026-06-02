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
    // Creating an root pointer and taking first input
    int val; cin >> val;
    Bnode* root;

    // If the input value is -1 root is set to NULL, other wise root will point new node
    if(val == -1) root = NULL;
    else root = new Bnode(val);

    // Queue of nodes
    queue<Bnode*> q;
    // If the root is not null pushing it
    if(root) q.push(root);

    while(!q.empty()) {
    // 1. Ber kore ana from queue
        Bnode* p = q.front();
        q.pop();

    // 2. Oi node nia kaj kora
        // Taking new inputs
        int l, r; cin >> l >> r;
        // Creating empty pointer
        Bnode* myLeft, *myRight;

        // If the input value is -1 set null, other wise create new child node 
        if(l == -1) myLeft = NULL;
        else myLeft = new Bnode(l);
        if(r == -1) myRight = NULL;
        else myRight = new Bnode(r);

        // Connection
        p->left = myLeft;
        p->right = myRight;

    // 3. Set children to queue
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }

    // Returing the root
    return root;
}

void level_order(Bnode* root) {
    if(!root) {
        cout << "No Tree" << endl;
        return;
    }

    queue<Bnode*> q;
    q.push(root);

    while(!q.empty()) {
        // 1. Ber kore nia asha queue theke
        Bnode* f = q.front();
        q.pop();

        // 2. Node dia kaj kora
        cout << f->val << " ";

        // 3. Node ar children push kora (thakle)
        if(f->left) q.push(f->left);
        if(f->right) q.push(f->right);
    }
}

int main() {
    Bnode* root = input_tree();

    // Printing
    level_order(root);

    return 0;
}
