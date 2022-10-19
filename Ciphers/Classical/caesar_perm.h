#include <utility>
#include <algorithm>
#include <set>


#ifndef CS_LABS_CAESAR_PERM_H
#define CS_LABS_CAESAR_PERM_H

using namespace std;

class CaesarPermCypher {
private:
    int substitutionKey;
    string permutationKey;
    string alphabet;

public:
    CaesarPermCypher(int substitutionKey, string permutationKey);

    [[nodiscard]] string encryptMessage(const string &message) const;

    [[nodiscard]] string decryptMessage(const string &encryptedMessage) const;

    static int myModulo(int a, int b);

    static string permKeyNoDuplic(string permKey);
};

string CaesarPermCypher::encryptMessage(const string &message) const {

    string encryptedMessage;

    for (auto i: message) {
        if (i != 32) {
            encryptedMessage += alphabet[myModulo(int(alphabet.find(char(toupper(i)))) + substitutionKey, 26)];
        }
    }

    return encryptedMessage;
}

string CaesarPermCypher::decryptMessage(const string &encryptedMessage) const {

    string decryptedMessage;

    for (auto i: encryptedMessage) {
        decryptedMessage += alphabet[myModulo(int(alphabet.find(i)) - substitutionKey, 26)];
    }

    return decryptedMessage;
}

int CaesarPermCypher::myModulo(int a, int b) {
    return (b + (a % b)) % b;
}

CaesarPermCypher::CaesarPermCypher(int substitutionKey, string permutationKey) : substitutionKey(
        substitutionKey), permutationKey(std::move(permutationKey)) {

    set<char> charsWeHave;
    string permKeyUniqueLetts = CaesarPermCypher::permKeyNoDuplic(this->permutationKey);
    alphabet += permKeyUniqueLetts;

    for (char &permKeyUniqueLett: permKeyUniqueLetts) {
        charsWeHave.insert(permKeyUniqueLett);
    }

    for (int i = 65; i < 91; ++i) {
        if (!charsWeHave.count(char(i))) alphabet += char(i);
    }

}

string CaesarPermCypher::permKeyNoDuplic(string permKey) {

    transform(permKey.begin(), permKey.end(), permKey.begin(), ::toupper);

    for (int i = 0; i < permKey.length() - 1; ++i) {
        replace(permKey.begin() + i + 1, permKey.end(), permKey[i], '*');
    }

    permKey.erase(remove(permKey.begin(), permKey.end(), '*'), permKey.end());

    return permKey;
}

#endif //CS_LABS_CAESAR_PERM_H
