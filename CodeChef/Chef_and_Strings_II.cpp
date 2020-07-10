#include <bits/stdc++.h>

using namespace std;

#define ll long long int

vector<ll> gstrings;

void solve(ll n) {
    ll skip = 0;
    for(ll i = 0; i < n-1; i++) {
        skip += abs(gstrings[i+1] - gstrings[i]) - 1;
    }
    cout << skip << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        gstrings.resize(n);
        for(ll i=0; i<n; i++)
            cin >> gstrings[i];

        solve(n);
    }
}