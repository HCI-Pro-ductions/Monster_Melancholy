# Monster Melancholy Game: A simple adventure-style game


[![Docs](https://img.shields.io/badge/docs-monster--melancholy.me-brightgreen?style=flat-square&color=%2373DC8C&label=docs)](https://monster-melancholy.me)
[![Latest Release](https://img.shields.io/github/v/release/HCI-Pro-ductions/Monster_Melancholy?color=lightgreen&include_prereleases&label=latest%20version&style=flat-square)](https://github.com/HCI-Pro-ductions/Monster_Melancholy/releases)

### [Downloads and Instructions](https://monster-melancholy.me/downloads)

<br/><br/>

Monster Melancholy Game (MMG) is a simplistic but still fun adventure game! It was created simply as side project and as a way for us (specially [@AKeevee](https://github.com/AKeevee)) to express our creativity. Do have a try, it's quite easy (instructions linked above :D).

This was created as a side project so please excuse the roughness around the edges :)

<br/>

## For Developers:

A few parts of the code (like decryption, encryption, server security, etc) are obfuscated due to security reasons, such as:
- The int encrypt and int decrypt functions
- In File "MHGdataHandle.h", line 87, the MongoDB connection URI is omitted

Thanks to:
- [Stephan-Brumme](https://create.stephan-brumme.com/hash-library) - Modified version of header files used for hashing
- [Mongo-C](http://mongoc.org) - MongoDB driver for c++
