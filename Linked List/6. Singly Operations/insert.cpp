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

void insert(Node* &head, int val) {
    // Creating Node
    Node* newNode = new Node(val);

    // If Liked list is Empty
    if(head == NULL) head = newNode;
    else {
        // Current Node
        Node* current = head;

        // Inserting at 1st
        if(val <= current->val) {
            newNode->next = head;
            head = newNode;
        }
        else { // Not 1st
            // Traversing untile found val <= Number
            while(current->next != NULL) {
                if(val >= current->next->val) break;
                current = current->next; 
            }

            // Last Node
            if(current->next == NULL) current->next = newNode;
            // Middle node
            else {
                newNode->next = current->next;
                current->next = newNode;
            }

        // Innser else end
        }
    // Outter else end
    }
}

void printingSinglyLinkedList(Node* headCpy) {
    // For Traversing
    Node* current = headCpy;

    // Traversing and printing
    while(current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // For empty Node
    Node* head = NULL;

    // Inserting
    insert(head, 100);
    insert(head, 200);
    insert(head, 50);
    insert(head, 200);

    // Printing
    printingSinglyLinkedList(head);
    
    return 0;
}
