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
    if(val == -1){
        root = NULL;
        return root;
    }
    else root = new Bnode(val);

    queue<Bnode*> q;
    q.push(root);

    while(!q.empty()) {
    // 1. queue theke oi node ber kore ana
        Bnode* node = q.front();
        q.pop();

    // 2. oi node nia kaj
        int l, r; cin >> l >> r;
        Bnode* myLeft, *myRight;

        // Creating node
        if(l == -1) myLeft = NULL;
        else myLeft =  new Bnode(l);
        if(r == -1) myRight = NULL;
        else myRight = new Bnode(r);

        // Connection
        node->left = myLeft;
        node->right = myRight;

    // 3. oi node ar children push int the queue thakle
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
    return root;
}

void level_order_print(Bnode* root) {
    if(!root) {
        cout << "NO Tree" << endl;
        return;
    }
    queue<Bnode*> q;
    q.push(root);

    while(!q.empty()) {
    // 1. queue theke node ber kore ana
        Bnode* node = q.front();
        q.pop();

    // 2. oi node nia kaj
        cout << node->val << " ";

    // 3. oi node ar children push in the queue
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
}

void insert_BST(Bnode* &root, int val) {
    // Base case
    if(!root) {
        root = new Bnode(val);
        return;
    }

    if(root->val > val) insert_BST(root->left, val);
    else insert_BST(root->right, val);
}

int main() {
    // Taking input
    Bnode* root = input_tree();

    // Taking new val input
    insert_BST(root, 11);

    // Printing
    level_order_print(root);

    return 0;
}
