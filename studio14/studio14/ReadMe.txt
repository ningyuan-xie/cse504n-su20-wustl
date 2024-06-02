Studio 14

1. 
Ningyuan Xie
Ben Silberstein
Anh Vo

2. 
(1) 1 object was created
(2) 1 object was destroyed

3.
(1) 2 objects were created; 1 object was destroyed
(2) because we dynamically allocated the object detector, so it won't get destroyed if we do not call "delete"

4. 2 objects were destroyed in this case, because we called "delete"

5.
(1) 3 objects were created; 3 objects were destroyed
(2) we used shallow copy so no problems with allocation/deallocation
(3) 1st wrapper w was responsible for creating/destroying the 1st detector object

6. 
Becasue of the copy construction: 4 objects were created; 4 objects were destroyed