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
	auto vb = vi.cbegin();
	cout << "Printing vector of integer (push back): " << endl;
	while (vb != vi.cend()) {
		cout << *vb << " ";
		vb++;
	}
	cout << endl;

	// 1.2 Forward List
	auto fb = fli.cbegin();
	cout << "Printing forward list (push front): " << endl;
	while (fb != fli.cend()) {
		cout << *fb << " ";
		fb++;
	}
	cout << endl;

	// 1.3 List
	auto lb = li.cbegin();
	cout << "Printing list (push back): " << endl;
	while (lb != li.cend()) {
		cout << *lb << " ";
		lb++;
	}
	cout << endl;

	// 1.4 Double-ended Queue
	auto db = di.cbegin();
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


	// 3. Copy
	ostream_iterator<int> out(cout, " ");
	// copy(InputIterator first, InputIterator last, OutputIterator result);
	copy(vi.cbegin(), vi.cend(), out); cout << endl;
	copy(fli.cbegin(), fli.cend(), out); cout << endl;
	copy(li.cbegin(), li.cend(), out); cout << endl;
	copy(di.cbegin(), di.cend(), out); cout << endl;

}

