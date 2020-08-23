#include <iostream>
#include <vector>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define FOI(i,n) for(int i=0; i<n; i++)
#define FOI2(i,a,n) for(int i=a; i<n; i++)
#define pii pair<int, int>
#define ppii pair<int, pii>
#define vp vector<pii>
#define MOD (1e9+7)

const int N = 1e5+5;
int n;
vi A(N);
int i, j, k, l;

// void solve() {
// }

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int stool = 0;
    FOI(i, n) {
        cin >> A[i];
        if(i == 0)
            continue;
        if(A[i] < A[i-1]) {
            stool += A[i-1] - A[i];
            A[i] = A[i-1];
        }
    }
    cout << stool << endl;

    return 0;
}
