Ningyuan Xie CSE 504N Lab 1

Errors/warnings：
1. When iterate through vector using vector.size(), I forgot to add () multiple times which cause an error.

2. In my parsing_function(), I did not check "no_file_name_given" in the first condition. Therefore, the program crashed when running in
   command line when I did not input a file to run.

3. When typing absolute path, I only typed one "\" instead of two (previously in my Python on Mac experience I only need to type "xxx/xxx"),
   so I could never successfully open a file. I struggled with that error for nearly an hour.

4. In the main method, I called parsing_function() first and then check whether parsing_function() == file_open_failed. This runs my function
   twice. I later realized that the first call is redundant because it will run once in the if-statement.

These are the major errors/warnings I ran into. I spent almost 8 hours on the compulsory part of this lab, and frankly half of my time was 
used to debug these problems. Nevertheless, I enjoyed this lab very much!


Test cases I run:
(Note: According to the lab instruction at the end of Step 13, I only summarized what my program did;
detailed command results can be seen below in the extra credit part):

1. command line: "H:\CSE_504N_Lab1\cse504lab1\Debug>cse504lab1.exe"
   I did not correctly input a file name. The program correctly prints out an instruction: "usage: cse504lab1.exe <input_file_name>"

2. command line: "H:\CSE_504N_Lab1\cse504lab1\Debug>cse504lab1.exe input_file.txt"
   I input a non-existing file. The program correctly prints out "File open failed; no matching file was found."

3. command line: "H:\CSE_504N_Lab1\cse504lab1\Debug>cse504lab1.exe input_file_1.txt"
   I input a "input_file_1.txt", which contains both strings with non-nummerical characters and integer values.
   The program prints out "File is successfully opened!" "Extraction completed.", before printing out both strings with 
   non-nummerical characters and integer values correctly. Empty strings are ignored.

4. command line: "H:\CSE_504N_Lab1\cse504lab1\Debug>cse504lab1.exe input_file_2.txt"
   I input a "input_file_2.txt", which contains both strings with non-nummerical characters and integer values.
   The program prints out "File is successfully opened!" "Extraction completed.", before printing out both strings with 
   non-nummerical characters and integer values correctly. Empty strings are ignored.

5. command line: "H:\CSE_504N_Lab1\cse504lab1\Debug>cse504lab1.exe input_file_3.txt"
   I input a "input_file_3.txt", which contains only integer values.
   The program prints out "File is successfully opened!" "Extraction completed.", before printing out only integer values corresponding 
   to strings with only numeric digit characters correctly. Empty strings are ignored.

6. command line: "H:\CSE_504N_Lab1\cse504lab1\Debug>cse504lab1.exe input_file_4.txt"
   I input a "input_file_4.txt", which contains only strings with non-nummerical characters.
   The program prints out "File is successfully opened!" "Extraction completed.", before printing out only strings with 
   non-nummerical characters correctly. Empty strings are ignored.

------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------

Extra Credit Section

EC 1:
[ningyuan.xie@shell ~]$ ls
CSE_504N_Lab1         CSE_504N_Studio_2&3  Desktop    Music         perl5     Public     Videos
CSE_504N_Recitations  CSE_504N_Studio_4&5  Downloads  My Documents  Pictures  Templates  WINDOWS

EC 2:
Errors/warnings：
1. According to Professor Shidal, "g++ compiles to the c++98 standard by default", so I ran into an error
   where the open function is not supported during compliation. Professor Shidal tole me to add
   "-std=c++11" after "-pedantic", and the error went away.

2. I ran into a warning: A warning - comparison between signed and unsigned integer expressions. I fixed
   it by changing the integer used for comparison from "int" to "size_t" to compare with xx.size().

After that, my program compiles with no errors or warnings; but I ran into more problems when running 
my code. I want to thank Professor Shidal for helping me solve these problems on Piazza.

3. Linux has different file path logic than Windows does. For my program to read any file, I have to
   change the path 
   from "H:\\CSE_504N_Lab1\\cse504lab1\\cse504lab1\\" to "/home/warehouse/ningyuan.xie/cse332/lab1/".

4. txt files are also formatted differently in Linux, as my code will print out different results than
   it did in Windows. I used to following process to transfer txt files: 
   type "vi input_file_1.txt" to open the editor
   type ":set fileformat=unix" to transfer
   type ":wq" to save the file and exit the editor

After that, my program finally runs without problems.


Same trial cases I ran: 
(Here I copy all the results. Note that they produce exactly the same results as those under Windows do):

1. Did not correctly input a file name
[ningyuan.xie@shell lab1]$ ./cse504lab1.exe
usage: cse504lab1.exe <input_file_name>


2. Input a non-existing file
[ningyuan.xie@shell lab1]$ ./cse504lab1.exe input_file.txt
File open failed; no matching file was found.


3. File contains both strings with non-nummerical characters and integer value
[ningyuan.xie@shell lab1]$ vi input_file_1.txt
[ningyuan.xie@shell lab1]$ ./cse504lab1.exe input_file_1.txt
File is successfully opened!
Extraction completed.

-------------------------
vector_of_string's output:

hello, this is my testing file.
        I am trying to complete lab-1.
C++ is very fun to learn!
I am going to sleep now. It's too late!
-------------------------


-------------------------
vector_of_int's output:

123
456
789
-------------------------


4. File contains both strings with non-nummerical characters and integer value
[ningyuan.xie@shell lab1]$ vi input_file_2.txt
[ningyuan.xie@shell lab1]$ ./cse504lab1.exe input_file_2.txt
File is successfully opened!
Extraction completed.

-------------------------
vector_of_string's output:

hello, this is my 2nd testing file!
        I think my lab-1 project is going great!
C++ is important in quantitative finance.
        That is why I choose CSE 504N to enhance my programming skills.
-------------------------


-------------------------
vector_of_int's output:

314229124
233455
456
-------------------------


5. File contains no strings with non-nummerical characters and only integer value
[ningyuan.xie@shell lab1]$ vi input_file_3.txt
[ningyuan.xie@shell lab1]$ ./cse504lab1.exe input_file_3.txt
File is successfully opened!
Extraction completed.

-------------------------
vector_of_string's output:

-------------------------


-------------------------
vector_of_int's output:

639111025
466722533
624951341
-------------------------


6. File contains only strings with non-nummerical characters and no integer value
[ningyuan.xie@shell lab1]$ vi input_file_4.txt
[ningyuan.xie@shell lab1]$ ./cse504lab1.exe input_file_4.txt
File is successfully opened!
Extraction completed.

-------------------------
vector_of_string's output:

This is my fourth test file.
The third test file contain only nuemrical data.
On the contrary, this file does not contain any numerical data.
-------------------------


-------------------------
vector_of_int's output:

-------------------------























