Anh Vo




3.
the shared pointer has its own destructor and was declared in main, so when main gets out of scope, the share_ptr is destructed.

4.
(a) the share_ptr inside the main.
(b) When main gets out of scope
(C) only once
(d) after the object is destroyed, no aliases remain.

5.
(a) Yes, more detector objects are created/destroyed.
(b) Because we declared more objects.

6.
H:\332\cse332s-su19-wustl\studio13-14\studio13\studio13\Debug>studio13.exe
This is begining of main
detector() 00B2F464 x = 0
detector() 00B2F664 x = 1
detector() 00B2F5E4 x = 2
this is original shared_ptr
00B2F464 00B2F664 00B2F5E4
this is aliased by shared_ptr of the vector
00B2F464 00B2F664 00B2F5E4
This is ending of main
~detector() 00B2F5E4 x = 2
~detector() 00B2F664 x = 1
~detector() 00B2F464 x = 0

the same objects are being aliased by two different sets of shared_ptr variables.


7.

When I  explicitly call delete on the pointer to detector object, the "~detector is called".
The vector does not clean up memory of what objects that pointers to
