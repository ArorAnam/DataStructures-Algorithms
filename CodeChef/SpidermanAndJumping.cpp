#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define INF (1e9+7)

const int N = 300000;
int height[N];
int dp[N];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> height[i];
        dp[i] = (1LL << 60LL);
    }

    dp[0] = 0;
    for(int i=0; i<n; i++) {
        for(int j = 1; i-j >= 0; j <<= 1) {
            dp[i] = min(dp[i], dp[i-j] + abs(height[i] - height[i-j]));
        }
    }

    cout << dp[n-1] << endl;
    return 0;
}
