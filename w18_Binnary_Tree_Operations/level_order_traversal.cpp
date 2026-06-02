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

void level_order(Bnode* root) {
    if(!root) {
        cout << "No Treee" << endl;
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
    Bnode* root = new Bnode(10);
    Bnode* a = new Bnode(20);
    Bnode* b = new Bnode(30);
    Bnode* c = new Bnode(40);
    Bnode* d = new Bnode(50);
    Bnode* e = new Bnode(60);

    // Connections
    root->left = a;
    root->right = b;
    a->left = c;
    b->left = d;
    b->right = e;

    level_order(root);
    
    return 0;
}
