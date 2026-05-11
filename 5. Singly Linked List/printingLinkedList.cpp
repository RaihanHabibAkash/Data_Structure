#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        next = NULL;
    }
};

int main() {
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);

    // Placing pointer
    head->next = a;
    a->next = b;
    b->next = c;

    // Temp pointer for traversing 
    Node* current = head;

    // Printing 1st time
    while(current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    // Printing 2nd time
    current = head;
    while(current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
    
    return 0;
}
