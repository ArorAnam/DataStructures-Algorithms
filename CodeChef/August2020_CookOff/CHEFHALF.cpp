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
vi A(N);

// take out subsequences of lenght 2L
// perform left rotations on it
// such that first L and last L sequences of it are like
// the smallest value in one half is greater than the largest
// value in the other half
// that means smallest L elemets in one half
// lasrgest L elements in other half
void solve() {
    cin >> n;
    FOI(i, n)
        cin >> A[i];


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
