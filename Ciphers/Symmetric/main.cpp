#include <iostream>
#include <cassert>
#include "blockCipher.h"
#include "streamCipher.h"

void checkRC4() {

    RC4StreamCypher RC4Machine = RC4StreamCypher({64, 26, 19, 30, 22});

    assert(RC4Machine.encryptMessage("Eu sunt Cristi.") == "000000011101110100011001001101000001001110001101001"
                                                           "100110110000010111000001101101010001010010010111000100001000101110001");

    assert(RC4Machine.decryptMessage(RC4Machine.encryptMessage("This is the most secret information."))
           == "This is the most secret information.");

    assert(RC4Machine.decryptMessage(RC4Machine.encryptMessage("AbCdEfGhIjKlMnOpQrStUvWxYz"))
           == "AbCdEfGhIjKlMnOpQrStUvWxYz");

    cout << "Checkpoints passed for RC4 Cypher" << endl;
}

void checkBlowfish() {

    BlowfishBlockCypher BlowfishMachine = BlowfishBlockCypher("This is the most secret key.");

    assert(BlowfishMachine.encryptMessage("Eu sunt Cristi. ") == "111101001001001100010000111100010101100010101"
                                                                 "100010000110100110011001010110111110000001001010001100"
                                                                 "10000010101110000001011110111");

    assert(BlowfishMachine.decryptMessage(BlowfishMachine.encryptMessage("This is the most secret information.    "))
           == "This is the most secret information.    ");

    assert(BlowfishMachine.decryptMessage(BlowfishMachine.encryptMessage("AbCdEfGhIjKlMnOpQrStUvWxYz      "))
           == "AbCdEfGhIjKlMnOpQrStUvWxYz      ");


    cout << "Checkpoints passed for Blowfish Cypher" << endl;

}

int main() {

    checkRC4();

    checkBlowfish();

    return 0;
}
