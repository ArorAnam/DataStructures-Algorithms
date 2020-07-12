#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

bool comp(int x, int y) {
	//for decreasing order
	return x > y;
}

void vectorDemo() {
	vector<int> A = {1, 5, 67, 46, 34 , 9};

	sort(A.begin(), A.end()); // O(NlogN)

	// O(logN)
	bool present = binary_search(A.begin(), A.end(), 5);
	//cout << present;

	A.push_back(25);
	A.push_back(78);

	sort(A.begin(), A.end());

	// Also done in O(logN) time using binary search
	auto it = lower_bound(A.begin(), A.end(), 25); // >=
	auto it2 = upper_bound(A.begin(), A.end(), 25); // >
	cout << *it << " " << *it2 << endl;


	// Now if we want to sort in descending order, we can pass a comparator function
	sort(A.begin(), A.end(), comp);

	for(auto it: A) {
		cout << it << " ";
	}

	cout<<endl;
	for(auto &it: A) {
		it++;
		cout << it << " ";
	}
}

void setDemo() {
	set<int> S;
	S.insert(1);		//O(LogN) for insertion
	S.insert(2);
	S.insert(-19);
	S.insert(65);
	S.insert(4);

	//they are all ready sorted

	for(auto x : S)
		cout << x << " ";
	cout << endl;

	auto it = S.find(4);
	if(it == S.end())
		cout << "Not present\n";
	else
		cout << "present\n";

	auto it2 = S.lower_bound(-1);
	auto it3 = S.upper_bound(0);
	cout << *it2 <<" " << *it3 << endl;

	auto it4 = S.upper_bound(65);
	if (it4 == S.end())
		cout << "Oops cant find something like that\n";

	S.erase(1); // O(logN)

}

void mapDemo() {
	map<int, int> A;
	A[1] = 100;
	A[2] = -4;		// each of these mappings take O(logN) times
	A[78] = 65;
	A[23] = -45;

	map<char, int> cnt;
	string name = "Naman Arora";

	for(char c : name) {
		cnt[c]++;		// this will atke propotional to the length of the string
	}

	cout << cnt['a'] << " " << cnt['r'] << endl;  //each of these also take logN time

}

void powerOfSTL() {
	set< pair<int, int> > S;

	S.insert({2, 5});
	S.insert({10, 50});
	S.insert({100, 350});
	S.insert({400, 500});

	int point = 1;

	auto it = S.upper_bound({point, INT_MAX});
	if (it == S.begin()) {	
		cout << "Not present \n";
		return;
	}

	it--;
	pair<int, int> current = *it;
	if(current.first <= point && point <= current.second)
		cout << "Yes its present: " << current.first << ", " << current.second << endl;
	else
		cout << " the given point is not lying in the interval..\n";


}

int main()
{
	//setDemo();	
	//mapDemo();
	powerOfSTL();
	return 0;
}