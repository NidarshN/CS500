#include "vignere.h"
#include <cctype>

Vignere::Vignere(std::string key)
{
    setKey(key);
}

Vignere::~Vignere(){
    
}

std::string Vignere::encrypt(std::string msg){
    std::string cipheredText = "";
    int j = 0;
    for(int i = 0; i < msg.size(); i++){
        if(!isspace(msg[i])){
            if(j == cipherKey.size())
                j = 0;
            char cipheredChar = (msg[i] + cipherKey[j]) % 26;
            cipheredChar += 'A';
            cipheredText += cipheredChar;
            j++;
        }else{
            cipheredText += msg[i];
        }
    }
    return cipheredText;
}

std::string Vignere::decrypt(std::string msg){
    std::string originalMsg = "";
    int j = 0;
    for(int i = 0; i < msg.size(); i++){
        if(!std::isspace(msg[i])){
            if(j == cipherKey.size())
                j = 0;
            char cipheredChar = (msg[i] - cipherKey[j] + 26) % 26;
            cipheredChar += 'A';
            originalMsg += cipheredChar;
            j++;
        }else{
            originalMsg += msg[i];
        }
    }
    return originalMsg;
}

bool Vignere::isEncrypted(std::string encryptedMsg, std::string decryptedMessage){
    std::string decryptMsg = decrypt(encryptedMsg);
    if(decryptMsg.compare(decryptedMessage) == 0)
        return true;
    else
        return false;
}

void Vignere::setKey(std::string key){
    cipherKey = key;
}
