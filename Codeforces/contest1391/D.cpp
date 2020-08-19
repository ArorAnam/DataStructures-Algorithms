#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+1;
int n, m;

void fill3() {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            bool bad = 0;
            for (int st = 0; st < 2; st++) {
                int bits = (bool)(i&(1<<st))+(bool)(i&(1<<(st+1)));
                bits += (bool)(j&(1<<st))+(bool)(j&(1<<(st+1)));
                if (bits%2 == 0)
                    bad = 1;
            }
            if(!bad)
                ok3[i][j] = 1;
        }
    }
}

void fill2() {
    for(int i =0; i < 4; i++) {
        for(int j =0; j < 4; j++) {
            bool bad = 0;
            for(int st = 0; st < 1; st++) {
                int bits = (bool)(i&(1<<st))+(bool)(i&(1<<(st+1)));
                bits += (bool)(j&(1<<st))+(bool)(j&(1<<(st+1)));
                    bad = 1;
            }
            if(!bad)
                ok2[i][j] = 1;
        }
    }
}

void solve2() {
    for(int i  = 1; i<=m; i++) {
        int mask = a[1][i] + 2*a[2][i];
        for(int cur = 0; cur < 4; cur++) {
            dp2[i][curr] = 1e9;
            for(int prev = 0; prev < 4; prev++) {
                if(!ok2[prev][cur])
                    continue;
                    dp2[i][cur] = min(dp2[i][cur], dp2[i-1][prev]+__builtin_popcount(cur^mask));
            }
        }
    }
    int ans = 1e9;
    for(int i = 0; i < 4; i++) ans = min(ans, dp2[m][i]);
    cout << ans;
}

void solve3() {
    for(int i =0; i <=m; i++) {
        int mask = a[1][i]
    }
}

void solve() {
    cin >> n >> m;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    fill2();
    fill3();
    solve();

    return 0;
}
