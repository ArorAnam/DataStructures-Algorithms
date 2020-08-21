#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define FOI(i,n) for(int i=0; i<n; i++)
#define FOI2(i,a,n) for(int i=a; i<n; i++)
#define endl '\n'
#define pii pair<int, int>
#define ppii pair<int, pii>
#define INF (1e9+7)

void solve() {
    int x0, x1, x2, y0, y1, y2;
    cin >> x0 >> x1 >> x2 >> y0 >> y1 >> y2;
    int m, sum = 0;

    m = min(x0, y2);
    x0 -= m;
    y2 -= m;

    m = min(x1, y0);
    x1 -= m;
    y0 -= m;

    m = min(x2, y1);
    x2 -= m;
    y1 -= m;
    sum += m*2;

    sum -= 2 * min(x1, y2);

    cout << sum << endl;
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
