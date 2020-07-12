#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

#define ll long long int

int main() {
    int n;
    cin>>n;
    ll S = 0;

    vector<int> arr(n, 0);
    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i];
        S += arr[i];
    }

    if(S & 1) {
        cout << "NO";
        return 0;
    }

    unordered_map <ll , int> first, second;

    first[arr[0]] = 1;

    for(int i = 1; i < n; i++)
        second[arr[i]]++;

    ll sdash = 0;

    for(int i = 0; i < n; i++) {
        sdash += arr[i];    //first i numbers
        if (sdash == S/2) {
            cout << "YES\n";
            return 0;
        }

        if (sdash < S/2) {
            ll x = S/2 - sdash;
            // delete element from second half, and insert into first half
            if (second[x] > 0) {
                cout << "YES\n";
                return 0;
            }
        }
        else {
            ll y = sdash - S/2;
            if (first[y] > 0) {
                cout << "YES\n";
                return 0;
            }
        }

        //i+1
        first[arr[i+1]]++;
        second[arr[i+1]]--;

    }

    cout << "NO";
    
}