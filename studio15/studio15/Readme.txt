

2. All the values could be assigned because the l value and r value were initialized correctly.

3. When moving the values into our r-value references, the values were copied over successfuly.

4. The detector objects are not allocated and de-allocated correctly because we do not have a move constructor.

5.1 The program is behaving correctly because the move operator does not change the number of detector objects because the move construct is reassigning the pointer to the new wrapper object.
5.2
detector() 00DD3520 x = 0
wrapper()007FFE04 p_d = 00DD3520
Begin copy
Num Detector (copy)= 1
detector() 00DD96A0 x = 1
wrapper()007FFDF4 p_d = 00DD96A0
Num Detector (copy)= 2
End copy
Move constructor begin (wrapper)
Detector objects= 2
Detector objects= 2
Move constructor end (wrapper)
~wrapper()007FFDE4 p_d = 00DD3520
~detector() 00DD3520 x = 0
~wrapper()007FFDF4 p_d = 00DD96A0
~detector() 00DD96A0 x = 1
~wrapper()007FFE04 p_d = 00000000

6.1 The program behaves correctly because the move operator deletes the detector object that the move operator is being assigned to.
6.2

detector() 00F73520 x = 0
wrapper()00AFFBD4 p_d = 00F73520
Begin copy
Num Detector (copy)= 1
detector() 00F796A0 x = 1
wrapper()00AFFBC4 p_d = 00F796A0
Num Detector (copy)= 2
End copy
detector() 00F73478 x = 2
wrapper()00AFFBB4 p_d = 00F73478
begin of operator (move)
Num detectors= 3
~detector() 00F73478 x = 2
Num detectors= 2
end of operator (move)
~wrapper()00AFFBB4 p_d = 00F73520
~detector() 00F73520 x = 0
~wrapper()00AFFBC4 p_d = 00F796A0
~detector() 00F796A0 x = 1
~wrapper()00AFFBD4 p_d = 00000000
