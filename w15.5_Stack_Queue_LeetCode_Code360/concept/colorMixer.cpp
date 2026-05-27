/*
Red+Blue = Green
Red+Blue = Purple
Red+Yellow = Orange
Red+Green = Brown
We have an color platers with every colors first name. we can make up colors mixed. 
We can take out of the mixed color from colors box. We need to know if the brow color can be make
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    string colors; cin >> colors;
    stack<char> st;
    bool flag = false;

    for(int i = 0; i < colors.size(); i++) {
        if(st.empty()) st.push(colors[i]);
        else {
            if((st.top() == 'Y' && colors[i] == 'B') || (st.top() == 'B' && colors[i] == 'Y')) {
                st.pop(); // Red+Blue = Greeen (We need it)
                st.push('G');
            }
            else if((st.top() == 'R' && colors[i] == 'B') || (st.top() == 'B' && colors[i] == 'R'))
                st.pop(); // Red+Blue = Purple (Don't need it, so we can take from the box)
            else if((st.top() == 'R' && colors[i] == 'Y') || (st.top() == 'Y' && colors[i] == 'R'))
                st.pop(); // Red+Yellow = Orange (Don't need it, so we can take from the box)
            else if((st.top() == 'R' && colors[i] == 'G') || (st.top() == 'G' && colors[i] == 'R')) {
                flag = true; // Red+Green = Brown(We need this, so true)
                break;
            }
            else st.push(colors[i]);
        }
    }

    cout << (flag ? "YES" : "NO") << endl;

    return 0;
}
