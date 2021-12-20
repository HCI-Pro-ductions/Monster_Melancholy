# Monster_Melancholy_v2.0.0
A big portion of the Source Code for Monster Melancholy v2.0.0  
A few parts of the code (like decryption, encryption, server security, etc) has been obfuscated due to security reasons  
Examples:  
- The int encrypt and int decrypt functions;  
- In File "MHGdataHandle.h", line 87, please key in your own mongodb uri connection string for the code to work.  

 I am using sha256 header files (that I modified slightly by excluding "#include <endian.h>") from https://create.stephan-brumme.com/hash-library/ (and I would like to thank them)
under the zlib License.  
  
Please also note that mongo-c-driver was used for the C++ code for mongodb connections (see [mongo-c-driver-download-link](http://mongoc.org/))
