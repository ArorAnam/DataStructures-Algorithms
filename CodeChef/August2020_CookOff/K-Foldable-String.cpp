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
int i, j, l;
int n, k;
string s;

void solve() {
    cin >> n >> k;
    assert(n % k == 0);
    cin >> s;
    string ans = "";

    int cnt_0 = 0;
    for(auto x : s)
        cnt_0 += (x =='0');
    int parts = n/k;
    if(cnt_0 % parts) {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }
    int zeros = cnt_0 / parts, ones = (n - cnt_0)/parts;
    while(zeros--)
        ans += '0';
    while(ones--)
        ans += '1';
    while(parts--)
        cout << ans, reverse(ans.begin(), ans.end());
        cout <<'\n';
}

// K is a divisor of N
// A string is said to be K foldable
// if can be changed to a string with lenght K
// By repaeating the follwing process
// S[0:k] -- prefix
// for each i(1 <= i <= K), check if S[2K - i + 1] == S[i]
// is not equal there is collison
// erase the prefix of S with length K
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
