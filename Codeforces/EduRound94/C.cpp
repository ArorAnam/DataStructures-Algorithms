#include <bits/stdc++.h>

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

const int N = 1e5+5;
int i, j, k, l;
int X;
string S;

void solve() {
    cin >> S;
    cin >> X;
    int n = int(S.size());
    string W(n, '1');

    FOI(i, n)
        if(S[i] == '0') {
            if(i - X >= 0)
                W[i-X] = '0';

            if(i + X < n)
                W[i+X] = '0';
        }

    FOI(i, n) {
        bool one = false;
        one = one || (i - X >= 0 && W[i - X] == '1');
        one = one || (i + X < n && W[i + X] == '1');

        if(S[i] != one + '0') {
            cout << -1 << '\n';
            return;
        }
    }
    cout << W << '\n';
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
