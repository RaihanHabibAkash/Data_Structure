// Problem: 4th Highest Element
// Platform: Code360
// Difficulty: Easy
// Link: https://www.naukri.com/code360/problems/fourth-largest-element-in-the-array_1792782
// Topics: Heap Insertion & Deletion
/*
Given an array 'ARR' of 'N' integers. Find the fourth highest element present in the give 'ARR'. Return the minimum value of an integer which is -2147483648 if there it does not exists.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= N < 10^6
-10^6 <= ARR[i] <= 10^6

Where 'ARR[i]' denotes the 'ARR' element at 'ith' position.

Time Limit: 1 sec
Sample Input 1:
5
3 5 1 3 1
Sample Output 1:
1
Explanation Of Sample Input 1:
5 is the largest element, 3 is the second-largest element, again we have a 3 so it's the third largest and 1 is the fourth-largest, hence the answer 1.
Sample Input 2:
4
9 9 9 9
Sample Output 2:
9
*/


#include <bits/stdc++.h>
using namespace std;

void insert(vector<int>& v, int val) {
    v.push_back(val);

    int curIdx = v.size() - 1;
    while(curIdx > 0) {
        int parIdx = (curIdx - 1) / 2;

        if(v[parIdx] < v[curIdx]) swap(v[parIdx], v[curIdx]);
        else break;

        curIdx = parIdx;
    }
}

void dlt(vector<int>& v) {
    v[0] = v.back();
    v.pop_back();

    int curIdx = 0;

    while(v.size() > 1) {
        int leftIdx = (curIdx * 2) + 1;
        int rightIdx = (curIdx * 2) + 2;
        int leftVal = INT_MIN;
        int rightVal = INT_MIN;

        if(leftIdx < v.size()) leftVal = v[leftIdx];
        if(rightIdx < v.size()) rightVal = v[rightIdx];

        if(leftVal >= rightVal && leftVal > v[curIdx]){
            swap(v[leftIdx], v[curIdx]);
            curIdx = leftIdx;
        }
        else if(rightVal > leftVal && rightVal > v[curIdx]){
            swap(v[rightIdx], v[curIdx]);
            curIdx = rightIdx;
        }
        else break;
    }
}

int getFourthLargest(int arr[], int n)
{
    vector<int> heap;
    for(int i = 0; i < n; i++)
        insert(heap, arr[i]);

    // Poping vlues 3 times
    for(int i = 0; i < 3; i++) dlt(heap);

    if(heap.empty()) return INT_MIN;
    else return heap[0];
}