#include <iostream>
#include <cassert>
#include "rsa.h"

void checkRSA() {

    RSAMachine rsaMachine = RSAMachine(104717, 104723);

    assert(rsaMachine.encryptMessage("Eu sunt Cristi.") ==
           "000074463532525890030012421160697300000034359738368002660019"
           "880468750030012421160697300194871710000000002826219734466560"
           "000003435973836800006060711605323002502268791287040014071004"
           "226562500266001988046875002826219734466560014071004226562500"
           "000435817657216");


    assert(rsaMachine.decryptMessage(rsaMachine.encryptMessage("This is the most secret information."))
           == "This is the most secret information.");

    assert(rsaMachine.decryptMessage(rsaMachine.encryptMessage("AbCdEfGhIjKlMnOpQrStUvWxYz      "))
           == "AbCdEfGhIjKlMnOpQrStUvWxYz      ");


    cout << "Checkpoints passed for RSA Cypher" << endl;

}

int main() {

    checkRSA();

    return 0;
}