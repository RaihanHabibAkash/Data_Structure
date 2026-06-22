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

void level_order(Bnode* root, vector<int>& v, int k) {
    queue<pair<Bnode*, int>> q;
    q.push({root, 0});

    while(!q.empty()) {
        Bnode* node = q.front().first;
        int level = q.front().second;
        q.pop();

        if(level == k) v.push_back(node->val);

        if(node->left) q.push({node->left, level+1});
        if(node->right) q.push({node->right, level+1});
    }
}

int main() {
    Bnode* root = input_tree();

    vector<int> v;
    int k; cin >> k;
    level_order(root, v, k);
    
    for(int x : v) cout << x << " ";
    cout << endl;

    return 0;
}
