Answer studio 16 questions here

1. Team member: Ningyuan Xie; Anh Vo; Runyao Guo

2. Process of declaring an "interface": declare a class, and then add pure virtual functions.

3.
a. This is an example of "interface inheritance".
b. These member variables should be private.

4. We test to read a vector we write containing { 'h', 'e', 'l', 'l', 'o' }, and the read() output is "hello".

5.
a. We created an abstractfile pointing to the address of TextFile. Our main function is "AbstractFile* af = &tf;"

main function:
#include <iostream>
#include "../../SharedCode/AbstractFile.h"
#include "../../SharedCode/TextFile.h"
#include <vector>
#include <string>

using namespace std;

int main()
{
	// Studio 16 -> Question 4
	TextFile tf("tf_1");
	vector<char> v = { 'h', 'e', 'l', 'l', 'o' };
	tf.write(v);
	tf.read();

	// Studio 16 -> Question 5
	cout << endl;
	AbstractFile* af = &tf;
	af->write(v);
	af->read();
	
}

