#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define FOI(i,n) for(int i=0; i<n; i++)
#define FOI2(i,a,n) for(int i=a; i<n; i++)
#define INF (1e9+7)

const int N = 200;
int dp[N][N] = {0};
int n, k;

// void solve() {
//
// }

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    dp[0][0] = 1;

    FOI(i, 20) {
        FOI(j, (i*(i-1))/2 + 1) {
            for(int k=0; k < i && j-k >=0; ++k) {
                dp[i][j] += dp[i-1][j-k];
            }
        }
    }

    while (t--) {
        cin >> n >> k;
        cout << dp[n][k] << endl;
    }
    
    return 0;
}
