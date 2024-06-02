1.  Xander Varga 
	Anh Vo
	Ningyan Xie

	Uki is with us also 


2. the A constructor is called before the B constructor during the declaration of B.
Then the program destroys the objects in the reverse order that they were created,
which also implies that the B destrcutor is called first. 

3. 

A constructor
A constructor
B constructor
A method:
A's method called
B method:
B's method called
A reference to A:
A's method called
A reference to B:		<<
A's method called
B reference to B:
B's method called
B destructor
A destructor
A destructor

this was mostly as expected. We learned that when a reference to A's method is called,
the A.method is called even if the referenced object is not of type A.

we made both methods virtual.

WHEN: the line with A's reference to B 

HOW: B's method was called instead of A

WHY: the 'virtual' keyword allows for dynamic binding. 

4. its the exact same as for references.

5. 
the derived class (B) destructors are always called frist

for the A* that points to the B object:
when the virtual keyword is used on the base class destructor (virtual ~A()), 
the derived class constructor is also called. 

6. 
