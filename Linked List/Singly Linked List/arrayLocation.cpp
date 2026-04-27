#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {0,2,3,4,5};
    cout << (uintptr_t)&v[2] << " " << (uintptr_t)&v[3];
    return 0;
}
