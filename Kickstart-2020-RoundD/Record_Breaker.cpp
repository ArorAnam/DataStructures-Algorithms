#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> arr, int n) {
    int maxrec = 0, cnt = 0;

    for (int i = 0; i < n; i++) {
        bool k = i == 0 || arr[i] > maxrec;
        bool l = i == n-1 || arr[i] > arr[i+1];

        if (k && l)
            cnt++;

        maxrec = max(maxrec, arr[i]);
    }

    //if (arr[n-1] > max) cnt++;

    return cnt;
}

int main() {
    int t, j = 0;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for(int i = 0 ; i < n; i++)
            cin >> arr[i];

        int res = solve(arr, n);

        cout <<"Case #"<<j+1<<": "<<res<<endl;
        j++;
    }
}
