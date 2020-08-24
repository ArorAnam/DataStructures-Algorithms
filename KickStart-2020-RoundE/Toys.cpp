#include <bits/stdc++.h>
#include <numeric>

using namespace std;

//#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define FOI(i,n) for(int i=0; i<n; i++)
#define FOI2(i,a,n) for(int i=a; i<n; i++)
#define pii pair<int, int>
#define ppii pair<int, pii>
#define vpii vector<pii>
#define MOD (1e9+7)

const int64_t INF = 8e18;
const int N = 1e5+5;

void solve(int l) {
    int i, j, z;
    int n;
    cin >> n;
    vector<pair<int64_t, int>> R(n);
    vector<int64_t> E(n);
    FOI(i, n) {
        cin >> E[i] >> R[i].first;
        R[i].first += E[i];
        R[i].second = i;

    }
    sort(R.begin(), R.end());

    int64_t C = accumulate(E.begin(), E.end(), int64_t(0));

    // compute the prefix sums of alive toys
    vector<int64_t> bit(n);
    FOI(i, n)
        for(int a = i; a < n; a |= a+1)
            bit[a] += E[i];

    priority_queue<int, vector<int>, greater<int>> is_bad;

    int64_t ans = -1;
    int best_remove = -1;
    FOI(z, n) {
        while(!R.empty() && C < R.back().first) {
            is_bad.push(R.back().second);
            R.pop_back();
        }

        if(is_bad.empty()) {
            ans = INF;
            best_remove = z;
            break;
        }

        int cur = is_bad.top(); is_bad.pop();
        int64_t cnd = C;
        for(int a = cur; a > 0; a &= a-1)
            cnd += bit[a-1];

        if(cnd > ans) {
            ans = cnd;
            best_remove = z;
        }

        C -= E[cur];
        for(int a = cur; a < n; a |= a+1)
            bit[a] -= E[cur];
    }

    cout << "Case #" << l << ": ";
    cout << best_remove << ' ';
    if(ans == INF) cout << "INDEFINITELY" << '\n';
    else cout << ans << '\n';

}

/*
Given the description of the toys, remove the smallest possible
number of them in order to make Axel play either an indefinitely long
time, or (if that is not possible) as long as possible before he stops.

- he alwyas start with the toy that has the smallest number
- after largest toy --> smallest toy

*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    int l = 0;
    while(t--) {
        solve(++l);
    }
    return 0;
}
