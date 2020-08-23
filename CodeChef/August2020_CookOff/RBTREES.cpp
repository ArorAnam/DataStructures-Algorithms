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

const int N = 1e5+5;
int i, j, k, l;
int n;
vvi tree(N, vector<int>(N));
vi type(N);

void solve() {
    cin >> n;
    int u, v;
    FOI(i, n-1) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    FOR(i, n)
        cin >> type[i];


}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
