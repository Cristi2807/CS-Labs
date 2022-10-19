#include <utility>
#include <cstring>
#include <sstream>
#include <bitset>

using namespace std;

#ifndef CS_LABS_BLOCKCIPHER_H
#define CS_LABS_BLOCKCIPHER_H

class BlowfishBlockCypher {
    string key;
    string P[18] = {"243f6a88", "85a308d3", "13198a2e", "03707344", "a4093822",
                    "299f31d0", "082efa98", "ec4e6c89", "452821e6", "38d01377",
                    "be5466cf", "34e90c6c", "c0ac29b7", "c97c50dd", "3f84d5b5",
                    "b5470917", "9216d5d9", "8979fb1b"};

public:
    explicit BlowfishBlockCypher(string key);

    string encryptMessage(const string &message);

    string decryptMessage(const string &encryptedMessage);

    static string F(const string &bits);

};


#endif //CS_LABS_BLOCKCIPHER_H
