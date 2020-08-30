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

const int N = 3e5+5;
int i, j, k, l;
int n, m;
vi A(N);

void solve() {
    cin >> n;
    FOI(i, n) {
        cin >> A[i];
    }

    vi ZeroSegmentLen;
    FOI(i, n) {
        if (A[i]) continue;
        k = i;
        while((k + 1 < n) && (A[k + 1] == 0))
            k++;
        ZeroSegmentLen.push_back(k - i + 1);
        i = k;
    }
    if (ZeroSegmentLen.size() == 0)
        cout << "No" << '\n';
    else if (ZeroSegmentLen.size() == 1) {
        if(ZeroSegmentLen[0] % 2)
            cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    else {
        int maxLen = 0, id = -1;
        m = ZeroSegmentLen.size();
        FOI(i, m)
            if (maxLen < ZeroSegmentLen[i]) {
                maxLen = ZeroSegmentLen[i];
                id = i;
            }

        swap(ZeroSegmentLen[0], ZeroSegmentLen[id]);

        maxLen = 0, id = -1;
		FOI2(i, 1, m)
			if(maxLen < ZeroSegmentLen[i]) {
				maxLen = ZeroSegmentLen[i];
				id = i;
			}
        swap(ZeroSegmentLen[1], ZeroSegmentLen[id]);

        if (ZeroSegmentLen[0] % 2 && ZeroSegmentLen[1] <= (ZeroSegmentLen[0] - 1)/2)
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
	}
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
