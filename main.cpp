#include <iostream>
#include <cassert>
#include "Classical Cyphers/caesar.h"
#include "Classical Cyphers/caesar_perm.h"
#include "Classical Cyphers/vigenere.h"
#include "Classical Cyphers/playfair.h"
#include "Symmetric Cyphers/streamCipher.h"
#include "Symmetric Cyphers/blockCipher.h"

void checkCaesar() {

    // Simple CaesarCypher obj
    auto c = CaesarCypher(3);

    assert(c.encryptMessage("IT IS MONDAY") == "LWLVPRQGDB");

    assert(c.decryptMessage(c.encryptMessage("IT IS WEDNESDAY")) == "ITISWEDNESDAY");

    assert(c.decryptMessage(c.encryptMessage("abcdefghijklmnopqrstuvwxyz")) == "ABCDEFGHIJKLMNOPQRSTUVWXYZ");


    cout << "Checkpoints passed for Simple Caesar Cypher" << endl;

}


void checkCaesarPerm() {

    //Caesar with permutationKey obj
    auto cp = CaesarPermCypher(3, "saptamana");


    assert(cp.encryptMessage("UNIVERSITY") == "XDLYHWTLBA");


    assert(cp.decryptMessage(cp.encryptMessage("JUST SMILE")) == "JUSTSMILE");


    assert(cp.decryptMessage(cp.encryptMessage("abcdefghijklmnopqrstuvwxyz")) == "ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    cout << "Checkpoints passed for Perm Caesar Cypher" << endl;

}


void checkVigenere() {

    auto vigenere = VigenereCypher("LEMON");


    assert(vigenere.encryptMessage("attack at dawn") == "LXFOPVEFRNHR");


    assert(vigenere.decryptMessage(vigenere.encryptMessage("SUNDAY EVENING")) == "SUNDAYEVENING");


    assert(vigenere.decryptMessage(vigenere.encryptMessage("abcdefghijklmnopqrstuvwxyz")) ==
           "ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    cout << "Checkpoints passed for Vigenere Cypher" << endl;


}

void checkPlayfair() {

    //!Letter Q , as most rarely used was omitted from alphabet in Playfair Cypher

    PlayfairCypher playfair = PlayfairCypher("monarchy");


    assert(playfair.encryptMessage("instruments create sounds") == "GATKMZCKRPKBMJRSIKMVRYTX");


    assert(playfair.decryptMessage(playfair.encryptMessage("MESSAGE is secret")) == "MESXSAGEISSECRET");


    assert(playfair.decryptMessage(
            playfair.encryptMessage("ABCDEFGHIJKLMNOPRSTUVWXYZ")) == "ABCDEFGHIJKLMNOPRSTUVWXYZZ");


    cout << "Checkpoints passed for Playfair Cypher" << endl;

}

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


//    checkCaesar();
//
//    checkCaesarPerm();
//
//    checkVigenere();
//
//    checkPlayfair();
//
//    cout << endl;

    checkRC4();

    checkBlowfish();


    return 0;
}