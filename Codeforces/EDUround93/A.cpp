#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n; cin >> n;
    int a[n];
    for (int  i = 0; i < n; i++)
        cin >> a[i];

    if (a[0] + a[1] <= a[n-1])
        cout <<1<<" "<<2<<" "<<n<<endl;
    else
        cout << -1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
