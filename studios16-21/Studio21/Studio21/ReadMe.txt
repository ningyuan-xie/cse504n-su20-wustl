Studio 21 answers here

1. Group members: Ningyuan Xie; Anh Vo; Runyao Guo. We arranged two meetings lasting 6 hours everyday and we finished everything together through
   the zoom meetings.


2. Because a destructor can help to undo some command if needed. When the user make a mistake, the
   user can let the program to undo such command. 


3. Dependency injection is used to make this command pattern. In this process, the different objects are
   constructed by getting pointers/references from other objects, this allows different objects associate
   with each other in a flexible way. In the command pattern, the AbstractCommand class has pointers to
   different concrete commands. This command prompt is flexible because it can identify users' input,
   let the program execute the command, as well as display the information of the command.

   The command prompt can be easily configured compared to simple file system and its associated object.
   The command prompt enables different commands to execute correctly.


4. Test cases we ran:

    Test quitting:

    C:\WINDOWS\system32>H:

    H:\>cd Studio16-21\Studio21\x64\Debug\

    H:\Studio16-21\Studio21\x64\Debug>Studio21.exe

	Enter a command
	q to quit
	help for a list of commands
	help <command name> for details about a specific command
	$  q
	The user input 'q' to quit. Either the user does not inputs 'touch abc.txt' or after the user inputs 'touch abc.txt' to create the file and inputs'q' to quit (then the run() function returns a value), the file 'abc.txt' cannot be accessed in main().

    Test asking for help:
    
	H:\Studio16-21\Studio21\x64\Debug>Studio21.exe

    Enter a command
    q to quit
    help for a list of commands
    help <command name> for details about a specific command
    $  help
    touch

    Test asking for help on the touch command:
    Enter a command
    q to quit
    help for a list of commands
    help <command name> for details about a specific command
	$  help touch
	touch creates a file, touch can be invoked with the command: touch <filename>

    Test executing the touch command
    Enter a command
    q to quit
    help for a list of commands
    help <command name> for details about a specific command
	$  touch file.txt
	A command is found.

	Test after the user inputs "touch 'abc.txt" to create a file (the file name in this case is "abc.txt") and input "q" to quit (then the run() function returns a value),
	the file "abc.txt" can still be accessed in main().

	Enter a command
    q to quit
    help for a list of commands
    help <command name> for details about a specific command
	$  q
	The user input 'q' to quit. After the user inputs 'touch abc.txt' to create the file and inputs'q' to quit (then the run() function returns a value), the file 'abc.txt' can still be accessed in main().
    

------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------


Lab 5 answers here (including extra credit part)

Group members: Ningyuan Xie; Anh Vo; Runyao Guo. In the process of doing Lab 5, we arranged two meetings lasting 6 hours everyday and we finished everything together through
the zoom meetings.


Tests we ran:

1. cat:
Enter a command
q to quit
help for a list of commands
help <command name> for details about a specific command
$  help
cat
catds
cp
ds
ls
rm
rn
test
touch

Enter a command
q to quit
help for a list of commands
help <command name> for details about a specific command
$  touch a.txt
A command is found.

Enter a command
q to quit
help for a list of commands
help <command name> for details about a specific command
$  cat a.txt
a.txt
Enter what you would like to write to the file.
Or enter :wq to save the file and exit.
Or enter :q to exit without saving.
asdf
hjkl
:wc
:wq
A command is found.

Enter a command
q to quit
help for a list of commands
help <command name> for details about a specific command
$  cat a.txt -a
a.txt
asdf
hjkl
:wc
Enter what you would like to write to the file.
Or enter :wq to save the file and exit
Or enter :q to exit without saving

2. catds
Enter a command
q to quit
help for a list of commands
help <command name> for details about a specific command
$  help catds
This is a MacroCommand; it should be invoked according to its strategy.
For example: rn renames a file; rn can be invoked with the command: rn <existing_file> <new_name_with_no_extension>

3. touch + cp
Enter a command
q to quit
help for a list of commands
help <command name> for details about a specific command
$  touch b.txt
A command is found.

