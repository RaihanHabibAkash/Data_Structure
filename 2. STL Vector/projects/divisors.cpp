// Problem: একটি সংখ্যার সব গুণনীয়ক (ভাজক) বের করতে হবে
// Platform: LightOJ
// Link: https://lightoj.com/problem/dimik-divisor

/*
একটি সংখ্যার সব গুণনীয়ক (ভাজক) বের করতে হবে।

ইনপুট
প্রথম লাইনে থাকবে টেস্ট কেসের সংখ্যা T (≤ 10)। পরবর্তী T-সংখ্যক লাইনে একটি করে পূর্ণসংখ্যা N থাকবে, যেখানে 1 ≤ N ≤ 100,000।

আউটপুট
প্রতিটি কেসের জন্য একটি করে লাইন প্রিন্ট করতে হবে, শুরুতে কেস নম্বর দিতে হবে। এরপর N-এর সব গুণনীয়ক ছোটো থেকে বড়ো ক্রমানুসারে প্রিন্ট করতে হবে। প্রতিটি গুণনীয়ক শুধু একবার প্রিন্ট করতে হবে। গুণনীয়কগুলোকে শুধু একটি স্পেস দিয়ে আলাদা করতে হবে। লাইনের শেষে কোনো অতিরিক্ত স্পেস থাকবে না।


ইনপুট	
3
5555
120
49

আউটপুট
Case 1: 1 5 11 55 101 505 1111 5555
Case 2: 1 2 3 4 5 6 8 10 12 15 20 24 30 40 60 120
Case 3: 1 7 49
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Taking case
    int cs; cin >> cs;

    for(int i = 1; i <= cs; i++) {
        int number; cin >> number;
        vector<int> v;

        // Checking divisors and adding in vector
        for(int i = 1; i <= sqrt(number); i++) {
            if(number % i == 0 && i != number / i) {
                v.push_back(i);
                if(i != number / i) v.push_back(number / i);
            }
        }

        // Sorting vector accending order
        sort(v.begin(), v.end());

        cout << "Case " << i << ": "; 
        for(int a : v) cout << a << " ";
        cout << endl;


    // For ends of cases
    }

    return 0;
}