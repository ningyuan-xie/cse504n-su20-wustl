studio 20 answers here

1. Group members: Ningyuan Xie; Anh Vo; Runyao Guo


2. Because if the user input incorrect password, the pointer to the actual file should be deleted
to prevent the user from accessing the actual file.


4. Tests performed (from the Studio20.cpp):

	// dynamically allocate an AbstractFile
	ImageFile* i = new ImageFile("File.img");

	// PasswordProxy for that file 
	PasswordProxy* p = new PasswordProxy(i, "123456");

	// Reading the file
	cout << "Reading the file:" << endl;
	cout << "Password:";
	p->read();

	// Writing the file
	cout << "Writing the file:" << endl;
	cout << "Password:";
	vector<char> v = { 'X', ' ', 'X', ' ', 'X', ' ', 'X',' ', 'X', '3' };
	p->write(v);

	// Displaying the file via the proxy object
	cout << "Reading the file:" << endl;
	cout << "Password:";
	BasicDisplayVisitor bdv;
	p->accept(&bdv);

   Results: 
   Each step, the console will pop out instruction for input password;
   If I input the wrong password (other than "123456"), the function will not generate any result; 
   if I input all the password correctly, final display will correctly print out:
	X X
	 X
	X X