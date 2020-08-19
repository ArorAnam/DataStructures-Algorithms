#include <bits/stdc++.h>

using namespace std;

#define int long long
int n, m , Sx, Sy;
vector<vector<bool>> visited;

void solve() {
    cin >> n >> m >> Sx >> Sy;
    visited.resize(n);
    for (int  i = 0; i < n; i++)
        visited[i].resize(m);


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
