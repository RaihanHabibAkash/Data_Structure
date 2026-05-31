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

void preOrder(Bnode* root) {
    // Base case
    if(root == NULL) return;

    cout << root->val << " "; // root

    preOrder(root->left); // left
    preOrder(root->right); // right
}

int main() {
    Bnode* root = new Bnode(10);
    Bnode* a = new Bnode(20);
    Bnode* b = new Bnode(30);
    Bnode* c = new Bnode(40);
    Bnode* d = new Bnode(50);
    Bnode* e = new Bnode(60);

    // Connections of binnary tree
    root->left = a;
    root->right = b;
    a->left = c;
    b->left = d;
    b->right = e;

    preOrder(root);
    
    return 0;
}
