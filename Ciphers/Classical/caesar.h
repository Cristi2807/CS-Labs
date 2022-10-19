
#ifndef CS_LABS_CAESAR_H
#define CS_LABS_CAESAR_H

using namespace std;

class CaesarCypher {
private:
    int substitutionKey;

public:
    explicit CaesarCypher(int substitutionKey) : substitutionKey(substitutionKey) {}

    [[nodiscard]] string encryptMessage(const string &message) const;

    [[nodiscard]] string decryptMessage(const string &encryptedMessage) const;

    static int myModulo(int a, int b);
};

string CaesarCypher::encryptMessage(const string &message) const {

    string encryptedMessage;

    for (auto i: message) {
        if (i != 32) {
            encryptedMessage += char(myModulo(int(toupper(i) - 65 + substitutionKey), 26) + 65);
        }
    }
    return encryptedMessage;
}

string CaesarCypher::decryptMessage(const string &encryptedMessage) const {

    string decryptedMessage;

    for (auto i: encryptedMessage) {
        decryptedMessage += char(myModulo(int(i) - 65 - substitutionKey, 26) + 65);
    }

    return decryptedMessage;
}

int CaesarCypher::myModulo(int a, int b) {
    return (b + (a % b)) % b;
}


#endif //CS_LABS_CAESAR_H
