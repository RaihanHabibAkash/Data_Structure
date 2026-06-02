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

void postOrder(Bnode* root) {
    // Base case
    if(root == NULL) return;

    postOrder(root->left); // left
    postOrder(root->right); // right
    cout << root->val << " ";
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

    postOrder(root);

    return 0;
}
