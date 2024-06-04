// ExceptionStudio.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <exception>

using namespace std;

// function 1: return v[i]^2
int square_element(vector<int> v, unsigned int i)
{
	if (i > v.size() - 1)
	{
		throw out_of_range("Out of Range");
	}
	return v[i] * v[i];
}

// function 2: return v[i_1]^2 / v[i_2]^2
int divideSquaredElements(vector<int> v, unsigned int index1, unsigned int index2)
{
	int denom = square_element(v, index2);
	if (denom == 0)
	{
		throw logic_error("Divide by zero");
	}
	return square_element(v, index1) / denom;
}

int main(int argc, char * argv[])
{
	vector<int> vect;
	vect.push_back(1);
	vect.push_back(2);
	vect.push_back(3);

	try {
		cout << divideSquaredElements(vect, 1, 3) << endl;
	}
	// try block requires at least one "catch" handler below
	
	//catch (out_of_range e){
		//cout << "1. Error is: " << e.what() << endl; // shows: "1. Error is: Out of Range"
	//}
	
	// Note 1: the std::out_of_range exception type inherits from std::logic_error, so logic_error goes second
	catch (logic_error e) {
		cout << "2. Error is: " << e.what() << endl; // if first catch is comment out, shows: "2. Error is: Out of Range"
	}

	// Note 2: if fails to catch the thrown exception, the program crashes!
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
