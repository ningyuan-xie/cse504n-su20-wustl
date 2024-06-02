// Studio_10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <forward_list>
#include <list>
#include <deque>
#include <algorithm>
#include <iterator>

#include <set>
#include <map>

using namespace std;

int main(int argc, char* argv[]) // when running, input 1 1 4 5 1 4
{
	multiset<string> mst;
	set<string> ss;
	map<string, int> msi;
	
	cout << "-------------------------------------------------------------------" << endl;

	// 1. Multiset
	// copy(InputIterator first, InputIterator last, OutputIterator result);
	cout << "1. Multiset: " << endl;
	cout << "Copying value from argv to multiset: " << endl;
	copy(&argv[1], &argv[argc], inserter(mst, mst.begin())); // inserter will work on any containers

	cout << "Printing multiset: " << endl;
	ostream_iterator<string> o (cout, ", ");
	copy(mst.begin(), mst.end(), o); // 1, 1, 1, 4, 4, 5,
	cout << endl;

	cout << "-------------------------------------------------------------------" << endl;

	// 2. Set
	cout << "2. Set: " << endl;
	cout << "Copying value from multiset to set: " << endl;
	copy(mst.begin(), mst.end(), inserter(ss, ss.begin())); // inserter will work on any containers

	cout << "Printing set: " << endl;
	copy(ss.begin(), ss.end(), o); // 1, 4, 5,
	cout << endl;

	cout << "-------------------------------------------------------------------" << endl;

	// 3. Map
	cout << "3. Map: " << endl;
	cout << "Copying key and value from set and multiset to map: " << endl;
	for (string i : ss) { // key from set, which is unique key
		
		int n = count(mst.begin(), mst.end(), i); // value from multi set, which is count number of keys
		pair<string, int> pa = make_pair(i, n); // pair = {unique key: count number of keys}
		msi.insert(pa);
	}

	cout << "Printing map: " << endl;
	for (auto i : msi) {
		cout << i.first << " appears " << i.second << " times." << endl;
		// 1 appears 3 times.
		// 4 appears 2 times.
		// 5 appears 1 times.
	}

	cout << "-------------------------------------------------------------------" << endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
