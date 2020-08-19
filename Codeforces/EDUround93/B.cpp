#include <bits/stdc++.h>

using namespace std;

#define sz(a) int((a).size())
#define forn(i, n) for(int i = 0; i < int(n); i++)

void solve() {
    string s;
    cin >> s;
    vector<int> a;
    forn(i, sz(s)) if (s[i] == '1') {
        int j = i;
        while (j+1 < sz(s) && s[j+1] == '1')
            ++j;
        a.push_back(j - i + 1);
        i = j;
    }

    sort(a.rbegin(), a.rend());
    int ans = 0;
    for (int i = 0; i < sz(a); i+= 2)
        ans += a[i];
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}
