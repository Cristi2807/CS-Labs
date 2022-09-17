#include <iostream>
#include "caesar.h"
#include "caesar_perm.h"
#include "vigenere.h"
#include "playfair.h"

int main() {

    // Simple CaesarCypher obj
    auto c = CaesarCypher(3);

    //Encryption gives LWLVPRQGDB
    cout << c.encryptMessage("ITISMONDAY") << endl;

    //Check if LWLVPRQGDB gives ITISMONDAY
    cout << c.decryptMessage("LWLVPRQGDB") << endl;

    //Simple test to see if message after encr and decr is the same
    cout << c.decryptMessage(c.encryptMessage("ITISWEDNESDAY")) << endl;

    //Check all the possible letters to encr and then decr in same letter
    cout << c.decryptMessage(
            c.encryptMessage("abcdefghijklmnopqrstuvwxyz")) << endl;


    cout << endl;


    //Caesar with permutationKey obj
    auto cp = CaesarPermCypher(3, "saptamana");

    //Encryption gives XDLYHWTLBA
    cout << cp.encryptMessage("UNIVERSITY") << endl;

    //Check if XDLYHWTLBA gives UNIVERSITY
    cout << cp.decryptMessage("XDLYHWTLBA") << endl;

    //Simple test to see if message is same after encr and decr
    cout << cp.decryptMessage(cp.encryptMessage("JUSTSMILE")) << endl;

    //Check all the possible letters to encr and then decr in same letter
    cout << cp.decryptMessage(cp.encryptMessage("abcdefghijklmnopqrstuvwxyz")) << endl;

    cout << endl;


    auto vigenere = VigenereCypher("LEMON");

    //Encryption gives LXFOPVEFRNHR
    cout << vigenere.encryptMessage("attackatdawn") << endl;

    //Check if LXFOPVEFRNHR gives ATTACKATDAWN
    cout << vigenere.decryptMessage("LXFOPVEFRNHR") << endl;

    //Check if message remains same after encr and decr
    cout << vigenere.decryptMessage(vigenere.encryptMessage("SUNDAYEVENING")) << endl;

    //Check all the possible letters to encr and then decr in same letter
    cout << vigenere.decryptMessage(vigenere.encryptMessage("abcdefghijklmnopqrstuvwxyz")) << endl;

    cout<<endl;


    //!Letter Q , as most rarely used was omitted from alphabet in Playfair Cypher

    PlayfairCypher playfair = PlayfairCypher("monarchy");

    //Encryption gives GATKMZCKRPTX
    cout << playfair.encryptMessage("instruments") << endl;

    //Check if GATKMZCKRPTX gives INSTRUMENTSZ
    cout << playfair.decryptMessage("GATKMZCKRPTX") << endl;

    //Check if message remains the same
    cout << playfair.decryptMessage(playfair.encryptMessage("MESSAGE")) << endl;

    //Check if all possible letters encrypt and decrypt in same letters
    cout << playfair.decryptMessage(
            playfair.encryptMessage("ABCDEFGHIJKLMNOPRSTUVWXYZ"));
    cout<<endl;

    return 0;
}