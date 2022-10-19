#include <iostream>
#include <cassert>
#include "caesar.h"
#include "caesar_perm.h"
#include "playfair.h"
#include "vigenere.h"

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

int main() {

    checkCaesar();

    checkCaesarPerm();

    checkVigenere();

    checkPlayfair();

    return 0;
}