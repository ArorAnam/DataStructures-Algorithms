nclude <bits/stdc++.h>

using namespace std;

//#define int long long

int check(int r, int g, int b, int w) {
    int cnt = 0;
    if (r % 2 != 0)
        cnt++;
    if (g % 2 != 0)
        cnt++;
    if (b % 2 != 0)
        cnt++;
    if (w % 2 != 0)
        cnt++;
    return cnt;
}

void solve() {
    int r, g, b, w;
    cin >> r >> g >> b >> w;

    int k = min(min(r, g), b);
    if (k == 0) {
        if(check(r, g, b, w) <= 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        return;
    }


    do {
        int cnt = check(r, g, b, w);
        if (cnt <= 1) {
            cout << "Yes" << endl;
            return;
        }
        else {
            r--; g--; b--;
            w += 3;
        }
    } while (k--);

    cout << "No" << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
