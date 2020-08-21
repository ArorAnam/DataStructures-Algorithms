#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define FOI(i,n) for(int i=0; i<n; i++)
#define FOI2(i,a,n) for(int i=a; i<n; i++)
#define pii pair<int, int>
#define ppii pair<int, pii>
#deine vp vector<pii>
#define MOD (1e9+7)

const int N = 1e5+5;
int n, m;
vp edges(N);
int fact[N];
int i, j, k, l;

void solve() {
    cin >> n;
    FOR(i, n-1)
        cin >> edges[i].first >> edges[i].second;

    cin >> m;
    FOI(i, m)
        cin >> fact[i];



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
