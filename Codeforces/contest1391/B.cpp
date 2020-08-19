#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<vector<char>> grid;

void solve() {
    // at [n-1][j] we cant have D
    // at [i][m-1] we cant have R

    int i, j, n, m;
    cin >> n >> m;
    int res = 0;

    grid.clear();
    grid.resize(n);
    for (i = 0; i < n; i++)
        grid[i].resize(m);

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (j == m-1 && grid[i][j] == 'R')
                res++;
            if (i == n-1 && grid[i][j] == 'D')
                res++;
        }
    }
    cout << res << endl;
}

signed main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
