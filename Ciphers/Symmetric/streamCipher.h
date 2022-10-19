#include <bitset>
#include <vector>

#ifndef CS_LABS_STREAMCIPHER_H
#define CS_LABS_STREAMCIPHER_H

using namespace std;

class RC4StreamCypher {
private:
    vector<int> key;
    vector<int> S;

public:

    string encryptMessage(const string &message);

    string decryptMessage(const string &encryptedMessage);

    explicit RC4StreamCypher(const vector<int> &key);

};


#endif //CS_LABS_STREAMCIPHER_H
