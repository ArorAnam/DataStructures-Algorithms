#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define FOI(i,n) for(int i=0; i<n; i++)
#define FOI2(i,a,n) for(int i=a; i<n; i++)
#define INF (1e9+7)


int n, k;

void solve() {
    cin >> n >> k;
    int ans = max(k-n, 0);
    n += ans;
    if(n%2 != k%2) ans++;
    cout << ans << endl;
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
