#include <utility>

#ifndef CS_LABS_VIGENERE_H
#define CS_LABS_VIGENERE_H

using namespace std;

class VigenereCypher {
private:
    string keyWord;

public:
    explicit VigenereCypher(string keyWord) : keyWord(std::move(keyWord)) {};

    string encryptMessage(string message);

    string decryptMessage(const string &encryptedMessage);

    static int myModulo(int a, int b);

};

string VigenereCypher::encryptMessage(std::string message) {
    string encryptedMessage;

    message.erase(remove_if(message.begin(), message.end(), ::isspace), message.end());

    for (int i = 0; i < message.length(); ++i) {
        encryptedMessage += char(myModulo(toupper(message[i]) - 65 +
                                          toupper(keyWord[myModulo(i, int(keyWord.length()))]) - 65, 26) + 65);
    }

    return encryptedMessage;
}

string VigenereCypher::decryptMessage(const string &encryptedMessage) {

    string decryptedMessage;

    for (int i = 0; i < encryptedMessage.length(); ++i) {
        decryptedMessage += char(myModulo(toupper(encryptedMessage[i]) -
                                          toupper(keyWord[myModulo(i, int(keyWord.length()))]), 26) + 65);
    }

    return decryptedMessage;
}


int VigenereCypher::myModulo(int a, int b) {
    return (b + (a % b)) % b;
}


#endif //CS_LABS_VIGENERE_H
