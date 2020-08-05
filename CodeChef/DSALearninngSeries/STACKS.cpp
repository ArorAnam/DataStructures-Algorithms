// Let f(i) be the radius of the top disc
// We have to find f(i) such that f(i) > k
// So this is similar to upper bound

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;  // radius of top disc of stacks
// We have to storw the stacks in increasing order

int main() {
    int t;
    cin >> t;
    while (t--) {
        v.clear();
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++)
            cin >> A[i];

        for (int i = 0; i < n; i++) {
            vector<int>::iterator index;
            index = upper_bound(v.begin(), v.end(), A[i]); // index of the first stack such that we can place the index on this stacks

            if (index == v.end())
                v.push_back(A[i]);
            else
                v[index - v.begin()] = A[i];
        }
        cout << v.size() << " ";
        for (int j : v) cout << j << " ";
        cout << endl;
    }
}
