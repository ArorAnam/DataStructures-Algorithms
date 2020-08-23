#include <bits/stdc++.h>

using namespace std;

void solve(int l) {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    assert(1 <= c && c <= n);
    assert(c <= a && a <= n);
    assert(c <= b && b <= n);

    cout << "Case #" << l << ": ";
    if((a + b - c) > n || (a + b - c == 1 && n >= 2)) {
        cout << "IMPOSSIBLE" << '\n';
    } else if(n == 1) {
        cout << "1" << '\n';
    } else if(n == 2) {
        if(c == 2)
            cout << "1 1" << '\n';
        else if(a == 2)
            cout << "1 2" << '\n';
        else if(b == 2)
            cout << "2 1" << '\n';
        else assert(false);
    } else {
        vector<int> res; res.reserve(n);
        for(int i = 0; i < a-c; i++) res.push_back(2);
        for(int i = 0; i < c; i++) res.push_back(3);
        for(int i = 0; i < b-c; i++) res.push_back(2);
        int left = n - (a+b-c);
        if(left > 0) {
            res.insert(res.begin()+1, left, 1);
        }
        for(int i = 0; i < n; i++)
            cout << res[i] << " \n"[i+1==n];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    int l = 0;
    while(t--) {
        solve(l);
        l++;
    }
    return 0;
}
