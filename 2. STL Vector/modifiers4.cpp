#include <bits/stdc++.h>
using namespace std;

int main() {
    vector <int> v = {1,2,3,4,5};
    // For single deletion
    // v.erase(v.begin()+2);
    
    // Multiple deletion, last pointer + 1, to delete the pointer value.
    v.erase(v.begin()+1, v.end()-1);

    for(int x : v) cout << x << " ";

    return 0;
}
