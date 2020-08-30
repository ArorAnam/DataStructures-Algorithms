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
string s;


// string w simliar to - s[1..n], s[2..n+1], s[3..n+2]....s[n..2n-1]
void solve() {
    cin >> n;
    cin >> s;
    assert(s.length() == 2*n-1);
    if(s.length() == 1) {
        cout << s << '\n';
        return;
    }
    else {
        string res = "";
        FOI(i, n)
            res += s[(2*n-1)/2];
        cout << res << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
