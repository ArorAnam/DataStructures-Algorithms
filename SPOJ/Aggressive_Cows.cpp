#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> stalls;

int F(int x, int n, int c) {
    // We can place the first cow in the leftmost stall
    int cowsplaced = 1, lastpos = stalls[0];
    for(int i = 1; i < n; i++) {
        if (stalls[i] - lastpos >= x) {
            // we are atleat x distance away from last placed cow
            // So we can place one here
            if (++cowsplaced == c) return 1;
            lastpos = stalls[i];
        }
    }
    return 0;
}

int main() {
    //DP[i][k] -> the max number of cows we can place in shelters 1..i with minimum distance k
    //N.1e9 -> 1e14 -> way too large

    //If we know the min distance we can figure out how many we can place
    //F(MIN), we want to find the first MIN such that F(MIN) >= C
    //we have to proove that F(MIN) is MONOTONIC
    //If the minimum distance is smaller, then we can place more cows
    //The function is constantly decreasing
    //Since its contantly increasing we can apply a lower bound algorithm to it
    //
    //The f(x) takes O(N) time
    //Binary Search takes O(logN) time
    //Therfore our overall time is O(NLogN)
    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;

        stalls.clear();
        stalls.resize(n);
        for (int i = 0; i < n; i++)
            cin >> stalls[i];

        sort(stalls.begin(), stalls.end());

        int start = 0, end = stalls[n-1] - stalls[0] + 1, mid;
        while (end - start > 1) {
            mid = (end + start) >> 1;
            (F(mid, n, c) ? start : end) = mid;
        }

        cout << start << endl;
    }

    return 0;
}
