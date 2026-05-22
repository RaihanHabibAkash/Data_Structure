#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node *next;
};

int main() {
    Node a, b, c;
    a.val = 10; b.val = 20; c.val = 30;
    a.next = &b; b.next = &c; c.next = NULL;

    // Value
    cout << a.val << " " << b.val << " " << c.val << endl;
    // Address
    cout << a.next << " " << b.next << " " << c.next << endl;

    // Accesing using pointer
    cout << a.val << " " << (*a.next).val << " " << (*(*a.next).next).val << endl;

    // Acessing using arrow sign
    cout << a.val << " " << a.next->val << " " << a.next->next->val << endl;
    
    return 0;
}
