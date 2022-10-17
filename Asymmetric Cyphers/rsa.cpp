#include <iostream>
#include <iomanip>
#include "rsa.h"

RSAMachine::RSAMachine(double p, double q) {

    n = p * q;
    double phi = (p - 1) * (q - 1);

    e = 7;
    while (e < phi) {
        double track = gcd(int(e), int(phi));
        if (track == 1)
            break;
        else
            e++;
    }

    d = fmod(1 / e, phi);
}

int RSAMachine::gcd(int a, int b) {
    int t;
    while (true) {
        t = a % b;
        if (t == 0)
            return b;
        a = b;
        b = t;
    }
}

string RSAMachine::encryptMessage(const string &message) const {
    cout.precision(17);

    string encryptedMessage;

    for (char i: message) {
        double c = pow(i, e);

        stringstream stream;
        stream << fixed << setprecision(0) << c;
        std::string ch = stream.str();

        while (ch.length() < 17) {
            ch = '0' + ch;
        }

        encryptedMessage += ch;
    }

    return encryptedMessage;
}

string RSAMachine::decryptMessage(const string &encrpytedMessage) const {
    cout.precision(17);

    string decryptedMessage;

    for (int i = 0; i < encrpytedMessage.length(); i += 17) {
        double m = stod(encrpytedMessage.substr(i, 17));
        m = round(fmod(pow(m, d), n));

        decryptedMessage += char(m);
    }


    return decryptedMessage;
}
