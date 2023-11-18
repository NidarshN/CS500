# Vignere Cipher Implementation in C++

This C++ implementation provides a Vignere cipher for encrypting and decrypting messages. The Vignere cipher is a method of encrypting alphabetic text using a simple form of polyalphabetic substitution.

## Table of Contents

- [Features](#features)
- [Usage](#usage)
- [Example](#example)
- [References](#references)

## Features

- Encryption of a given string using a specified Vignere cipher
- Decryption of an encrypted string using a specified Vignere cipher
- Validation to check if a given string is correctly encrypted
- Dynamic key setting for the Vignere cipher

## Usage

To use the Vignere cipher implementation, follow these steps:

1. Create an instance of the Vignere class with a valid key.
2. Use the `encrypt()` function to encrypt a message.
3. Use the `decrypt()` function to decrypt an encrypted message.
4. Optionally, use the `isEncrypted()` function to check the correctness of encryption.
5. Change the key using the `setKey()` function if needed.

## Example

```cpp
#include "vignere.h"

int main() {
    // Create Vignere instance with key "KEY"
    Vignere vignereCipher("KEY");

    // Encrypt a message
    std::string encryptedMsg = vignereCipher.encrypt("HELLO");

    // Decrypt the message
    std::string decryptedMsg = vignereCipher.decrypt(encryptedMsg);

    // Check if the string is correctly encrypted
    bool isCorrect = vignereCipher.isEncrypted(encryptedMsg, decryptedMsg);

    // Output results
    std::cout << "Encrypted: " << encryptedMsg << std::endl;
    std::cout << "Decrypted: " << decryptedMsg << std::endl;
    std::cout << "Is Correct: " << std::boolalpha << isCorrect << std::endl;

    return 0;
}
```

## References

1. [Doxygen Documentation](https://www.doxygen.nl/index.html)
2. [ChatGPT for Doxygen Main Page](https://chat.openai.com/)
