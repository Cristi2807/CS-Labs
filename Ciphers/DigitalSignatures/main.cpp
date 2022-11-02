#include "../Asymmetric/rsa.h"
#include <cassert>
#include <iostream>

void checkDS() {

    RSAMachine rsaMachine = RSAMachine(104717, 104723);

    string message = "This is the message to be checked.";

    string messageHash = to_string(hash<string>{}(message));

    string digitalSignature = rsaMachine.encryptMessagePrivateKey(messageHash);

    assert(rsaMachine.decryptMessagePublicKey(digitalSignature) == messageHash);


    message = "A new message for new test.";

    messageHash = to_string(hash<string>{}(message));

    digitalSignature = rsaMachine.encryptMessagePrivateKey(messageHash);

    assert(rsaMachine.decryptMessagePublicKey(digitalSignature) == messageHash);


    cout << "Tests passed for Digital Signature!";
}

int main() {

    checkDS();

    return 0;
}
