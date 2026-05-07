/*
// Call by value
#include <bits/stdc++.h>
using namespace std;

void func(int* ptr) {
    cout << "Pointer in func: " << &ptr << endl;
}

int main() {
    int x = 10;
    int* p = &x;
    func(p);
    cout << "Pointer in main: " << &p << endl;
    return 0;
}
*/



// Call by reference
#include <bits/stdc++.h>
using namespace std;

void func(int* &ptr) {
    cout << "Pointer in func: " << &ptr << endl;
    ptr = NULL;
}

int main() {
    int x = 10;
    int* p = &x;
    func(p);
    cout << "Pointer in main: " << &p << endl;
    cout << p << endl;

    return 0;
}