#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define FOI(i,n) for(int i=0; i<n; i++)
#define FOI2(i,a,n) for(int i=a; i<n; i++)
#define pii pair<int, int>
#define ppii pair<int, pii>
#define INF (1e9+7)

const int side = 1e6;
const int N = 1e5+2;
int n, m;
vector<ppii> h(N), v(N);

// void solve() {
//
// }

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    FOI(i, n)
        cin >> h[i].first >> h[i].second.first >> h[i].second.second;

    FOI(i, n)
        cin >> v[i].first >> v[i].second.first >> v[i].second.second;



    return 0;
}
