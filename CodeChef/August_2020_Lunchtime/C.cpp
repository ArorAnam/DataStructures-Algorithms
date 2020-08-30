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
#define all(x) x.begin(),x.end()
#define MOD (1e9+7)

const int N = 1e3 + 1;
int i, j, k, l;
int n, m;
vpii R(N);
vvi C(N, vi(N));

bool comp(pii a, pii b) {
    return a.first > b.first;
}

// numbers of players whose peak ratings did not occur in
// the same month as their peak rankings.
void solve() {
    cin >> n >> m;
    FOI(i, n) {
        cin >> R[i].first;
        R[i].second = i;
    }

    FOI(i, n)
        FOI(j, m)
            cin >> C[i][j];

    vpii prate(n);
    vpii prank(n);
    int id;
    FOI(i, m) {
        FOI(j, n) {
            id = R[j].second;
            R[j].first += C[id][i];
        }
        sort(all(R), comp);
        int rnk, prnk;
        FOI(j, n) {
            if (j == 0 || R[j - 1].first != R[j].first)
                rnk = j + 1;
            else
                rnk = prnk;
            id = R[j].second;
            if (i == 0 || prate[id].first < R[j].first)
                prate[id] = {R[j].first, i};
            if (i == 0 || prank[id].first > rnk)
                prank[id] = {rnk, i};
            prnk = rnk;
        }
    }
    int ans = 0;
    FOI(i, n)
        if(prate[i].second != prank[i].second) ++ans;

    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
