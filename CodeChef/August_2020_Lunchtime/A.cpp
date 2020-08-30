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
int n, m;
vi A(N);

void solve() {
    cin >> n;
    unordered_map<int, int> freq;
    FOI(i, n) {
        cin >> A[i];
        ++freq[A[i]];
    }

    unordered_map<int, int> freq_freq;
    for(auto x : freq)
        ++freq_freq[x.second];

    vector<pair<int, int>> heap;
    for(auto x : freq_freq) {
        heap.push_back({x.second, x.first});
    }

    auto comp = [&heap](pair<int, int> a, pair<int, int> b) {
        if(a.first == b.first)
            return a.second > b.second;
        else
            return a.first < b.first;
    };

    make_heap(heap.begin(), heap.end(), comp);

    // k = heap.front().first;
    // j = 0;
    // while(k == heap.front().first && heap.size() > 0) {
    //     if(heap.front().second < heap[j].second)
    //         break;
    //     pop_heap(heap.begin(), heap.end());
    //     ++j;
    // }
    cout << heap.front().second << '\n';
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
