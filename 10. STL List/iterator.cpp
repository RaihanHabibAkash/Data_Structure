#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l = {20,30,40,50,70};

    // l.begin() -> point 1st element
    // l.end() -> point last element

    for(auto it = l.begin(); it != l.end(); it++) cout << *it << " ";

    return 0;
}
