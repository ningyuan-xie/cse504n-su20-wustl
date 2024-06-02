studio 18 answers here
1. Group members: Ningyuan Xie; Anh Vo; Runyao Guo


2. The SimpleFileSystem are creating files based on the input type that client choose. 
   For example, in order to create TextFile, we need to create an object of TextFile, same thing with ImageFile.
   Factory method will help client to pass type to the Factory and create object. Creating the new file system 
   implementation makes it more convenient to create different types of files. To build new concrete file type,
   a new class of may need to be declared, and also common functions such as add, open, close, and delete may need
   to be declared and defined for the concrete file type.


3. Advantage of the abstract factory pattern: this fits the "Single responsibility principle". Also, given two file system implementations
   that manage different types of files, the same factory can be used to create files for both, but not the same concrete factory
   implementation. When a new file type is introduced to create, the only code that must be modified is in the concrete factory.

   Disadvantages: Although the file system can manage many concrete type of files, it needs to know the related types (need to know each concrete type of files).
   
   The same factory can be used to create files for the two file system implementations that manage same types of files, 
   but cannot be used to create files for two files system implementations that manage different types of files.
   It might be more practical to have separate concrete factory implementations for each file system, each tailored to the specific requirements and behaviors of the file system it manages.


4. Test cases: 
   create a text file via the factory object;
   read the vector { 'h', 'e', 'l', 'l', 'o' };
   read output: hello


5. At this point, SimpleFileSystem does not depend on any concrete file types, but depends on the AbstractFile interface only, because
   its responsibility of creatFile has transferred to SimpleFileFactory (which now depends on concrete file types).