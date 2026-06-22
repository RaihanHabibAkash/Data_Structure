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

int cntNds(Bnode* root) {
    // Base case
    if(!root) return 0;

    int l = cntNds(root->left);
    int r = cntNds(root->right);

    return l+r+1;
}

int height(Bnode* root) {
    if(!root) return 0;

    int l = height(root->left);
    int r = height(root->right);

    return max(l, r) + 1;
}

int main() {
    Bnode* root = input_tree();

    if(!root) cout << "YES" << endl;
    else if((pow(2, height(root)) - 1) == cntNds(root)) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}
