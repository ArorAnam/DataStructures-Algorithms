#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define FOI(i,n) for(int i=0; i<n; i++)
#define FOI2(i,a,n) for(int i=a; i<n; i++)
#define pii pair<int, int>
#define ppii pair<int, pii>
#define vpii vector<pii>
#define MOD (1e9+7)

const int N = 40;
int t, u, v, n, k;
int DP[2 * N][N];
bool V[2 * N];

void solve() {
    cin >> n >> k;

    FOI(i, 2 * n)
        FOI(j, n + 1)
            DP[i][j] = 0;

    FOI(i, 2 * n)
        V[i] = false;

    FOI(i, k) {
        cin >> u;
        V[u - 1] = true;
    }

    DP[0][1] = 1;
    FOI(i, 2 * n - 1) {
        FOI(j, n + 1) {
            DP[i + 1][j + 1] += DP[i][j];
            if(!V[i + 1])
                if(j != 0)
                    DP[i + 1][j - 1] += DP[i][j];
        }
    }
    cout << DP[2 * n - 1][0] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
