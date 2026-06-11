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
    queue<Bnode*> q;
    q.push(root);

    while(!q.empty()) {
        Bnode* node = q.front();
        q.pop();

        cout << node->val << " ";

        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
}

Bnode* arrayToBST(int arr[], int l, int r) {
    // Base case
    if(l > r) return NULL;

    // Getting the mid index
    int mid = (l+r)/2;

    // Creating new cuurent node
    Bnode* root = new Bnode(arr[mid]);

    // Recurtion and recive root of tree or NULL
    Bnode* myLeft = arrayToBST(arr, l, mid-1);
    Bnode* myRight = arrayToBST(arr, mid+1, r);

    // Connecting root with children nodes
    root->left = myLeft;
    root->right = myRight;

    // returning current root
    return root;
}

int main() {
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    Bnode* root = arrayToBST(arr, 0, n-1);
    level_order(root);
    
    return 0;
}
