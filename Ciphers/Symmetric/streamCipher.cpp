#include "streamCipher.h"

string RC4StreamCypher::encryptMessage(const string &message) {

    string encryptedMessage;

    vector<int> S1 = S;

    int i = 0, j = 0;
    for (auto ch: message) {
        i = (i + 1) % 256;
        j = (j + S1[i]) % 256;
        swap(S1[i], S1[j]);
        int keyStreamBYTE = S1[(S1[i] + S1[j]) % 256];

        encryptedMessage += bitset<8>(ch xor keyStreamBYTE).to_string();
    }

    return encryptedMessage;
}

string RC4StreamCypher::decryptMessage(const string &encryptedMessage) {

    string decryptedMessage;

    vector<int> S1 = S;

    int i = 0, j = 0;
    for (int i1 = 0; i1 < encryptedMessage.length(); i1 += 8) {
        i = (i + 1) % 256;
        j = (j + S1[i]) % 256;
        swap(S1[i], S1[j]);
        int keyStreamBYTE = S1[(S1[i] + S1[j]) % 256];

        decryptedMessage += char(bitset<8>(encryptedMessage.substr(i1, 8)).to_ulong() xor keyStreamBYTE);
    }

    return decryptedMessage;
}

RC4StreamCypher::RC4StreamCypher(const vector<int> &key) : key(key) {

    vector<int> K;

    for (int i = 0; i < 256; ++i) {
        S.push_back(i);
        K.push_back(key[i % key.size()]);
    }

    int j = 0;
    for (int i = 0; i < 256; ++i) {
        j = (j + S[i] + K[i]) % 256;
        swap(S[i], S[j]);
    }

}
