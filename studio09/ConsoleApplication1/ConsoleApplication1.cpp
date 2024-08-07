// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <forward_list>
#include <list>
#include <deque>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
	int arr[7] = { 0, 1, 2, 6, 3, 4, 5};
	int arrb[7] = { 5, 4, 3, 6, 2, 1, 0};

	vector<int> vi;
	list<int> li;
	deque<int> di;
	for (int i : arr) {
		vi.push_back(i);
		li.push_back(i);
		di.push_back(i);
	}

	forward_list<int> fli;
	for (int i : arrb) {
		fli.push_front(i);
	}

	// 1.1 Vector of String
	auto vb = vi.cbegin(); // vb is an iterator
	cout << "Printing vector of integer (push back): " << endl; // 0 1 2 6 3 4 5
	while (vb != vi.cend()) {
		cout << *vb << " ";
		vb++;
	}
	cout << endl;

	// 1.2 Forward List
	auto fb = fli.cbegin(); // fb is an iterator
	cout << "Printing forward list (push front): " << endl; // 0 1 2 6 3 4 5
	while (fb != fli.cend()) {
		cout << *fb << " ";
		fb++;
	}
	cout << endl;

	// 1.3 List
	auto lb = li.cbegin(); // lb is an iterator
	cout << "Printing list (push back): " << endl; // 0 1 2 6 3 4 5
	while (lb != li.cend()) {
		cout << *lb << " ";
		lb++;
	}
	cout << endl;

	// 1.4 Double-ended Queue
	auto db = di.cbegin(); // db is an iterator
	cout << "Printing double-ended queue (push back): " << endl;
	while (db != di.cend()) {
		cout << *db << " ";
		db++;
	}
	cout << endl;

	cout << "-------------------------------------------------------------------" << endl;


	// 2. Sort
	sort(vi.begin(), vi.end()); // sort vector of integer
	fli.sort();					// sort forward list
	li.sort();					// sort list
	sort(di.begin(), di.end()); // sort double-ended queue

	cout << "-------------------------------------------------------------------" << endl;

	// 3. Copy: out is an iterator supporting output operation regardless of the type of container
	ostream_iterator<int> out(cout, " | "); // ostream_iterator<T> out(ostream, delimiter);
	// copy(InputIterator first, InputIterator last, OutputIterator result);
	copy(vi.cbegin(), vi.cend(), out); cout << endl; // cout will print 0 | 1 | 2 | 3 | 4 | 5 | 6 |
	copy(fli.cbegin(), fli.cend(), out); cout << endl;
	copy(li.cbegin(), li.cend(), out); cout << endl;
	copy(di.cbegin(), di.cend(), out); cout << endl;

}

