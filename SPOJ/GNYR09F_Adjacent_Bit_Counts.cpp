#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define FOI(i,n) for(int i=0; i<n; i++)
#define FOI2(i,a,n) for(int i=a; i<n; i++)
#define INF (1e9+7)

const int N = 200;
int dp[N][N][2];
int sn, n, k;

void solve() {
    cin >> sn >> n >> k;
    FOI(i, n)
        FOI(j, k+1)
            FOI(c, 2)
                dp[i][j][c] = 0;

    dp[0][0][1] = dp[0][0][0] = 1;

    FOI2(i, 1, n)
        FOI(j, k+1) {
            dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1];
            if(j > 0)
                dp[i][j][1] = dp[i-1][j-1][1];
            dp[i][j][1] += dp[i-1][j][0];
        }
    cout << sn << " " << dp[n-1][k][1] + dp[n-1][k][0] << endl;
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
