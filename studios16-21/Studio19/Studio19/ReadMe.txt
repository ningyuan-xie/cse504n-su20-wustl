studio 19 answers here

1. Group members: Ningyuan Xie; Anh Vo; Runyao Guo

2. Test Case:
We created a new text file and rewrite this text file with "h", "e", "l", "l", "o".

3. The txt and img object send visit request to the BasicDisplayVisitor object, then the visitor can
access to these objects. In this way, the two objects communicate with the visitor and delegate the 
read functions to the visitor (by calling the two functions: visit_TextFile and visit_ImageFile). 

4. Delegation is a method that involves a receiver and a sender. In the delegation process, the sender
sends a visit request to the receiver (through passing a pointer of the sender to the receiver), as a 
result, the receiver can access to the sender's state.

In this case, the BasicDisplayVisitor is a receiver, and it has functions to read each concrete file
object. The responsibility of reading files in each concrete class is transferred to this receiver.
A pointer of the BasicDisplayVisitor is passed to the concrete file objects, and the read functions is
independent from the concrete files, and this ensures that the additional function does not clutter the
interface.

5. To display a file's metadata, create a new class and inside this class, declare and define functions to get file's name, size and
type. 

If a concrete file type is added, all the visitor classes needs to be modified. A negative impact of
using visitor pattern is that when new concrete types needs to be included, all the visitor classes
should be modified, making the program not flexible enough to adapt to changes.