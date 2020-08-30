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
#define MAXN 5005

const int N = 1e5+5;
int t, n, k, u, l, m;


string s;
int dp[1005][MAXN];

int solve(int i, int sum) {
    if (i == s.size()) {
        if (sum) return 1e9;
        return 0;
    }
    if (dp[i][sum] != -1) return dp[i][sum];
    int ret = 1e9;
    int num = 0;
    FOI2(k, i, s.size()) {
        num = num * 10 + (s[k] - '0');
        if (num > sum) break;
        ret = min(ret, 1 + solve(k + 1, sum - num));
    }
    return dp[i][sum] = ret;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof dp);
    string s1;
    cin >> s1;
    u = 0;
    int i;
    for(i = 0; i < s1.length(); i++) {
        if(s1[i] == '=')
            break;
        if(s1[i] != '0') {
            s.push_back(s1[i]);
            u = 0;
        }
        else if(s1[i] == '0' && u <= 3) {
            s.push_back(s1[i]);
            ++u;
        }
    }

    int sum = 0;
    for(int j = i + 1; j < s1.length(); j++)
        sum = sum * 10 + (s1[j] - '0');

    printf("%lld\n", solve(0, sum) - 1);

    return 0;
}
