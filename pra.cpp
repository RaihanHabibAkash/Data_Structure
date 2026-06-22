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

    root = new Bnode(val);
    queue<Bnode*> q;
    q.push(root);

    while(!q.empty()) {
        Bnode* node = q.front();
        q.pop();

        int l, r; cin >> l >> r;
        Bnode* myLeft, *myRight;
        if(l == -1) myLeft = NULL;
        else myLeft = new Bnode(l);
        if(r == -1) myRight = NULL;
        else myRight = new Bnode(r);

        node->left = myLeft;
        node->right = myRight;

        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
    return root;
}

void leftSide(Bnode* root, vector<int>& v) {
    if(!root) return;

    if(root->left) leftSide(root->left, v);
    else leftSide(root->right, v);
    v.push_back(root->val);
}

void rightSide(Bnode* root, vector<int>& v) {
    if(!root) return;

    v.push_back(root->val);
    if(root->right) rightSide(root->right, v);
    else rightSide(root->left, v);
}

int main() {
    Bnode* root = input_tree();

    vector<int> v;

    leftSide(root->left, v);
    v.push_back(root->val);
    rightSide(root->right, v);
    
    for(int x : v) cout << x << " ";
    cout << endl;

    return 0;
}
