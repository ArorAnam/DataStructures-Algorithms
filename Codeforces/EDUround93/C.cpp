#include <bits/stdc++.h>

using namespace std;
#define MAXN 1e5
#define ll long long

void solve() {
    int n;
    string a;
    cin >> n >> a;
    map<int, int> freq;
    freq[0] = 1;
    int sum = 0;
    int64_t total = 0;

    for(int i = 0; i < n; i++) {
        sum += (a[i] - '0') - 1;
        total += freq[sum]++;
    }
    cout << total << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
