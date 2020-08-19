#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define INF (1e9+7)

vvi prices;
vvi discounts;
vvi dp;

void solve() {
    int n, m;
    cin >> n >> m;
    prices.clear();
    discounts.clear();
    dp.clear();

    prices.resize(n); discounts.resize(n); dp.resize(n);
    for(int i=0; i<n; i++) {
        prices[i].resize(m);
        discounts[i].resize(m);
        dp[i].resize(m);
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> prices[i][j];

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> discounts[i][j];

    int currmin = (1LL << 44LL);
    for(int j=0; j<m; j++) {
        dp[0][j] = prices[0][j];
        currmin = min(prices[0][j], currmin);
    }

    for(int i=1; i<n; i++) {
        for(int j=0; j<m; j++) {
            dp[i][j] = min(currmin + prices[i][j], dp[i-1][j] + max(0LL, prices[i][j] - discounts[i-1][j]));
        }
        currmin = (1LL << 44LL);
        for(int j=0; j<m; j++)
            currmin = min(currmin, dp[i][j]);
    }

    cout << currmin << endl;
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
