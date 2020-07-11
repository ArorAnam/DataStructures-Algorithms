#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

int main() {

    map <char, int> M;
    unordered_map <char, int> U;

    string s = "Lorem ipsum dolor sit amet";

    //add(key, value) = logN, O(1)
    //erase(key) = logN, O(1)

    for (char c : s) M[c]++;    // O(NlogN), N = |s|

    for (char c : s) U[c]++;    // O(N) 



    return 0;
}