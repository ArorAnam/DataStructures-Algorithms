#include <bits/stdc++.h>

using namespace std;

#define i64 int64_t
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
i64 P, F;
i64 CS, CW;
i64 S, W;

i64 can_take(i64 S, i64 W, i64 CS, i64 CW, i64 P) {
    if(S > W)
        return can_take(W, S, CW, CS, P);

    if(S * CS >= P)
        return P / S;

    return CS + min((P - S * CS) / W, CW);
}

void solve() {
    cin >> P >> F;
    cin >> CS >> CW;
    cin >> S >> W;
    i64 best = 0;

    for(i64 cs = 0; cs <= CS; cs++)
        if(cs * S <= P) {
            i64 cw = min((P - cs * S) / W, CW);
            best = max(best, cs + cw + can_take(S, W, CS - cs, CW - cw, F));
        }
    cout << best << '\n';
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
