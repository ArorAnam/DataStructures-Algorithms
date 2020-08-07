//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
#define int long long

using namespace std;

int INF = pow(10, 18)*2;
vector<pair<int, pair<int, int>>> v;

int f(int x) {  // s is the number of men
    int curr = 0;
    while (v[curr].second.first != -100) {
        // if the place is a dish
        if(v[curr].second.first == - 50) {
            x -= v[curr].second.second;
        }
        else {  // if place is a tribe
            if (v[curr].second.first <= x) {
                x += v[curr].second.second;
            }
        }
        curr++;
    }
    return x;
}

int l_b(int k, int lo, int hi) {
    int toreturn = INF;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int fmid = f(mid);
        if (fmid >= k) {
            toreturn = min(toreturn, mid);
            // look for an even smaller point y such that f(y) >= k
            // In order to do thid, look in the smaller half
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    return toreturn;
}

int u_b(int k, int lo, int hi) {
    int toreturn = INF;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int fmid = f(mid);
        if (fmid > k) {
            toreturn = min(toreturn, mid);
            // look for an even smaller point y such that f(y) >= k
            // In order to do thid, look in the smaller half
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    return toreturn;
}


signed main() {
    // we have to output minimun number of Chefs (Chef+friends) required so that even after all dishes atleast one is leftmost
    // The anser would just be sum of y(i)+1
    // we also have C tribes
    // Lets represent a function f(k) where k is the number of people that start the journey Chef + friends
    // Its trivial that f(k) is montonically increasing
    // If k is higher then your chance of makking it is also higher
    // Therfore f(k) is monotonocally increasing

    // We need to find the first k, for which f(k)>=1
    // Hence lower bound

    int t;
    cin >> t;
    while (t--) {
        v.clear();
        int X, B, C;
        cin >> X;

        cin >> B;
        // vector<pair<int, int>> dishes(B);
        for (int i = 0; i < B; i++) {
            int x, y;
            cin >> x >> y;
            v.push_back(make_pair(x, make_pair(-50, y)));
        }

        cin >> C;
        // vector<tuple<int, int, int>> tribals(C);
        for (int i = 0; i < C; i++) {
            int p, q, r;
            cin >> p >> q >> r;
            v.push_back(make_pair(p, make_pair(q, r)));
        }

        v.push_back(make_pair(X, make_pair(-100, -100)));
        sort(v.begin(), v.end());

        cout << l_b(1, 1, INF) << endl;
    }
    return 0;
}
