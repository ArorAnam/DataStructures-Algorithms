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

const int N = 1e3+5;
int i, j, k, l;
int n, m;
vector<string> S(N);

void solve() {
    cin >> n;
    map<char, int> count;
    FOI(i, n) {
        cin >> S[i];
        for(auto c : S[i])
            ++count[c];
    }

    // vector<pair<char, int>> A;
    // for(auto& it : count)
    //     A.push_back(it);
    //
    // auto comp = [&A](pair<char, int> a, pair<char, int> b) {
    //     return a.second < b.second;
    // };
    //
    // sort(A.begin(), A.end(), comp);

    //auto first_count = A.begin()->second;
    for(auto& it : count) {
        if(it.second < n || it.second % n) {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" <<'\n';
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
