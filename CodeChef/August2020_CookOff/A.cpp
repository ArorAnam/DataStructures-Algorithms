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

int i, j, l;
int n, k;
vi W;

void solve() {
    cin >> n >> k;
    W.clear();
    W.resize(n+2);
    FOI(i, n)
        cin >> W[i+1];

    int trips = 0;
    int sum = 0;
    for(i = n; i >= 0; ) {
        sum = 0;
        while(sum <= k && i > 0) {
            if(sum + W[i] > k) break;
            sum += W[i];
            i--;
        }
        if(sum == 0 && i > 0) {
            cout << -1 << '\n';
            return;
        }
        trips++;
        if(i == 0) {
            cout << trips << '\n';
            return;
        }
    }
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
