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
int n;
vi A(N);

void solve() {
    cin >> n;
    assert(n >= 4 && n <= 3000);
    A.clear();
    A.resize(n);
    for(auto &a : A) {
        cin >> a;
        a--;
    }

    vi freq(n*n, 0);
    i64 total = 0;

    for(k = n-1; k >= 0; k--) {
        for(l = k + 1; l < n; l++)
            freq[A[k] * n + A[l]]++;

        int j = k - 1;

        for(int i = 0; i < j; i++)
            total += freq[A[i] * n + A[j]];
    }

    cout << total << '\n';
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
