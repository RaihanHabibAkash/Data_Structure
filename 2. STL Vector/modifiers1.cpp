// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     vector <int> v = {1,2,3,4,5};
//     vector <int> v2;
    
//     // Assinging vector
//     v2 = v;
//     for(size_t i = 0; i < v2.size(); i++)
//         cout << v2[i] << " ";

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int main() {
    // Assinging vector
    vector <int> v = {1,2,3,4,5};
    vector <int> v2;
    v2 = v;
    // v2.assign(v.begin(), v.end());
    for(int x : v2)
        cout << x << " ";

    return 0;
}
