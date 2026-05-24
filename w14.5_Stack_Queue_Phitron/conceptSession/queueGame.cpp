// Phitron Concept Session
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, guess;
    cout << "Chose number(n) for 1 - n" << endl; 
    cin >> n;
    cout << "Chose k'th number to delete every time" << endl; 
    cin >> k;
    cout << "Guess the winning number" << endl;
    cin >> guess;

    // Inserting value
    queue<int> q;
    for(int i = 1; i <= n; i++) q.push(i);

    int cnt = 0;
    while(q.size() > 1) {
        int val = q.front();
        q.pop();
        cnt++;

        if(cnt == k) cnt = 0;
        else q.push(val);
    }

    if(guess == q.front()) cout << "Win" << endl;
    else cout << "Loss" << endl;

    return 0;
}
