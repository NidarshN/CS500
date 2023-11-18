#include <string>
#include <iostream>

/*!
@mainpage Vignere Cipher Implementation in C++

@section intro Introduction
This documentation provides information on the Vignere cipher implementation in C++. The Vignere cipher is a method of encrypting alphabetic text using a simple form of polyalphabetic substitution. The implementation includes a class named Vignere, which allows encryption, decryption, and key manipulation.

@section features Features
- Encryption of a given string using a specified Vignere cipher
- Decryption of an encrypted string using a specified Vignere cipher
- Validation to check if a given string is correctly encrypted
- Dynamic key setting for the Vignere cipher

@section usage Usage
To use the Vignere cipher implementation, follow these steps:
1. Create an instance of the Vignere class with a valid key.
2. Use the encrypt() function to encrypt a message.
3. Use the decrypt() function to decrypt an encrypted message.
4. Optionally, use the isEncrypted() function to check the correctness of encryption.
5. Change the key using the setKey() function if needed.

@section example Example
@code
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
@endcode

@section note Note
Make sure to handle the key securely as it directly influences the security of the Vignere cipher.

*/

class Vignere {
    public: 
        //! Constructor for Vignère class which takes string key containing upper class characters.
        /*!
            @param key A string containing upper class characters assigned to be the vignère cipher
        */
        Vignere(std::string key);

        //! Destructor for Vignère class
        /*!
            Used to clear out heap allocated memory 
        */
        ~Vignere();

        //! Function to encrypt a given string using a specified vignère cipher
        /*!
            @param msg A string containing message to be encrypted
            @return std::string Returns an encrypted string
        */
        std::string encrypt(std::string msg);

        //! Function to decrypt an encrypted string using a specified vignère cipher
        /*!
            @param msg A string containing encrypted message
            @return std::string Returns the decrypted string
        */
        std::string decrypt(std::string msg);

        //! Function to check if a given string is correctly encrypted 
        /*!
            @param encryptedMsg A string containing encrypted message
            @param decryptedMessage A string containing decrypted message
            @return bool Returns true if the string is correctly encrypted else returns false
        */
        bool isEncrypted(std::string encryptedMsg, std::string decryptedMessage);

        //! Function to set the vignère cipher
        /*!
            @param key A string containing uppercase characters to be set as vignère cipher
        */
        void setKey(std::string key);

    private:
        std::string cipherKey;
};