Enter a command
q to quit
help for a list of commands
help <command name> for details about a specific command
$  cat b.txt
b.txt
Enter what you would like to write to the file.
Or enter :wq to save the file and exit.
Or enter :q to exit without saving.
abcde
:wq
A command is found.

Enter a command
q to quit
help for a list of commands
help <command name> for details about a specific command
$  cp b.txt c
A command is found.

Enter a command
q to quit
help for a list of commands
help <command name> for details about a specific command
$  ds b.txt
abcde
A command is found.

Enter a command
q to quit
help for a list of commands
help <command name> for details about a specific command
$  ds c.txt
abcde
A command is found.

Enter a command
q to quit
help for a list of commands
help <command name> for details about a specific command
$  cat c.txt
c.txt
Enter what you would like to write to the file.
Or enter :wq to save the file and exit.
Or enter :q to exit without saving.
fghij
:wq
A command is found.

Enter a command
q to quit
help for a list of commands
help <command name> for details about a specific command
$  ds b.txt
abcde
A command is found.

Enter a command
q to quit
help for a list of commands
help <command name> for details about a specific command
$  ds c.txt
fghij
A command is found.

4. ls
Enter a command
q to quit
help for a list of commands
help <command name> for details about a specific command
$  touch a.txt
A command is found.

Enter a command
q to quit
help for a list of commands
help <command name> for details about a specific command
$  touch abc.txt
A command is found.

Enter a command
q to quit
help for a list of commands
help <command name> for details about a specific command
$  touch bcdef.txt
A command is found.

Enter a command
q to quit
help for a list of commands
help <command name> for details about a specific command
$  touch hijk.txt
A command is found.

Enter a command
q to quit
help for a list of commands
help <command name> for details about a specific command
$  touch opq.img
A command is found.

Enter a command
q to quit
help for a list of commands
help <command name> for details about a specific command
$  ls
a.txt                    abc.txt
bcdef.txt                hijk.txt
opq.img

Enter a command
q to quit
help for a list of commands
help <command name> for details about a specific command

5. rm
Enter a command
q to quit
help for a list of commands
help <command name> for details about a specific command
$  touch a.txt
A command is found.

Enter a command
q to quit
help for a list of commands
help <command name> for details about a specific command
$  touch b.txt
A command is found.

Enter a command
q to quit
help for a list of commands
help <command name> for details about a specific command
$  ls
a.txt                    b.txt


Enter a command
q to quit
help for a list of commands
help <command name> for details about a specific command
$  rm a.txt
 Deleted
A command is found.

Enter a command
q to quit
help for a list of commands
help <command name> for details about a specific command
$  ls
b.txt

Enter a command
q to quit
help for a list of commands
help <command name> for details about a specific command

6. rn
Enter a command
q to quit
help for a list of commands
help <command name> for details about a specific command
$  help rn
This is a MacroCommand; it should be invoked according to its strategy.
For example: rn renames a file; rn can be invoked with the command: rn <existing_file> <new_name_with_no_extension>

Enter a command
q to quit
help for a list of commands
help <command name> for details about a specific command

7. test:
Enter a command
q to quit
help for a list of commands
help <command name> for details about a specific command
$  help test
aRandomStringz

Enter a command
q to quit
help for a list of commands
help <command name> for details about a specific command
$


Errors/bugs encountered while working:

1. In the display command, we accidentally typed a " " after every pixel, so the graph displayed looks "fatter" than it should.


2. In the copy command, we forgot to pass a string holding the new file name to the clone function as part of the prototype patter, so when we
   call "cp", the new file will still has the name of the original file.


Additional notes:

1. In the display command, I created an extra visitor "BasicDisplayVisitor2" to visit the files in unformatted ways. Although the unformatted
   ways for image are the same as they do for text, this extra visitor can be better implemented in the future if unformatted conditions change.


2. We did Question c for the extra credit part. The intuition is modifying the vector of string from the RenameParsingStrategy so that it only
   returns the same parameter for both index 0 and index 1. In this way, both "cat" and "ds" will call the same file, so the command "catds" can
   edit a file and then display it afterwards to see the edits.