#include <iostream>
#include <vector>
#include "student.h"
#include <algorithm>
#include <fstream>
using namespace std;



int main() {

	// 1. Create a vector of student
	vector<student> v;
	student jared("jared", 420);
	student syan("syan", 99);
	student claire("claire", 2345);

	v.push_back(jared);
	v.push_back(syan);
	v.push_back(claire);

	// 2. Read from txt input (not used), will work because we overloaded >>
	//fstream f;
	//f.open("students.txt");
	//if (!f.is_open()){cout<< "file not open!" << endl;}

	//int i = 0;
	//while (i < 6) {
	//	++i;
	//	student s;
	//	f >> s;
	//	v.push_back(s);
	//}

	// 3. Sort the vector of student, will work because we overloaded <
	sort(v.begin(), v.end()); // use name to sort

	// 4. print each student's name, will work by default
	for (student s : v) {
		cout << s.name << endl;
	}

	// 5. print each student's name + ID together using s only, will work because we overloaded <<
	for (student s : v) {
		cout << s << endl;
	}

}