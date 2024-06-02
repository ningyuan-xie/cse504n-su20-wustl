#include "pch.h"
#include "CppUnitTest.h"
#define protected public
#include "../../SharedCode/TextFile.cpp"
#include "../../SharedCode/ImageFile.cpp"
#include "../../SharedCode/SimpleFileFactory.cpp"
#include "../../SharedCode/SimpleFileSystem.cpp"
#include "../../SharedCode/BasicDisplayVisitor.cpp"
#include "../../SharedCode/BasicDisplayVisitor2.cpp"
#include "../../SharedCode/MetadataDisplayVisitor.cpp"
#include "../../SharedCode/PasswordProxy.cpp"
#include "../../SharedCode/TouchCommand.cpp"
#include "../../SharedCode/CommandPrompt.cpp"
#include "../../SharedCode/CommandTest.cpp"
#include "../../SharedCode/RemoveCommand.cpp"
#include "../../SharedCode/LSCommand.cpp"
#include "../../SharedCode/CatCommand.cpp"
#include "../../SharedCode/DisplayCommand.cpp"
#include "../../SharedCode/CopyCommand.cpp"
#include "../../SharedCode/MacroCommand.cpp"
#include "../../SharedCode/RenameParsingStrategy.cpp"
#undef protected


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(textFile)
	{
	public:

		TEST_METHOD(contstructor)  // checks that the file is initialized with proper name and size, expects size to be 0 and the name to match the input to the constructor
		{
			// REDIRECT COUT STREAM -- TO PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());

			std::string fileName = "FileName.txt";
			unsigned int fileSize = 0;
			TextFile t(fileName);
			Assert::AreEqual(t.getName(), fileName);
			Assert::AreEqual(t.getSize(), fileSize);
		}
		TEST_METHOD(write) // tests write, expects that the function returns success and that the size of the file is updated correctly
		{
			// REDIRECT COUT STREAM -- TO PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());

			std::string fileName = "FileName.txt";
			TextFile t(fileName);
			std::vector<char> v = { 'h', 'i' };
			Assert::AreEqual(t.write(v), 0);
			Assert::AreEqual(t.getSize(), static_cast<unsigned int>(v.size()));

		}
		TEST_METHOD(append) // tests append, expects the write and append functions to return 0 and the size of the file to update correctly
		{
			// REDIRECT COUT STREAM -- TO PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());

			std::string fileName = "FileName.txt";
			TextFile t(fileName);
			std::vector<char> v = { 'h', 'i' };
			Assert::AreEqual(t.write(v), 0);
			unsigned int fileSize = t.getSize();
			Assert::AreEqual(t.append(v), 0);
			Assert::AreEqual(t.getSize(), static_cast<unsigned int>(fileSize + v.size()));

		}
		TEST_METHOD(read) // tests that the read function outputs the contents of the file
		{
			// REDIRECT COUT STREAM -- TO PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());

			std::string fileName = "FileName.txt";
			TextFile t(fileName);
			std::vector<char> v = { 'h', 'i' };
			Assert::AreEqual(t.write(v), 0);
			std::vector<char> contents = t.read();
			Assert::AreEqual((size_t)t.getSize(), v.size());
			Assert::AreEqual(contents.size(), v.size());
			for (size_t i = 0; i < contents.size(); ++i) {
				Assert::AreEqual(v[i], contents[i]);
			}
		}
		TEST_METHOD(readWithAppend) // tests that read also works with appending to a file
		{
			// REDIRECT COUT STREAM -- TO PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());

			std::string fileName = "FileName.txt";
			TextFile t(fileName);
			std::vector<char> v = { 'h', 'i' };
			Assert::AreEqual(t.write(v), 0);
			Assert::AreEqual(t.append(v), 0);
			std::vector<char> newExpectedV = { 'h', 'i',  'h', 'i' };
			std::vector<char> contents = t.read();
			Assert::AreEqual(t.getSize(), static_cast<unsigned int>(newExpectedV.size()));
			Assert::AreEqual(contents.size(), newExpectedV.size());
			for (size_t i = 0; i < contents.size(); ++i) {
				Assert::AreEqual(newExpectedV[i], contents[i]);
			}

		}
	};
	TEST_CLASS(imageFile)
	{
	public:

		TEST_METHOD(contstructor) // checks that the file is initialized with proper name and size, expects size to be 0 and the name to match the input to the constructor
		{
			// REDIRECT COUT STREAM -- TO PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());

			std::string fileName = "FileName.img";
			unsigned int fileSize = 0;
			ImageFile t(fileName);
			Assert::AreEqual(t.getName(), fileName);
			Assert::AreEqual(t.getSize(), fileSize);
		}
		TEST_METHOD(writeValid) // tests write with a valid vector input, expects write to return success, and the size of the contents to be equal to that of the input vector -1 (for the last index that is removed
		{
			// REDIRECT COUT STREAM -- TO PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());

			std::string fileName = "FileName.img";
			unsigned int fileSize = 0;
			ImageFile t(fileName);
			std::vector<char> v = { 'X', ' ', 'X', ' ', 'X', ' ', 'X',' ', 'X', '3' };
			Assert::AreEqual(t.write(v), 0);
			Assert::AreEqual(t.getSize(), static_cast<unsigned int>(v.size() - 1));
		}
		TEST_METHOD(writeSizeMismatch) // tests write with a size mismatch in the input vector, expects write to return a non-zero value and the size of the contents to remain 0
		{
			// REDIRECT COUT STREAM -- TO PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());

			std::string fileName = "FileName.img";
			unsigned int fileSize = 0;
			ImageFile t(fileName);
			std::vector<char> v = { 'X', ' ', 'X', ' ', 'X', ' ', 'X',' ', 'X', 4 };
			Assert::AreNotEqual(t.write(v), 0); // non-zero error returned
			Assert::AreEqual(t.getSize(), fileSize); // contents not added
		}
		TEST_METHOD(writeInvalidPixel) // tests write with an invalid pixel in the input vector, expects write to return a non-zero value and the size of the contents to remain 0
		{
			// REDIRECT COUT STREAM -- TO PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());

			std::string fileName = "FileName.img";
			unsigned int fileSize = 0;
			ImageFile t(fileName);
			std::vector<char> v = { 'X', ' ', 'X', ' ', 'Y', ' ', 'X',' ', 'X', 3 };
			Assert::AreNotEqual(t.write(v), 0);
			Assert::AreEqual(t.getSize(), fileSize); // contents not added
		}
		TEST_METHOD(appendInvalid) // tests that append returns a non-zero value (can't append to an image)
		{
			// REDIRECT COUT STREAM -- TO PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());

			std::string fileName = "FileName.img";
			unsigned int fileSize = 0;
			ImageFile t(fileName);
			std::vector<char> v = { 'X', ' ', 'X', ' ', 'Y', ' ', 'X',' ', 'X', '3' };
			Assert::AreNotEqual(t.append(v), 0); // can't append to image
		}
		TEST_METHOD(read) // tests that read returns the contents that are written to the file
		{
			// REDIRECT COUT STREAM -- TO PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());

			std::string fileName = "FileName.img";
			ImageFile t(fileName);
			std::vector<char> v = { 'X', ' ', 'X', ' ', 'X', ' ', 'X',' ', 'X', '3' };
			Assert::AreEqual(t.write(v), 0);
			std::vector<char> contents = t.read();
			Assert::AreEqual(contents.size(), v.size() - 1);
			for (size_t i = 0; i < contents.size(); ++i) {
				Assert::AreEqual(contents[i], v[i]);
			}
		}
	};
	TEST_CLASS(simpleFileSystem)
	{
	public:

		TEST_METHOD(addValid) // adds two different files to the system, expects success as return value both times
		{
			// REDIRECT COUT STREAM -- TO PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());

			SimpleFileSystem sfs;
			SimpleFileFactory sff;
			AbstractFile* img = sff.createFile("FileName.img");
			AbstractFile* txt = sff.createFile("FileName.txt");
			Assert::AreEqual(sfs.addFile(img->getName(), img), 0);
			Assert::AreEqual(sfs.addFile(txt->getName(), txt), 0);
		}
		TEST_METHOD(addNullFile) // adds a nullptr to the filesystem, expects a non-zero return value
		{
			// REDIRECT COUT STREAM -- TO PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());

			SimpleFileSystem sfs;
			ImageFile* img = nullptr;
			Assert::AreNotEqual(sfs.addFile("FileName.img", img), 0);
		}
		TEST_METHOD(addFileAlreadyExists) // adds the same file twice, the first time should return success, the second time should return a non-zero value
		{
			// REDIRECT COUT STREAM -- TO PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());

			SimpleFileSystem sfs;
			SimpleFileFactory sff;
			AbstractFile* img = sff.createFile("FileName.img");
			Assert::AreEqual(sfs.addFile(img->getName(), img), 0);
			Assert::AreNotEqual(sfs.addFile(img->getName(), img), 0);
		}
		TEST_METHOD(deleteValid) // deletes a valid file (a file that exists and is not open), expects 0 as a return value
		{
			// REDIRECT COUT STREAM -- TO PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());

			SimpleFileSystem sfs;
			SimpleFileFactory sff;
			AbstractFile* img = sff.createFile("FileName.img");
			Assert::AreEqual(sfs.addFile(img->getName(), img), 0);
			Assert::AreEqual(sfs.deleteFile(img->getName()), 0);
		}
		TEST_METHOD(deleteFileDoesNotExist) // deletes a file that has not been added, expects a non-zero return value
		{
			// REDIRECT COUT STREAM -- TO PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());

			SimpleFileSystem sfs;
			SimpleFileFactory sff;
			AbstractFile* img = sff.createFile("FileName.img");
			Assert::AreNotEqual(sfs.deleteFile(img->getName()), 0);
		}
		TEST_METHOD(openValid) //  opens a valid file that exists and is not already open, expect to see the same file returned
		{
			// REDIRECT COUT STREAM -- TO PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());

			SimpleFileSystem sfs;
			SimpleFileFactory sff;
			AbstractFile* img = sff.createFile("FileName.img");
			Assert::AreEqual(sfs.addFile(img->getName(), img), 0);
			AbstractFile* res1 = sfs.openFile(img->getName());
			bool sameAddress = &(*img) == &(*res1);
			Assert::IsTrue(sameAddress);
		}
		TEST_METHOD(openFileNotAdded) // opens a file that has not been added, expects a null pointer
		{
			// REDIRECT COUT STREAM -- TO PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());

			SimpleFileSystem sfs;
			SimpleFileFactory sff;
			AbstractFile* img = sff.createFile("FileName.img");
			AbstractFile* res1 = sfs.openFile(img->getName());
			bool isNull = res1 == nullptr;
			Assert::IsTrue(isNull);
		}
		TEST_METHOD(openAlreadyOpenedFile) // opens a file twice, the first time should return the same file, the second time should return nullptr
		{
			// REDIRECT COUT STREAM -- TO PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());

			SimpleFileSystem sfs;
			SimpleFileFactory sff;
			AbstractFile* img = sff.createFile("FileName.img");
			Assert::AreEqual(sfs.addFile(img->getName(), img), 0);
			AbstractFile* firstOpen = sfs.openFile(img->getName());
			bool sameAddress = &(*img) == &(*firstOpen);
			Assert::IsTrue(sameAddress);
			AbstractFile* secondOpen = sfs.openFile(img->getName());
			bool isNull = secondOpen == nullptr;
			Assert::IsTrue(isNull);
		}
		TEST_METHOD(closeValid) // closes a file that has been added and opened, expect success
		{
			// REDIRECT COUT STREAM -- TO PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());

			SimpleFileSystem sfs;
			SimpleFileFactory sff;
			AbstractFile* img = sff.createFile("FileName.img");
			sfs.addFile(img->getName(), img);
			sfs.openFile(img->getName());
			int res1 = sfs.closeFile(img);
			Assert::AreEqual(res1, 0);
		}
		TEST_METHOD(closeNotOpen) // closes a file that has been added but not opened, expects a non-zero return value
		{
			// REDIRECT COUT STREAM -- TO PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());

			SimpleFileSystem sfs;
			SimpleFileFactory sff;
			AbstractFile* img = sff.createFile("FileName.img");
			Assert::AreEqual(sfs.addFile(img->getName(), img), 0);
			Assert::AreNotEqual(sfs.closeFile(img), 0);
		}
		TEST_METHOD(closeNotAdded) // closes a file that has not been added or opened, expects a non-zero return value
		{
			// REDIRECT COUT STREAM -- TO PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());

			SimpleFileSystem sfs;
			SimpleFileFactory sff;
			AbstractFile* img = sff.createFile("FileName.img");
			Assert::AreNotEqual(sfs.closeFile(img), 0);
		}
	};
	TEST_CLASS(simpleFileFactory) {
public:
	TEST_METHOD(createFileValid) // creates two files by calling create on the file factory, the calls should return the new file objects that are both not null
	{
		// REDIRECT COUT STREAM -- TO PROTECT AGAINST ERRORS
		streambuf* backup_out;
		backup_out = cout.rdbuf();
		stringstream ss_out;
		cout.rdbuf(ss_out.rdbuf());

		SimpleFileFactory sff;
		AbstractFile* res1 = sff.createFile("FileName.img");
		bool isNull1 = res1 == nullptr;
		Assert::IsFalse(isNull1);
		AbstractFile* res2 = sff.createFile("FileName.txt");
		bool isNull2 = res2 == nullptr;
		Assert::IsFalse(isNull2);
	}
	TEST_METHOD(createUnknownExtension) // when a bad extension is passed, the factory should pass back a nullptr
	{
		// REDIRECT COUT STREAM -- TO PROTECT AGAINST ERRORS
		streambuf* backup_out;
		backup_out = cout.rdbuf();
		stringstream ss_out;
		cout.rdbuf(ss_out.rdbuf());

		SimpleFileFactory sfs;
		AbstractFile* res1 = sfs.createFile("FileName.bla");
		bool isNull = res1 == nullptr;
		Assert::IsTrue(isNull);
	}
	};
	TEST_CLASS(basicDisplayVisitor) {
public:
	TEST_METHOD(visitTextFile) { // tests output of basic display visitor for a text file, expects the contents of the file
		std::string fileName = "FileName.txt";
		TextFile t(fileName);
		std::vector<char> v = { 'h', 'i' };
		int resWrite = t.write(v);
		// REDIRECT STD STREAM
		streambuf* backup;
		backup = cout.rdbuf();
		stringstream ss;
		cout.rdbuf(ss.rdbuf());
		AbstractFileVisitor* bdv = new BasicDisplayVisitor;
		t.accept(bdv);
		string wordShouldBe = "hi";
		string word;
		ss >> word;
		// ASSIGN COUT BACK TO STDOUT
		cout.rdbuf(backup);
		Assert::AreEqual(word, wordShouldBe);
		Assert::AreEqual(resWrite, 0);
	}
	TEST_METHOD(visitImageFile) { // tests the output the basic display visitor for an image file, expects 5 Xs
		std::string fileName = "FileName.img";
		ImageFile t(fileName);
		std::vector<char> v = { 'X', ' ', 'X', ' ', 'X', ' ', 'X',' ', 'X', '3' };
		Assert::AreEqual(t.write(v), 0);
		// REDIRECT STD STREAM
		streambuf* backup;
		backup = cout.rdbuf();
		stringstream ss;
		cout.rdbuf(ss.rdbuf());
		AbstractFileVisitor* bdv = new BasicDisplayVisitor;
		t.accept(bdv);
		string outputShouldBe = "X";
		string word;
		int count = 0;
		while (ss >> word) { // no skip ws -- wont skip white space! would have to extract one character at a time
			Assert::AreEqual(word, outputShouldBe);
			++count;
		}
		// ASSIGN COUT BACK TO STDOUT
		cout.rdbuf(backup);
		Assert::AreEqual(count, 5);
	}
	};
	TEST_CLASS(metadataDisplayVisitor) {
public:
	TEST_METHOD(visitTextFile) { // tests the output of the metadata display visitor for a text file, expects the filename, type and size to be included in the print statement
		std::string fileName = "FileName.txt";
		TextFile t(fileName);
		std::vector<char> v = { 'h', 'i' };
		Assert::AreEqual(t.write(v), 0);
		// REDIRECT STD STREAM
		streambuf* backup;
		backup = cout.rdbuf();
		stringstream ss;
		cout.rdbuf(ss.rdbuf());
		AbstractFileVisitor* bdv = new MetadataDisplayVisitor;
		t.accept(bdv);
		string word;
		std::vector<string> printedWords;
		while (ss >> word) {
			printedWords.push_back(word);
		}
		std::vector<string>::iterator it1;
		std::vector<string>::iterator it2;
		std::vector<string>::iterator it3;
		it1 = std::find(printedWords.begin(), printedWords.end(), fileName);
		bool notEqual1 = it1 == printedWords.end();
		Assert::IsFalse(notEqual1);
		it2 = std::find(printedWords.begin(), printedWords.end(), to_string(t.getSize()));
		bool notEqual2 = it2 == printedWords.end();
		Assert::IsFalse(notEqual2);
		it3 = std::find(printedWords.begin(), printedWords.end(), "text");
		bool notEqual3 = it3 == printedWords.end();
		Assert::IsFalse(notEqual3);
		// ASSIGN COUT BACK TO STDOUT
		cout.rdbuf(backup);
	}
	TEST_METHOD(visitImageFile) { // tests the output of the metadata display visitor for an image file, expects the filename, type and size to be included in the output
		std::string fileName = "FileName.img";
		ImageFile t(fileName);
		std::vector<char> v = { 'X', ' ', 'X', ' ', 'X', ' ', 'X',' ', 'X', '3' };
		Assert::AreEqual(t.write(v), 0);
		// REDIRECT STD STREAM
		streambuf* backup;
		backup = cout.rdbuf();
		stringstream ss;
		cout.rdbuf(ss.rdbuf());
		AbstractFileVisitor* bdv = new MetadataDisplayVisitor;
		t.accept(bdv);
		string word;
		std::vector<string> printedWords;
		while (ss >> word) {
			printedWords.push_back(word);
		}
		std::vector<string>::iterator it1;
		std::vector<string>::iterator it2;
		std::vector<string>::iterator it3;
		it1 = std::find(printedWords.begin(), printedWords.end(), fileName);
		bool notEqual1 = it1 == printedWords.end();
		Assert::IsFalse(notEqual1);
		it2 = std::find(printedWords.begin(), printedWords.end(), to_string(t.getSize()));
		bool notEqual2 = it2 == printedWords.end();
		Assert::IsFalse(notEqual2);
		it3 = std::find(printedWords.begin(), printedWords.end(), "image");
		bool notEqual3 = it3 == printedWords.end();
		Assert::IsFalse(notEqual3);
		// ASSIGN COUT BACK TO STDOUT
		cout.rdbuf(backup);
	}
	};
	TEST_CLASS(passwordProxy)
	{
	public:

		TEST_METHOD(contstructor) // we expect the name and size of the password proxy to match that of the text file it is assigned with
		{
			// REDIRECT COUT STREAM -- TO PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// CREATE FILE AND FILE PROXY
			std::string fileName = "file1.txt";
			AbstractFile* realfile = new TextFile(fileName);
			string password = "r4A3dg";
			PasswordProxy* pp = new PasswordProxy(realfile, password);
			unsigned int fileSize = 0;
			// EXPECTATIONS FOR CONSTRUCTION
			Assert::AreEqual(pp->getName(), fileName);
			Assert::AreEqual(pp->getSize(), fileSize);
			Assert::AreEqual(realfile->getName(), fileName);
			Assert::AreEqual(realfile->getSize(), fileSize);
		}
		TEST_METHOD(writeValidPassword) // with a valid password, we would expect the size of the pasword proxy and realfile to be updated and return the same value (the size of the vector)
		{
			// CREATE FILE AND FILE PROXY
			std::string fileName = "file1.txt";
			AbstractFile* realfile = new TextFile(fileName);
			string password = "r4A3dg";
			PasswordProxy* pp = new PasswordProxy(realfile, password);
			vector<char> v = { 'h', 'i' };
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// SET UP PASSWORD STREAM
			ss_in << password;
			// EXPECTATIONS FOR FUNCTION -- VALID PASSWORD
			Assert::AreEqual(pp->write(v), 0);
			Assert::AreEqual(pp->getSize(), static_cast<unsigned int>(v.size()));
			Assert::AreEqual(realfile->getSize(), static_cast<unsigned int>(v.size()));
			// ASSIGN COUT BACK TO STDOUT
			cout.rdbuf(backup_out);
			// ASSIGN CIN BACK TO STDIN
			cin.rdbuf(backup_in);
		}
		TEST_METHOD(writeInvalidPassword) // if an incorrect password is given, write should not execute and the size of both the password proxy and the real file should remain 0
		{
			// CREATE FILE AND FILE PROXY
			std::string fileName = "file1.txt";
			AbstractFile* realfile = new TextFile(fileName);
			string password = "r4A3dg";
			PasswordProxy* pp = new PasswordProxy(realfile, password);
			vector<char> v = { 'h', 'i' };
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// SET UP PASSWORD STREAM
			string wrongPassword = "s9K3qL";
			ss_in << wrongPassword;
			// EXPECTATIONS FOR FUNCTION -- INVALID PASSWORD
			Assert::AreNotEqual(pp->write(v), 0);
			Assert::AreEqual(pp->getSize(), static_cast<unsigned int>(0));
			Assert::AreEqual(realfile->getSize(), static_cast<unsigned int>(0));
			// ASSIGN COUT BACK TO STDOUT
			cout.rdbuf(backup_out);
			// ASSIGN CIN BACK TO STDIN
			cin.rdbuf(backup_in);
		}
		TEST_METHOD(appendValidPassword) // we expect that if a good password is given for write and for append, then the proxy and real file should both only have their sizes updated accordingly 
		{
			// CREATE FILE AND FILE PROXY
			std::string fileName = "file1.txt";
			AbstractFile* realfile = new TextFile(fileName);
			string password = "r4A3dg";
			PasswordProxy* pp = new PasswordProxy(realfile, password);
			vector<char> v = { 'h', 'i' };
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// SET UP PASSWORD STREAM
			ss_in << password + '\n' + password;
			// EXPECTATIONS FOR FIRST FUNCTION -- VALID PASSWORD
			Assert::AreEqual(pp->write(v), 0);
			Assert::AreEqual(pp->getSize(), static_cast<unsigned int>(v.size()));
			Assert::AreEqual(realfile->getSize(), static_cast<unsigned int>(v.size()));
			unsigned int fileSize = pp->getSize();
			// EXPECTATIONS FOR SECOND FUNCTION -- INVALID PASSWORD
			Assert::AreEqual(pp->append(v), 0);
			Assert::AreEqual(pp->getSize(), static_cast<unsigned int>(fileSize + v.size()));
			Assert::AreEqual(realfile->getSize(), static_cast<unsigned int>(fileSize + v.size()));
			// ASSIGN COUT BACK TO STDOUT
			cout.rdbuf(backup_out);
			// ASSIGN CIN BACK TO STDIN
			cin.rdbuf(backup_in);

		}
		TEST_METHOD(appendInvalidPassword) //  we expect that if a good password is given for write, but an incorrect password is given for append, then the proxy and real file should both only have their sizes updated from the first write
		{
			// CREATE FILE AND FILE PROXY
			std::string fileName = "file1.txt";
			AbstractFile* realfile = new TextFile(fileName);
			string password = "r4A3dg";
			PasswordProxy* pp = new PasswordProxy(realfile, password);
			vector<char> v = { 'h', 'i' };
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// SET UP PASSWORD STREAM
			string wrongPassword = "a5lsdIK3";
			ss_in << password + '\n' + wrongPassword;
			// EXPECTATIONS FOR FIRST FUNCTION -- VALID PASSWORD
			Assert::AreEqual(pp->write(v), 0);
			Assert::AreEqual(pp->getSize(), static_cast<unsigned int>(v.size()));
			Assert::AreEqual(realfile->getSize(), static_cast<unsigned int>(v.size()));
			unsigned int fileSize = pp->getSize();
			// EXPECTATIONS FOR SECOND FUNCTION -- INVALID PASSWORD
			Assert::AreNotEqual(pp->append(v), 0);
			Assert::AreEqual(pp->getSize(), static_cast<unsigned int>(fileSize));
			Assert::AreEqual(realfile->getSize(), static_cast<unsigned int>(fileSize));
			// ASSIGN COUT BACK TO STDOUT
			cout.rdbuf(backup_out);
			// ASSIGN CIN BACK TO STDIN
			cin.rdbuf(backup_in);

		}
		TEST_METHOD(readValidPassword) // we would expect to see the effects of writing to the proxy with a valid password in the content returned by the read function -- when a valid password is given -- this should also match the read content of the real file
		{
			// CREATE FILE AND FILE PROXY
			std::string fileName = "file1.txt";
			AbstractFile* realfile = new TextFile(fileName);
			string password = "r4A3dg";
			PasswordProxy* pp = new PasswordProxy(realfile, password);
			vector<char> v = { 'h', 'i' };
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// SET UP PASSWORD STREAM
			ss_in << password + '\n' + password;
			// EXPECTATIONS FOR FIRST FUNCTION -- VALID PASSWORD
			Assert::AreEqual(pp->write(v), 0);
			Assert::AreEqual(pp->getSize(), static_cast<unsigned int>(v.size()));
			Assert::AreEqual(realfile->getSize(), static_cast<unsigned int>(v.size()));
			// EXPECTATIONS FOR SECOND FUNCTION -- VALID PASSWORD
			std::vector<char> contentsPP = pp->read();
			Assert::AreEqual(contentsPP.size(), v.size());
			for (size_t i = 0; i < contentsPP.size(); ++i) {
				Assert::AreEqual(v[i], contentsPP[i]);
			}
			std::vector<char> contentsRF = realfile->read();
			Assert::AreEqual(contentsRF.size(), v.size());
			for (size_t i = 0; i < contentsRF.size(); ++i) {
				Assert::AreEqual(v[i], contentsRF[i]);
			}
			// ASSIGN COUT BACK TO STDOUT
			cout.rdbuf(backup_out);
			// ASSIGN CIN BACK TO STDIN
			cin.rdbuf(backup_in);
		}
		TEST_METHOD(readInvalidPassword) // when an invalid password is given for the read function, then we would expect the contents vector returned to be empty, however the original file, that does not require a password to read, should be updated from the valid write call
		{
			// CREATE FILE AND FILE PROXY
			std::string fileName = "file1.txt";
			AbstractFile* realfile = new TextFile(fileName);
			string password = "r4A3dg";
			PasswordProxy* pp = new PasswordProxy(realfile, password);
			vector<char> v = { 'h', 'i' };
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// SET UP PASSWORD STREAM
			string wrongPassword = "a5lsdIK3";
			ss_in << password + '\n' + wrongPassword;
			// EXPECTATIONS FOR FIRST FUNCTION -- VALID PASSWORD
			Assert::AreEqual(pp->write(v), 0);
			Assert::AreEqual(pp->getSize(), static_cast<unsigned int>(v.size()));
			Assert::AreEqual(realfile->getSize(), static_cast<unsigned int>(v.size()));
			// EXPECTATIONS FOR SECOND FUNCTION -- INVALID PASSWORD
			std::vector<char> contentsPP = pp->read();
			Assert::AreEqual(contentsPP.size(), static_cast<size_t>(0));
			std::vector<char> contentsRF = realfile->read();
			Assert::AreEqual(contentsRF.size(), static_cast<size_t>(v.size()));
			// ASSIGN COUT BACK TO STDOUT
			cout.rdbuf(backup_out);
			// ASSIGN CIN BACK TO STDIN
			cin.rdbuf(backup_in);
		}
		TEST_METHOD(acceptValidPassword) // we would expect "hi" -- the contents of the file -- to be printed when a valid password is given for accept
		{
			// CREATE FILE AND FILE PROXY
			std::string fileName = "file1.txt";
			AbstractFile* realfile = new TextFile(fileName);
			string password = "r4A3dg";
			PasswordProxy* pp = new PasswordProxy(realfile, password);
			vector<char> v = { 'h', 'i' };
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// SET UP PASSWORD STREAM
			ss_in << password + '\n' + password;
			// EXPECTATIONS FOR FIRST FUNCTION -- VALID PASSWORD
			Assert::AreEqual(pp->write(v), 0);
			Assert::AreEqual(pp->getSize(), static_cast<unsigned int>(v.size()));
			Assert::AreEqual(realfile->getSize(), static_cast<unsigned int>(v.size()));
			// EXPECTATIONS FOR SECOND FUNCTION -- VALID PASSWORD
			BasicDisplayVisitor* bdv = new BasicDisplayVisitor;
			pp->accept(bdv);
			string wordShouldBe = "hi";
			string word;
			vector<string> printedWords;
			while (ss_out >> word) {
				printedWords.push_back(word);
			}
			std::vector<string>::iterator it1;
			it1 = std::find(printedWords.begin(), printedWords.end(), wordShouldBe);
			bool isEqual = it1 == printedWords.end();
			Assert::IsFalse(isEqual);
			// ASSIGN COUT BACK TO STDOUT
			cout.rdbuf(backup_out);
			// ASSIGN CIN BACK TO STDIN
			cin.rdbuf(backup_in);
		}
		TEST_METHOD(acceptInvalidPassword) // we do not expect "hi" (the contents of the file) to be printed when an invalid password is given for accept
		{
			// CREATE FILE AND FILE PROXY
			std::string fileName = "file1.txt";
			AbstractFile* realfile = new TextFile(fileName);
			string password = "r4A3dg";
			PasswordProxy* pp = new PasswordProxy(realfile, password);
			vector<char> v = { 'h', 'i' };
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// SET UP PASSWORD STREAM
			string wrongPassword = "a5lsdIK3";
			ss_in << password + '\n' + wrongPassword;
			// EXPECTATIONS FOR FIRST FUNCTION -- VALID PASSWORD
			Assert::AreEqual(pp->write(v), 0);
			Assert::AreEqual(pp->getSize(), static_cast<unsigned int>(v.size()));
			Assert::AreEqual(realfile->getSize(), static_cast<unsigned int>(v.size()));
			// EXPECTATIONS FOR SECOND FUNCTION -- INVALID PASSWORD
			BasicDisplayVisitor* bdv = new BasicDisplayVisitor;
			pp->accept(bdv);
			string wordShouldBe = "hi";
			string word;
			vector<string> printedWords;
			while (ss_out >> word) {
				printedWords.push_back(word);
			}
			std::vector<string>::iterator it1;
			it1 = std::find(printedWords.begin(), printedWords.end(), wordShouldBe);
			bool isEqual = it1 == printedWords.end();
			Assert::IsTrue(isEqual);
			// ASSIGN COUT BACK TO STDOUT
			cout.rdbuf(backup_out);
			// ASSIGN CIN BACK TO STDIN
			cin.rdbuf(backup_in);
		}
	};
	TEST_CLASS(commandPrompt) {
		TEST_METHOD(addAndListCommands) { // ensures the add command and list command are working correctly, we would expect the command name for the command we added (in this case the testCommand) to be printed out by the listCommand() method
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			CommandPrompt cp;
			cp.setFileSystem(sfs);
			cp.setFileFactory(sff);
			// ADD COMMAND -- TEST COMMAND
			CommandTest* ct = new CommandTest(sfs);
			string commandname = "test";
			Assert::AreEqual(cp.addCommand(commandname, ct), 0);
			// REDIRECT STD STREAM
			streambuf* backup;
			backup = cout.rdbuf();
			stringstream ss;
			cout.rdbuf(ss.rdbuf());
			// LIST COMMANDS
			cp.listCommands();
			string word;
			std::vector<string> printedWords;
			while (ss >> word) {
				printedWords.push_back(word);
			}
			// EXPECTATION -- COMMAND NAME SHOULD BE PRINTED TO COUT
			Assert::AreEqual(static_cast<int>(printedWords.size()), 1);
			Assert::AreEqual(printedWords[0], commandname);
			// ASSIGN COUT BACK TO STDOUT
			cout.rdbuf(backup);
		}
		TEST_METHOD(prompt) { // checks prompt method, ensures that prompt returns what is typed in the terminal by the filesystem user
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			CommandPrompt* cp = new CommandPrompt;
			cp->setFileSystem(sfs);
			cp->setFileFactory(sff);
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// MIMIC USER INPUT -- SAMPLE COMMAND FOR TOUCH
			string input = "touch file.txt";
			ss_in << input;
			// EXPECTATION -- PROMPT SHOULD RETURN THE USER INPUT
			string promptResponse = cp->prompt();
			Assert::AreEqual(promptResponse, input);
			// ASSIGN COUT BACK TO STDOUT
			cout.rdbuf(backup_out);
			// ASSIGN CIN BACK TO STDIN
			cin.rdbuf(backup_in);
		}
		TEST_METHOD(runQuit) { // ensures that the run method ends when quit by the user (entering q), we would expect a non-zero return value
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			CommandPrompt* cp = new CommandPrompt;
			cp->setFileSystem(sfs);
			cp->setFileFactory(sff);
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// MIMC USER INPUT -- QUITTING COMMAND -- 'Q'
			string input = "q";
			ss_in << input;
			// CAPUTRE RETURN VALUE -- Q SHOULD END THE RUN LOOP
			int response = cp->run();
			Assert::AreNotEqual(response, 0);
			// ASSIGN COUT BACK TO STDOUT
			cout.rdbuf(backup_out);
			// ASSIGN CIN BACK TO STDIN
			cin.rdbuf(backup_in);
		}
		TEST_METHOD(runHelp) { // we would expect help to list all of the commands that have been added, in this case only the test command should be printed
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			CommandPrompt* cp = new CommandPrompt;
			cp->setFileSystem(sfs);
			cp->setFileFactory(sff);
			// ADD COMMAND -- COMMAND TEST
			CommandTest* ct = new CommandTest(sfs);
			string commandname = "test";
			Assert::AreEqual(cp->addCommand(commandname, ct), 0);
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// MIMIC USER INPUT -- HELP & QUIT -- USE QUIT TO END RUN 
			string input = "help\nq";
			ss_in << input;
			int response = cp->run();
			Assert::AreNotEqual(response, 0);
			// CAPTURE COUT DATA
			string word;
			std::vector<string> printedWords;
			while (ss_out >> word) {
				printedWords.push_back(word);
			}
			// EXPECTATION -- PROGRAM SHOULD PRINT ALL COMMANDS
			std::vector<string>::iterator it1;
			it1 = std::find(printedWords.begin(), printedWords.end(), commandname);
			bool notEqual1 = it1 == printedWords.end();
			Assert::IsFalse(notEqual1);
			// ASSIGN COUT BACK TO STDOUT
			cout.rdbuf(backup_out);
			// ASSIGN CIN BACK TO STDIN
			cin.rdbuf(backup_in);
		}
	};
	TEST_CLASS(commandTest) {
		TEST_METHOD(commandDisplayInfo) { // uses the CommandTest object to check that help + command name will successfully call the displayInfo() method for the correct command type
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			CommandPrompt* cp = new CommandPrompt;
			cp->setFileSystem(sfs);
			cp->setFileFactory(sff);
			// ADD COMMAND -- COMMAND TEST
			CommandTest* ct = new CommandTest(sfs);
			string commandname = "test";
			Assert::AreEqual(cp->addCommand(commandname, ct), 0);
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// MIMIC USER INPUT -- SPECIFIC HELP COMMAND
			string input = "help test\nq\n";
			ss_in << input;
			int response = cp->run();
			Assert::AreNotEqual(response, 0);
			string word;
			std::vector<string> printedWords;
			while (ss_out >> word) {
				printedWords.push_back(word);
			}
			/// EXPECTATION -- DISPLAY INFO OF OUR COMMAND TEST SHOULD BE PRINTED TO COUT
			std::vector<string>::iterator it1;
			string expectedString = "aRandomStringz"; // MATCHES GIVEN COMMAND TEST FILE
			it1 = std::find(printedWords.begin(), printedWords.end(), expectedString);
			bool notEqual1 = it1 == printedWords.end();
			Assert::IsFalse(notEqual1);
			// ASSIGN COUT BACK TO STDOUT
			cout.rdbuf(backup_out);
			// ASSIGN CIN BACK TO STDIN
			cin.rdbuf(backup_in);
		}
		TEST_METHOD(commandExecuteNoInfo) { //  uses the CommandTest object to check passing variables to execute - expects no inputs to be passed as the parameter in this case
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			CommandPrompt* cp = new CommandPrompt;
			cp->setFileSystem(sfs);
			cp->setFileFactory(sff);
			// ADD COMMAND
			CommandTest* ct = new CommandTest(sfs);
			string commandname = "test";
			Assert::AreEqual(cp->addCommand(commandname, ct), 0);
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// MIMIC USER INPUT -- COMMAND TEST EXECUTE 
			string input = "test\nq\n";
			ss_in << input;
			// CAPTURE RUN OUTPUT
			int response = cp->run();
			Assert::AreNotEqual(response, 0);
			string word;
			std::vector<string> printedWords;
			while (ss_out >> word) {
				printedWords.push_back(word);
			}
			// EXPECTATION -- NOTHING SHOULD BE PASSED TO THE FUNCTION
			std::vector<string>::iterator it1;
			string expectedOutput = "command-test-no-info";
			it1 = std::find(printedWords.begin(), printedWords.end(), expectedOutput);
			bool notEqual1 = it1 == printedWords.end();
			Assert::IsFalse(notEqual1);
			// ASSIGN COUT BACK TO STDOUT
			cout.rdbuf(backup_out);
			// ASSIGN CIN BACK TO STDIN
			cin.rdbuf(backup_in);
		}
		TEST_METHOD(commandExecuteOneInput) { //  uses the CommandTest object to check passing variables to execute - expects one input, foo, to be passed to the function
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			CommandPrompt* cp = new CommandPrompt;
			cp->setFileSystem(sfs);
			cp->setFileFactory(sff);
			// ADD COMMAND
			CommandTest* ct = new CommandTest(sfs);
			string commandname = "test";
			Assert::AreEqual(cp->addCommand(commandname, ct), 0);
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// MIMIC USER INPUT
			string input = "test foo\nq\n";
			ss_in << input;
			int response = cp->run();
			Assert::AreNotEqual(response, 0);
			string word;
			std::vector<string> printedWords;
			while (ss_out >> word) {
				printedWords.push_back(word);
			}
			// EXPECTATION -- THE SECOND PARAMETER SHOULD BE PRINTED TO COUT
			std::vector<string>::iterator it1;
			string expectedOutput = "foo";
			it1 = std::find(printedWords.begin(), printedWords.end(), expectedOutput);
			bool notEqual1 = it1 == printedWords.end();
			Assert::IsFalse(notEqual1);
			// ASSIGN COUT BACK TO STDOUT
			cout.rdbuf(backup_out);
			// ASSIGN CIN BACK TO STDIN
			cin.rdbuf(backup_in);
		}
		TEST_METHOD(commandExecuteMoreInputs) { // uses the CommandTest object to check passing variables to execute - expects two inputs to be passed 
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			CommandPrompt* cp = new CommandPrompt;
			cp->setFileSystem(sfs);
			cp->setFileFactory(sff);
			// ADD COMMAND
			CommandTest* ct = new CommandTest(sfs);
			string commandname = "test";
			Assert::AreEqual(cp->addCommand(commandname, ct), 0);
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// MIMIC USER INPUT
			string input = "test foo moo\nq\n";
			ss_in << input;
			int response = cp->run();
			Assert::AreNotEqual(response, 0);
			string word;
			std::vector<string> printedWords;
			while (ss_out >> word) {
				printedWords.push_back(word);
			}
			// EXPECTATION -- ALL PARAMETERS SHOULD BE PRINTED TO COUT
			std::vector<string>::iterator it1;
			string expectedOutput = "foo:moo";
			it1 = std::find(printedWords.begin(), printedWords.end(), expectedOutput);
			bool notEqual1 = it1 == printedWords.end();
			Assert::IsFalse(notEqual1);
			// ASSIGN COUT BACK TO STDOUT
			cout.rdbuf(backup_out);
			// ASSIGN CIN BACK TO STDIN
			cin.rdbuf(backup_in);
		}
	};
	TEST_CLASS(touchCommand) {
		TEST_METHOD(execute) { // confirms that execute, when passed a valid filename, will create and add a file in the filesystem
			// REDIRECT COUT STREAM -- TO PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			// CREATE COMMAND
			TouchCommand* tc = new TouchCommand(sfs, sff);
			// CALL EXECUTE ON TOUCH COMMAND
			string filename = "file.txt";
			Assert::AreEqual(tc->execute(filename), 0);
			// EXPECTATION -- FILE EXISTS IN THE FILE SYSTEM
			AbstractFile* file = sfs->openFile(filename);
			bool isNull = file == nullptr;
			Assert::IsFalse(isNull);
			Assert::AreEqual(filename, file->getName());
		}
		
		TEST_METHOD(executePasswordProxy) { // confirms that execute, when passed a valid filename with a password, will create and add a password proxy file to the filesystem
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			// CREATE COMMAND
			TouchCommand* tc = new TouchCommand(sfs, sff);
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// MIMIC USER INPUT
			string password = "Jdi320dD";
			string wrongpassword = "DKR32sdfRR";
			string input = password + "\n" + password + "\n" + wrongpassword + "\n" + password;
			ss_in << input;
			// CALL EXECUTE ON TOUCH COMMAND
			string filename = "file.txt";
			Assert::AreEqual(tc->execute(filename + " -p"), 0);
			// EXPECTATION -- FILE EXISTS IN THE FILE SYSTEM
			AbstractFile* file = sfs->openFile(filename);
			bool isNull = file == nullptr;
			Assert::IsFalse(isNull);
			Assert::AreEqual(filename, file->getName());
			// EXPECTATION -- PASSWORD REQUIRED FOR WRITE -- GIVEN VALID PASSWORD
			vector<char> v = { 'h', 'i' };
			Assert::AreEqual(file->write(v), 0);
			Assert::AreEqual(file->getSize(), static_cast<unsigned int>(v.size()));
			// EXPECTATION -- PASSWORD REQUIRED FOR READ -- GIVEN INVALID PASSWORD
			vector<char> contents1 = file->read();
			Assert::AreEqual(contents1.size(), static_cast<size_t>(0));
			// EXPECTATION -- PASSWORD REQUIRED FOR READ -- GIVEN VALID PASSWORD
			vector<char> contents2 = file->read();
			Assert::AreEqual(contents2.size(), v.size());
			// ASSIGN CIN BACK TO STDIN
			cin.rdbuf(backup_in);
		}
		
		TEST_METHOD(executeInvalidExtension) { // confirms that execute, when passed a valid filename, will create and add a file in the filesystem
			// REDIRECT COUT STREAM -- TO PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			// CREATE COMMAND
			TouchCommand* tc = new TouchCommand(sfs, sff);
			// CALL EXECUTE ON TOUCH COMMAND
			string filename = "file.foo";
			Assert::AreNotEqual(tc->execute(filename), 0);
			// EXPECTATION -- FILE DOES NOT EXISTS IN THE FILE SYSTEM
			AbstractFile* file = sfs->openFile(filename);
			bool isNull = file == nullptr;
			Assert::IsTrue(isNull);
		}
		TEST_METHOD(executeFileAlreadyExists) { // confirms that execute, when passed a valid filename, will create and add a file in the filesystem
			// REDIRECT COUT STREAM -- TO PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			// CREATE COMMAND
			TouchCommand* tc = new TouchCommand(sfs, sff);
			// CALL EXECUTE ON TOUCH COMMAND
			string filename = "file.txt";
			Assert::AreEqual(tc->execute(filename), 0);
			Assert::AreNotEqual(tc->execute(filename), 0);
			// EXPECTATION -- FILE DOES EXISTS IN THE FILE SYSTEM - FIRST EXECUTION
			AbstractFile* file = sfs->openFile(filename);
			bool isNull = file == nullptr;
			Assert::IsFalse(isNull);
		}
	};

	
	TEST_CLASS(removeCommand) {
		TEST_METHOD(execute) { // confirms that execute, when passed a valid filename, will remove the given file from the filesystem -- removing the file again should fail, adding the file again should pass
			// REDIRECT COUT STREAM -- TO PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			// ADD FILES
			string filename1 = "file.txt";
			string filename2 = "file.img";
			Assert::AreEqual(sfs->addFile(filename1, sff->createFile(filename1)), 0);
			Assert::AreEqual(sfs->addFile(filename2, sff->createFile(filename2)), 0);
			// CREATE COMMAND
			RemoveCommand* rc = new RemoveCommand(sfs);
			// CALL EXECUTE ON REMOVE COMMAND
			Assert::AreEqual(rc->execute(filename2), 0);
			// EXPECTATION -- TEXT FILE EXISTS IN THE FILE SYSTEM
			AbstractFile* file1 = sfs->openFile(filename1);
			bool isNull1 = file1 == nullptr;
			Assert::IsFalse(isNull1);
			Assert::AreEqual(filename1, file1->getName());
			// EXPECTATION -- IMAGE FILE REMOVED IN THE FILE SYSTEM
			AbstractFile* file2 = sfs->openFile(filename2);
			bool isNull2 = file2 == nullptr;
			Assert::IsTrue(isNull2);
			// CLOSE TEXT FILE
			Assert::AreEqual(sfs->closeFile(file1), 0);
			// CHECK FILES IN SYSTEM USING GETFILENAMES() FUCNTION
			set<string> files = sfs->getFileNames();
			Assert::AreEqual(files.size(), static_cast<size_t>(1));
			// EXPECTATION -- TEXT FILE EXISTS IN THE FILE SYSTEM
			std::set<std::string>::iterator it1 = files.find(filename1);
			bool found1 = it1 == files.end();
			Assert::IsFalse(found1);
			// EXPECTATION -- IMAGE FILE REMOVED IN THE FILE SYSTEM
			std::set<std::string>::iterator it2 = files.find(filename2);
			bool found2 = it2 == files.end();
			Assert::IsTrue(found2);
			// RE-ADD FILE
			Assert::AreEqual(sfs->addFile(filename2, sff->createFile(filename2)), 0);
			set<string> files2 = sfs->getFileNames();
			Assert::AreEqual(files2.size(), static_cast<size_t>(2));
			// EXPECTATION -- IMAGE FILE EXISTS IN THE FILE SYSTEM - OPEN FILE CHEC AND GETFILENAMES CHECK
			std::set<std::string>::iterator it3 = files2.find(filename2);
			bool found3 = it3 == files2.end();
			Assert::IsFalse(found3);
			AbstractFile* file3 = sfs->openFile(filename2);
			bool isNull3 = file3 == nullptr;
			Assert::IsFalse(isNull3);
		}
		TEST_METHOD(executeFileOpen) { // confirms that execute, when passed a valid filename for a file that is open, execute will return an error and filesystem is untouched, so we expect to be able to close it
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			// ADD FILE
			string filename1 = "file.txt";
			Assert::AreEqual(sfs->addFile(filename1, sff->createFile(filename1)), 0);
			// OPEN FILE
			AbstractFile* file1 = sfs->openFile(filename1);
			bool isNull = file1 == nullptr;
			Assert::IsFalse(isNull);
			Assert::AreEqual(filename1, file1->getName());
			// CREATE COMMAND
			RemoveCommand* rc = new RemoveCommand(sfs);
			// CALL EXECUTE ON REMOVE COMMAND
			Assert::AreNotEqual(rc->execute(filename1), 0);
			// EXPECTATION -- TEXT FILE EXISTS IN THE FILE SYSTEM -- SO WE CAN CLOSE IT
			// CLOSE FILE
			Assert::AreEqual(sfs->closeFile(file1), 0);
		}
	};
	TEST_CLASS(lSCommand) {
		TEST_METHOD(getAllFiles) { // condirms set returned by getFileNames() matches the file system
			// REDIRECT COUT STREAM -- TO PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			// ADD FILES
			string filename1 = "file.txt";
			string filename2 = "file.img";
			Assert::AreEqual(sfs->addFile(filename1, sff->createFile(filename1)), 0);
			Assert::AreEqual(sfs->addFile(filename2, sff->createFile(filename2)), 0);
			// CHECK FILES IN SYSTEM USING GETFILENAMES() FUCNTION
			set<string> files = sfs->getFileNames();
			Assert::AreEqual(files.size(), static_cast<size_t>(2));
			// EXPECTATION -- TEXT FILE EXISTS IN THE FILE SYSTEM
			std::set<std::string>::iterator it1 = files.find(filename1);
			bool found1 = it1 == files.end();
			Assert::IsFalse(found1);
			// EXPECTATION -- IMAGE FILE EXISTS IN THE FILE SYSTEM
			std::set<std::string>::iterator it2 = files.find(filename2);
			bool found2 = it2 == files.end();
			Assert::IsFalse(found2);
		}
		TEST_METHOD(nooption) {
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			// ADD FILES
			string filename1 = "file.txt";
			string filename2 = "file.img";
			string filename3 = "adifferentfile.txt";
			Assert::AreEqual(sfs->addFile(filename1, sff->createFile(filename1)), 0);
			Assert::AreEqual(sfs->addFile(filename2, sff->createFile(filename2)), 0);
			Assert::AreEqual(sfs->addFile(filename3, sff->createFile(filename3)), 0);
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// execute ls
			AbstractCommand* ls = new LSCommand(sfs);
			Assert::AreEqual(ls->execute(""), 0);
			// check output
			string firstLine;
			string secondLine;
			// ensure 2 lines of output
			bool extractSuccessful = false;
			if (getline(ss_out, firstLine)) {
				extractSuccessful = true;
			}
			Assert::IsTrue(extractSuccessful);
			extractSuccessful = false;
			if (getline(ss_out, secondLine)) {
				extractSuccessful = true;
			}
			Assert::IsTrue(extractSuccessful);
			string firstFile;
			string secondFile;
			istringstream iss(firstLine);
			iss >> firstFile;
			iss >> secondFile;
			string thirdFile;
			istringstream iss2(secondLine);
			iss2 >> thirdFile;
			string expectedFirst = "adifferentfile.txt";
			string expectedSecond = "file.img";
			string expectedThird = "file.txt";
			Assert::AreEqual(firstFile, expectedFirst);
			Assert::AreEqual(secondFile, expectedSecond);
			Assert::AreEqual(thirdFile, expectedThird);
		}
		
		TEST_METHOD(metadata) {
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			// ADD FILES
			string filename1 = "file.txt";
			string filename2 = "file.img";
			string filename3 = "adifferentfile.txt";
			Assert::AreEqual(sfs->addFile(filename1, sff->createFile(filename1)), 0);
			Assert::AreEqual(sfs->addFile(filename2, sff->createFile(filename2)), 0);
			Assert::AreEqual(sfs->addFile(filename3, sff->createFile(filename3)), 0);
			AbstractFile* f1 = sfs->openFile(filename1);
			AbstractFile* f2 = sfs->openFile(filename2);
			f1->write({ 'h','i' });
			int f1Size = f1->getSize();
			Assert::AreEqual(f1Size, 2);
			f2->write({ 'X',' ', ' ', 'X', '2' });
			int f2Size = f2->getSize();
			Assert::AreEqual(f2Size, 4);
			int f3Size = 0;
			sfs->closeFile(f1);
			sfs->closeFile(f2);
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// execute ls
			AbstractCommand* ls = new LSCommand(sfs);
			Assert::AreEqual(ls->execute("-m"), 0);
			string line1;
			string line2;
			string line3;
			getline(ss_out, line1);
			getline(ss_out, line2);
			getline(ss_out, line3);
			istringstream iss(line1);
			istringstream iss2(line2);
			istringstream iss3(line3);
			string f1Name;
			string f2Name;
			string f3Name;
			string f1Type;
			string f2Type;
			string f3Type;
			int sizeF1;
			int sizeF2;
			int sizeF3;
			iss >> f1Name >> f1Type >> sizeF1;
			iss2 >> f2Name >> f2Type >> sizeF2;
			iss3 >> f3Name >> f3Type >> sizeF3;
			Assert::AreEqual(f1Name, filename3);
			Assert::AreEqual(f2Name, filename2);
			Assert::AreEqual(f3Name, filename1);
			string txtType = "text";
			string imgType = "image";
			Assert::AreEqual(f1Type, txtType);
			Assert::AreEqual(f2Type, imgType);
			Assert::AreEqual(f3Type, txtType);
			Assert::AreEqual(sizeF1, f3Size);
			Assert::AreEqual(sizeF2, f2Size);
			Assert::AreEqual(sizeF3, f1Size);
			// did the files get closed?
			f1 = sfs->openFile(filename1);
			f2 = sfs->openFile(filename2);
			AbstractFile* f3 = sfs->openFile(filename3);
			bool allOpen = false;
			if (f1 != nullptr && f2 != nullptr && f3 != nullptr) {
				allOpen = true;
			}
			Assert::IsTrue(allOpen);
		} 
	}; 
	TEST_CLASS(catCommand) {
		TEST_METHOD(executeTextFileNoAppendSaving) { // test executing cat with no append option and saving input to a text file
			// SET UP FILE SYSTEM
			// REDIRECT COUT STREAM -- PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			// ADD FILES
			string filename = "file.txt";
			AbstractFile* file = new TextFile(filename);
			Assert::AreEqual(sfs->addFile(filename, file), 0);
			// INITIALIZE FILE CONTENTS
			vector<char> origContents = { 'f','o','o' };
			string origContentsStr(origContents.begin(), origContents.end());
			Assert::AreEqual(file->write(origContents), 0);
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// MIMIC USER INPUT 
			string userInput = "hello world";
			string saveOption = "\n:wq\n";
			ss_in << userInput + saveOption;
			// CREATE AND EXECUTE COMMAND
			CatCommand* cc = new CatCommand(sfs);
			string executeInput = filename;
			Assert::AreEqual(cc->execute(executeInput), 0);
			// EXPECTATION -- CONTENTS MATCH
			vector<char> contents = file->read();
			string contentsStr(contents.begin(), contents.end());
			Assert::AreEqual(userInput, contentsStr);
			// ASSIGN CIN BACK TO STDIN
			cin.rdbuf(backup_in);
		}
		TEST_METHOD(executeTextFileNoAppendSavingMultipleLines) { // test executing cat with no append option and saving input with multiple lines to a text file
			// REDIRECT COUT STREAM -- PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			// ADD FILES
			string filename = "file.txt";
			AbstractFile* file = new TextFile(filename);
			Assert::AreEqual(sfs->addFile(filename, file), 0);
			// INITIALIZE FILE CONTENTS
			vector<char> origContents = { 'f','o','o' };
			string origContentsStr(origContents.begin(), origContents.end());
			Assert::AreEqual(file->write(origContents), 0);
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// MIMIC USER INPUT 
			string userInput = "hello\nworld\nmultiple\nlines";
			string saveOption = "\n:wq\n";
			ss_in << userInput + saveOption;
			// CREATE AND EXECUTE COMMAND
			CatCommand* cc = new CatCommand(sfs);
			string executeInput = filename;
			Assert::AreEqual(cc->execute(executeInput), 0);
			// EXPECTATION -- CONTENTS MATCH
			vector<char> contents = file->read();
			string contentsStr(contents.begin(), contents.end());
			Assert::AreEqual(userInput, contentsStr);
			// ASSIGN CIN BACK TO STDIN
			cin.rdbuf(backup_in);
		}
		TEST_METHOD(executeTextFileNoAppendNoSaving) { // test executing cat with no append option and without saving input to a text file
			// REDIRECT COUT STREAM -- PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			// ADD FILES
			string filename = "file.txt";
			AbstractFile* file = new TextFile(filename);
			Assert::AreEqual(sfs->addFile(filename, file), 0);
			// INITIALIZE FILE CONTENTS
			vector<char> origContents = { 'f','o','o' };
			string origContentsStr(origContents.begin(), origContents.end());
			Assert::AreEqual(file->write(origContents), 0);
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// MIMIC USER INPUT 
			string userInput = "hello world";
			string saveOption = "\n:q\n";
			ss_in << userInput + saveOption;
			// CREATE AND EXECUTE COMMAND
			CatCommand* cc = new CatCommand(sfs);
			string executeInput = filename;
			Assert::AreEqual(cc->execute(executeInput), 0);
			// EXPECTATION -- CONTENTS UNTOUCHED
			vector<char> contents = file->read();
			string contentsStr(contents.begin(), contents.end());
			Assert::AreEqual(origContentsStr, contentsStr);
			// ASSIGN CIN BACK TO STDIN
			cin.rdbuf(backup_in);
		}
		TEST_METHOD(executeTextFileAppendSaving) { // test executing cat with append option and saving input to a text file
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			// ADD FILES
			string filename = "file.txt";
			AbstractFile* file = new TextFile(filename);
			Assert::AreEqual(sfs->addFile(filename, file), 0);
			// INITIALIZE FILE CONTENTS
			vector<char> origContents = { 'f','o','o' };
			string origContentsStr(origContents.begin(), origContents.end());
			Assert::AreEqual(file->write(origContents), 0);
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// MIMIC USER INPUT 
			string userInput = "hello world";
			string saveOption = "\n:wq\n";
			ss_in << userInput + saveOption;
			// CREATE AND EXECUTE COMMAND
			CatCommand* cc = new CatCommand(sfs);
			string executeInput = filename + " -a";
			Assert::AreEqual(cc->execute(executeInput), 0);
			// EXPECTATION -- CONTENTS PRINTED PRINTED
			string word;
			std::vector<string> printedWords;
			while (ss_out >> word) {
				printedWords.push_back(word);
			}
			std::vector<string>::iterator it1;
			it1 = std::find(printedWords.begin(), printedWords.end(), origContentsStr);
			bool notEqual1 = it1 == printedWords.end();
			Assert::IsFalse(notEqual1);
			// EXPECTATION -- CONTENTS CORRECTLY UPDATED
			vector<char> contents = file->read();
			string contentsStr(contents.begin(), contents.end());
			Assert::AreEqual(origContentsStr + userInput, contentsStr);
			// ASSIGN COUT BACK TO STDOUT
			cout.rdbuf(backup_out);
			// ASSIGN CIN BACK TO STDIN
			cin.rdbuf(backup_in);
		}
		TEST_METHOD(executeTextFileAppendNoSaving) { // test executing cat with append option and does not save input, no changes should be made to the text file
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			// ADD FILES
			string filename = "file.txt";
			AbstractFile* file = new TextFile(filename);
			Assert::AreEqual(sfs->addFile(filename, file), 0);
			// INITIALIZE FILE CONTENTS
			vector<char> origContents = { 'f','o','o' };
			string origContentsStr(origContents.begin(), origContents.end());
			Assert::AreEqual(file->write(origContents), 0);
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// MIMIC USER INPUT 
			string userInput = "hello world";
			string saveOption = "\n:q\n";
			ss_in << userInput + saveOption;
			// CREATE AND EXECUTE COMMAND
			CatCommand* cc = new CatCommand(sfs);
			string executeInput = filename + " -a";
			Assert::AreEqual(cc->execute(executeInput), 0);
			// EXPECTATION -- CONTENTS PRINTED PRINTED
			string word;
			std::vector<string> printedWords;
			while (ss_out >> word) {
				printedWords.push_back(word);
			}
			std::vector<string>::iterator it1;
			it1 = std::find(printedWords.begin(), printedWords.end(), origContentsStr);
			bool notEqual1 = it1 == printedWords.end();
			Assert::IsFalse(notEqual1);
			// EXPECTATION -- CONTENTS CORRECTLY UPDATED
			vector<char> contents = file->read();
			string contentsStr(contents.begin(), contents.end());
			Assert::AreEqual(origContentsStr, contentsStr);
			// ASSIGN COUT BACK TO STDOUT
			cout.rdbuf(backup_out);
			// ASSIGN CIN BACK TO STDIN
			cin.rdbuf(backup_in);
		} 
		TEST_METHOD(executeImageFileNoAppendSavingGoodInput) { // test executing cat with no append option and saving valid input to an image file
			// REDIRECT COUT STREAM -- PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			// ADD FILES
			string filename = "file.img";
			AbstractFile* file = new ImageFile(filename);
			Assert::AreEqual(sfs->addFile(filename, file), 0);
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// MIMIC USER INPUT 
			string userInput = "X X X X X3";
			string userInputWithoutLength = "X X X X X";
			string saveOption = "\n:wq\n";
			ss_in << userInput + saveOption;
			// CREATE AND EXECUTE COMMAND
			CatCommand* cc = new CatCommand(sfs);
			string executeInput = filename;
			Assert::AreEqual(cc->execute(executeInput), 0);
			// EXPECTATION -- CONTENTS MATCH
			vector<char> contents = file->read();
			string contentsStr(contents.begin(), contents.end());
			Assert::AreEqual(userInputWithoutLength, contentsStr);
			// ASSIGN CIN BACK TO STDIN
			cin.rdbuf(backup_in);
		}
		TEST_METHOD(executeImageFileNoAppendSavingBadInput) { // test executing cat with no append option and saving invalid input to an image file, content should be unchanged
			// REDIRECT COUT STREAM -- PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			// ADD FILES
			string filename = "file.img";
			AbstractFile* file = new ImageFile(filename);
			Assert::AreEqual(sfs->addFile(filename, file), 0);
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// MIMIC USER INPUT 
			string userInput = "X X X X X4";
			string userInputWithoutLength = "X X X X X";
			string saveOption = "\n:wq\n";
			ss_in << userInput + saveOption;
			// CREATE AND EXECUTE COMMAND
			CatCommand* cc = new CatCommand(sfs);
			string executeInput = filename;
			cc->execute(executeInput);
			// EXPECTATION -- CONTENTS UNCHANGED
			vector<char> contents = file->read();
			Assert::AreEqual(contents.size(), static_cast<size_t>(0));
			// ASSIGN CIN BACK TO STDIN
			cin.rdbuf(backup_in);
		}
		TEST_METHOD(executeImageFileNoAppendNoSavingGoodInput) { // test executing cat with no append option and not saving valid input to an image file, contents unchanged
			// REDIRECT COUT STREAM -- PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			// ADD FILES
			string filename = "file.img";
			AbstractFile* file = new ImageFile(filename);
			Assert::AreEqual(sfs->addFile(filename, file), 0);
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// MIMIC USER INPUT 
			string userInput = "X X X X X3";
			string userInputWithoutLength = "X X X X X";
			string saveOption = "\n:q\n";
			ss_in << userInput + saveOption;
			// CREATE AND EXECUTE COMMAND
			CatCommand* cc = new CatCommand(sfs);
			string executeInput = filename;
			Assert::AreEqual(cc->execute(executeInput), 0);
			// EXPECTATION -- CONTENTS UNCHANGED
			vector<char> contents = file->read();
			Assert::AreEqual(contents.size(), static_cast<size_t>(0));
			// ASSIGN CIN BACK TO STDIN
			cin.rdbuf(backup_in);
		}
		TEST_METHOD(executeImageFileAppendSavingGoodInput) { // test executing cat with append option and saving valid input to an image file, expect an error returned and contents to be unchanged
			// REDIRECT COUT STREAM -- PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			// ADD FILES
			string filename = "file.img";
			AbstractFile* file = new ImageFile(filename);
			Assert::AreEqual(sfs->addFile(filename, file), 0); // this line goes wrong
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// MIMIC USER INPUT 
			string userInput = "X X X X X3";
			string userInputWithoutLength = "X X X X X";
			string saveOption = "\n:wq\n";
			ss_in << userInput + saveOption;
			// CREATE AND EXECUTE COMMAND
			CatCommand* cc = new CatCommand(sfs);
			string executeInput = filename + " -a";
			Assert::AreNotEqual(cc->execute(executeInput), 0);
			// EXPECTATION -- CONTENTS UNCHANGED
			vector<char> contents = file->read();
			Assert::AreEqual(contents.size(), static_cast<size_t>(0));
			// ASSIGN CIN BACK TO STDIN
			cin.rdbuf(backup_in);
		}
		TEST_METHOD(executeFileDoesNotExist) { // test executing cat with append option and saving valid input to an image file that doesnt exist, expect an error returned 
			// REDIRECT COUT STREAM -- PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// MIMIC USER INPUT 
			string userInput = "hello world";
			string saveOption = "\n:wq\n";
			ss_in << userInput + saveOption;
			// CREATE AND EXECUTE COMMAND
			CatCommand* cc = new CatCommand(sfs);
			string executeInput = "file.txt";
			Assert::AreNotEqual(cc->execute(executeInput), 0);
			// ASSIGN CIN BACK TO STDIN
			cin.rdbuf(backup_in);
		}
	};
	TEST_CLASS(renameCommand) {
		TEST_METHOD(renameParsingStrategy) { // checks parse function of RenameParsingStrategy correctly converts input string into a vector of strings representing instructions for copy and remove commands
			// REDIRECT COUT STREAM -- PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// SETUP INPUT AND TEST OUTPUT
			RenameParsingStrategy* rps = new RenameParsingStrategy();
			vector<string> parsed = rps->parse("file.txt renamedFile");
			Assert::AreEqual(parsed.size(), static_cast<size_t>(2));
			string expectedCopyInstructions = "file.txt renamedFile";
			string expectedRemoveInstructions = "file.txt";
			Assert::AreEqual(parsed[0], expectedCopyInstructions);
			Assert::AreEqual(parsed[1], expectedRemoveInstructions);
		}
		TEST_METHOD(renameValid) {
			// REDIRECT COUT STREAM -- PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			// ADD FILES
			string filename = "file.txt";
			AbstractFile* file = new TextFile(filename);
			Assert::AreEqual(sfs->addFile(filename, file), 0);
			// INITIALIZE FILE CONTENTS
			vector<char> v = { 'h','i' };
			Assert::AreEqual(file->write(v), 0);
			// CREATE MACRO COMMAND USING RENAME PARSING STRATEGY AND COPY/REMOVE COMMANDS
			MacroCommand* mc = new MacroCommand(sfs);
			RenameParsingStrategy* rps = new RenameParsingStrategy;
			AbstractCommand* cpc = new CopyCommand(sfs);
			AbstractCommand* rmc = new RemoveCommand(sfs);
			mc->setParseStrategy(rps);
			mc->addCommand(cpc);
			mc->addCommand(rmc);
			// EXECUTE RENAME COMMAND
			string newfilename = "newfilename";
			string userInput = filename + " " + newfilename;
			Assert::AreEqual(mc->execute(userInput), 0);
			// EXPECTATION -- ORIGINAL FILE IS REMOVED
			AbstractFile* originalFile = sfs->openFile(filename);
			bool isNull = originalFile == nullptr;
			Assert::IsTrue(isNull);
			// EXPECTATION -- FILE EXISTS UNDER NEW NAME AND CONTENTS ARE THE SAME
			AbstractFile* newFile = sfs->openFile(newfilename + ".txt");			
			bool isNull2 = newFile == nullptr;
			Assert::IsFalse(isNull2);
			vector<char> contents = newFile->read();
			Assert::AreEqual(v.size(), contents.size());
			Assert::AreEqual(v[0], contents[0]);
			Assert::AreEqual(v[1], contents[1]);
			 //EXPECTATION -- ADDRESSES ARE DIFFERENT
			bool areEqual = &file == &newFile;
			Assert::IsFalse(areEqual);
			// EXPECTATION -- FILE TYPE MATCHES
			TextFile* textCheck = dynamic_cast<TextFile*>(newFile);
			bool isNotTextFile = textCheck == nullptr;
			Assert::IsFalse(isNotTextFile); 
		}
		TEST_METHOD(renameInvalidFilename) {
			// REDIRECT COUT STREAM -- PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			// ADD FILES
			string filename = "file.txt";
			AbstractFile* file = new TextFile(filename);
			Assert::AreEqual(sfs->addFile(filename, file), 0);
			// INITIALIZE FILE CONTENTS
			vector<char> v = { 'h','i' };
			Assert::AreEqual(file->write(v), 0);
			// CREATE MACRO COMMAND USING RENAME PARSING STRATEGY AND COPY/REMOVE COMMANDS
			MacroCommand* mc = new MacroCommand(sfs);
			RenameParsingStrategy* rps = new RenameParsingStrategy;
			AbstractCommand* cpc = new CopyCommand(sfs);
			AbstractCommand* rmc = new RemoveCommand(sfs);
			mc->setParseStrategy(rps);
			mc->addCommand(cpc);
			mc->addCommand(rmc);
			// EXECUTE RENAME COMMAND
			string invalidfilename = "wrongfilename.txt";
			string newfilename = "newfilename";
			string userInput = invalidfilename + " " + newfilename;
			Assert::AreNotEqual(mc->execute(userInput), 0);
			// EXPECTATION -- ORIGINAL FILE IS NOT REMOVED
			AbstractFile* originalFile = sfs->openFile(filename);
			bool isNull = originalFile == nullptr;
			Assert::IsFalse(isNull);
			// EXPECTATION -- FILE DOES NOT EXIST UNDER NEW NAME 
			AbstractFile* newFile = sfs->openFile(newfilename + ".txt");
			bool isNull2 = newFile == nullptr;
			Assert::IsTrue(isNull2);;
		}
		TEST_METHOD(renameInvalidNewFilename) {
			// REDIRECT COUT STREAM -- PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			// ADD FILES
			string filename = "file.txt";
			string otherfilename = "otherfile";
			AbstractFile* file = new TextFile(filename);
			Assert::AreEqual(sfs->addFile(filename, file), 0);
			AbstractFile* otherfile = new TextFile(otherfilename + ".txt");
			Assert::AreEqual(sfs->addFile(otherfilename + ".txt", otherfile), 0);
			// INITIALIZE FILE CONTENTS
			vector<char> v = { 'h','i' };
			Assert::AreEqual(file->write(v), 0);
			// CREATE MACRO COMMAND USING RENAME PARSING STRATEGY AND COPY/REMOVE COMMANDS
			MacroCommand* mc = new MacroCommand(sfs);
			RenameParsingStrategy* rps = new RenameParsingStrategy;
			AbstractCommand* cpc = new CopyCommand(sfs);
			AbstractCommand* rmc = new RemoveCommand(sfs);
			mc->setParseStrategy(rps);
			mc->addCommand(cpc);
			mc->addCommand(rmc);
			// EXECUTE RENAME COMMAND
			string userInput = filename + " " + otherfilename;
			Assert::AreNotEqual(mc->execute(userInput), 0);
			// EXPECTATION -- ORIGINAL FILE IS NOT REMOVED
			AbstractFile* originalFile = sfs->openFile(filename);
			bool isNull = originalFile == nullptr;
			Assert::IsFalse(isNull);
			// EXPECTATION -- OTHER FILE STILL EXISTS
			AbstractFile* newFile = sfs->openFile(otherfilename + ".txt");
			bool isNull2 = newFile == nullptr;
			Assert::IsFalse(isNull2);;
		}
		TEST_METHOD(renameValidPasswordProtected) {
			// REDIRECT COUT STREAM -- PROTECT AGAINST ERRORS
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// SET UP FILE SYSTEM
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			// ADD FILES
			string filename = "file.txt";
			AbstractFile* file = new TextFile(filename);
			string password = "Adi23ifK";
			AbstractFile* proxy = new PasswordProxy(file, password);
			Assert::AreEqual(sfs->addFile(filename, proxy), 0);
			// INITIALIZE FILE CONTENTS -- WE WRITE DIRECTLY TO FILE IN THIS CASE (FUNCTIONALITY IS TEST OTHER PLACES)
			vector<char> v = { 'h','i' };
			Assert::AreEqual(file->write(v), 0);
			// CREATE MACRO COMMAND USING RENAME PARSING STRATEGY AND COPY/REMOVE COMMANDS
			MacroCommand* mc = new MacroCommand(sfs);
			RenameParsingStrategy* rps = new RenameParsingStrategy;
			AbstractCommand* cpc = new CopyCommand(sfs);
			AbstractCommand* rmc = new RemoveCommand(sfs);
			mc->setParseStrategy(rps);
			mc->addCommand(cpc);
			mc->addCommand(rmc);
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// EXECUTE RENAME COMMAND
			string newfilename = "newfilename";
			string userInput = filename + " " + newfilename;
			Assert::AreEqual(mc->execute(userInput), 0);
			// EXPECTATION -- ORIGINAL FILE IS REMOVED
			AbstractFile* originalFile = sfs->openFile(filename);
			bool isNull = originalFile == nullptr;
			Assert::IsTrue(isNull);
			// EXPECTATION -- FILE EXISTS UNDER NEW NAME AND CONTENTS ARE THE SAME
			AbstractFile* newFile = sfs->openFile(newfilename + ".txt");
			bool isNull2 = newFile == nullptr;
			Assert::IsFalse(isNull2);
			// SET UP USER PASSWORD INPUT AND READ AGAIN TO GET TRUE CONTENTS 
			ss_in << password + "\n";
			vector<char> contentswithpassword = newFile->read();
			Assert::AreEqual(v.size(), contentswithpassword.size());
			Assert::AreEqual(v[0], contentswithpassword[0]);
			Assert::AreEqual(v[1], contentswithpassword[1]);
			// SECOND READ CALL NOT GIVEN A PASSWORD -- SHOULD FAIL AND GET AN EMPTY VECTOR
			vector<char> contents = newFile->read();
			Assert::AreEqual(contents.size(), static_cast<size_t>(0));
			// EXPECTATION -- ADDRESSES ARE DIFFERENT
			bool areEqual = &file == &newFile;
			Assert::IsFalse(areEqual);
			// EXPECTATION -- FILE TYPE MATCHES
			PasswordProxy* proxyCheck = dynamic_cast<PasswordProxy*>(newFile);
			bool isNotPasswordProxy = proxyCheck == nullptr;
			Assert::IsFalse(isNotPasswordProxy);
		}
	};
	TEST_CLASS(DSCommand) {
		TEST_METHOD(displaytext) {
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			string filename1 = "file.txt";
			Assert::AreEqual(sfs->addFile(filename1, sff->createFile(filename1)), 0);
			AbstractFile* f = sfs->openFile(filename1);
			vector<char> v = { 'h', 'i','\n','h','e','l','l','o' };
			f->write(v);
			sfs->closeFile(f);
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// execute ds
			AbstractCommand* ds = new DisplayCommand(sfs);
			Assert::AreEqual(ds->execute(filename1), 0);
			ss_out >> noskipws;
			char c;
			for (size_t i = 0; i < v.size(); ++i) {
				ss_out >> c;
				Assert::AreEqual(c, v[i]);
			}
			// ensure the file was closed
			f = sfs->openFile(filename1);
			bool isNull = f == nullptr;
			Assert::IsFalse(isNull);
		}
		TEST_METHOD(displaytextunformatted) {
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			string filename1 = "file.txt";
			Assert::AreEqual(sfs->addFile(filename1, sff->createFile(filename1)), 0);
			AbstractFile* f = sfs->openFile(filename1);
			vector<char> v = { 'h', 'i','\n','h','e','l','l','o' };
			f->write(v);
			sfs->closeFile(f);
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// execute ds
			AbstractCommand* ds = new DisplayCommand(sfs);
			Assert::AreEqual(ds->execute(filename1 + " -d"), 0);
			ss_out >> noskipws;
			char c;
			for (size_t i = 0; i < v.size(); ++i) {
				ss_out >> c;
				Assert::AreEqual(c, v[i]);
			}
			// ensure the file was closed
			f = sfs->openFile(filename1);
			bool isNull = f == nullptr;
			Assert::IsFalse(isNull);
		}
		TEST_METHOD(displayimageformatted) {
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			string filename1 = "file.img";
			Assert::AreEqual(sfs->addFile(filename1, sff->createFile(filename1)), 0);
			AbstractFile* f = sfs->openFile(filename1);
			vector<char> v = { 'X',' ',' ','X',' ',' ','X', ' ',' ','3' };
			vector<char> expectedOutput = { 'X',' ',' ','\n','X',' ',' ','\n','X',' ',' ','\n' };
			f->write(v);
			sfs->closeFile(f);
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// execute ds
			AbstractCommand* ds = new DisplayCommand(sfs);
			Assert::AreEqual(ds->execute(filename1), 0);
			ss_out >> noskipws;
			char c;
			for (size_t i = 0; i < expectedOutput.size(); ++i) {
				ss_out >> c;
				Assert::AreEqual(c, expectedOutput[i]); // this line goes wrong
			}
			// ensure the file was closed
			f = sfs->openFile(filename1);
			bool isNull = f == nullptr;
			Assert::IsFalse(isNull);
		}

		TEST_METHOD(displayimageunformatted) {
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			string filename1 = "file.img";
			Assert::AreEqual(sfs->addFile(filename1, sff->createFile(filename1)), 0);
			AbstractFile* f = sfs->openFile(filename1);
			vector<char> v = { 'X',' ',' ','X',' ',' ','X', ' ',' ','3' };
			vector<char> expectedOutput = { 'X',' ',' ','X',' ',' ','X',' ',' ','\n' };
			f->write(v);
			sfs->closeFile(f);
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			// execute ds
			AbstractCommand* ds = new DisplayCommand(sfs);
			Assert::AreEqual(ds->execute(filename1 + " -d"), 0);
			ss_out >> noskipws;
			char c;
			for (size_t i = 0; i < expectedOutput.size(); ++i) {
				ss_out >> c;
				Assert::AreEqual(c, expectedOutput[i]);
			}
			// ensure the file was closed
			f = sfs->openFile(filename1);
			bool isNull = f == nullptr;
			Assert::IsFalse(isNull);
		}
		TEST_METHOD(displayinvalid) {
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			string filename1 = "file.img";
			Assert::AreEqual(sfs->addFile(filename1, sff->createFile(filename1)), 0);
			AbstractCommand* ds = new DisplayCommand(sfs);
			Assert::AreNotEqual(ds->execute("file.txt"), 0);
		}
	};
	TEST_CLASS(Copy) {
		TEST_METHOD(validcopy) {
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();

			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());

			string filename = "file.txt";
			Assert::AreEqual(sfs->addFile(filename, sff->createFile(filename)), 0);
			AbstractFile* f = sfs->openFile(filename);
			vector<char> original = { 'h','i' };
			f->write(original);
			sfs->closeFile(f);
			string copyname = "copy.txt";
			AbstractCommand* cp = new CopyCommand(sfs);
			Assert::AreEqual(cp->execute(filename + " copy"), 0);
			f = sfs->openFile(filename);
			bool isNull = f == nullptr;
			Assert::IsFalse(isNull);
			AbstractFile* f_copy = sfs->openFile(copyname);
			isNull = f_copy == nullptr;
			Assert::IsFalse(isNull);
			Assert::AreEqual(f_copy->getName(), copyname);
			bool sameFile = f_copy == f;
			Assert::IsFalse(sameFile);
			vector<char> copy_contents = f_copy->read();
			Assert::AreEqual(copy_contents.size(), original.size());
			Assert::AreEqual((size_t)f->getSize(), original.size());
			for (size_t i = 0; i < original.size(); ++i) {
				Assert::AreEqual(copy_contents[i], original[i]);
			}
			TextFile* t_p = dynamic_cast<TextFile*>(f_copy);
			isNull = t_p == nullptr;
			Assert::IsFalse(isNull);
		}
		TEST_METHOD(invalidcopy) {
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();

			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());

			string filename = "file.txt";
			Assert::AreEqual(sfs->addFile(filename, sff->createFile(filename)), 0);
			AbstractFile* f = sfs->openFile(filename);
			vector<char> original = { 'h','i' };
			f->write(original);
			sfs->closeFile(f);
			AbstractCommand* cp = new CopyCommand(sfs);
			Assert::AreNotEqual(cp->execute(filename + " file"), 0);
			Assert::AreNotEqual(cp->execute("madeupname.txt othername"), 0);
			// ensure the original file wasn't changed and is closed
			f = sfs->openFile(filename);
			bool isNull = f == nullptr;
			Assert::IsFalse(isNull);
			vector<char> after_invalid = f->read();
			Assert::AreEqual(after_invalid.size(), original.size());
		}
		TEST_METHOD(copypasswordprotected) {
			AbstractFileSystem* sfs = new SimpleFileSystem();
			AbstractFileFactory* sff = new SimpleFileFactory();
			// REDIRECT COUT STREAM
			streambuf* backup_out;
			backup_out = cout.rdbuf();
			stringstream ss_out;
			cout.rdbuf(ss_out.rdbuf());
			string filename = "file.txt";
			AbstractFile* realfile = sff->createFile(filename);
			vector<char> original = { 'h','i' };
			realfile->write(original);
			string pw = "easypassword";
			AbstractFile* proxy_toreal = new PasswordProxy(realfile, pw);
			Assert::AreEqual(sfs->addFile(proxy_toreal->getName(), proxy_toreal), 0);
			AbstractCommand* cp = new CopyCommand(sfs);
			string copyname = "copy.txt";
			Assert::AreEqual(cp->execute(filename + " copy"), 0);
			AbstractFile* proxy_copy = sfs->openFile(copyname);
			bool isNull = proxy_copy == nullptr;
			Assert::IsFalse(isNull);
			PasswordProxy* proxy_tocopy = dynamic_cast<PasswordProxy*>(proxy_copy);
			isNull = proxy_tocopy == nullptr;
			Assert::IsFalse(isNull);
			
			bool sameProxy = proxy_tocopy == proxy_toreal;
			Assert::IsFalse(sameProxy);
			// REDIRECT CIN STREAM
			streambuf* backup_in;
			backup_in = cin.rdbuf();
			stringstream ss_in;
			cin.rdbuf(ss_in.rdbuf());
			// MIMIC USER INPUT
			ss_in << pw << '\n';
			vector<char> newdata = { 'h','e','l','l','o' };
			Assert::AreEqual(proxy_tocopy->write(newdata), 0);
			auto v = realfile->read();
			Assert::AreEqual(v.size(), original.size());
			for (size_t i = 0; i < v.size(); ++i) {
				Assert::AreEqual(v[i], original[i]);
			}
		}
	};

}