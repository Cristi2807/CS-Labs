#include <iostream>
#include <iomanip>
#include "rsa.h"

const int NR_OF_DIGITS = 17;

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
    cout.precision(NR_OF_DIGITS);

    string encryptedMessage;

    for (char i: message) {
        double c = pow(i, e);

        stringstream stream;
        stream << fixed << setprecision(0) << c;
        std::string ch = stream.str();

        while (ch.length() < NR_OF_DIGITS) {
            ch = '0' + ch;
        }

        encryptedMessage += ch;
    }

    return encryptedMessage;
}

string RSAMachine::decryptMessage(const string &encryptedMessage) const {
    cout.precision(NR_OF_DIGITS);

    string decryptedMessage;

    for (int i = 0; i < encryptedMessage.length(); i += NR_OF_DIGITS) {
        double m = stod(encryptedMessage.substr(i, NR_OF_DIGITS));
        m = round(fmod(pow(m, d), n));

        decryptedMessage += char(m);
    }


    return decryptedMessage;
}

string RSAMachine::encryptMessagePrivateKey(const string &message) const {
    cout.precision(NR_OF_DIGITS);

    string encryptedMessage;

    for (char i: message) {
        double c = pow(i, d) * pow(10, NR_OF_DIGITS - 1);

        stringstream stream;
        stream << fixed << setprecision(0) << c;
        std::string ch = stream.str();

        while (ch.length() < NR_OF_DIGITS) {
            ch = '0' + ch;
        }

        encryptedMessage += ch;
    }

    return encryptedMessage;
}

string RSAMachine::decryptMessagePublicKey(const string &encryptedMessage) const {
    cout.precision(NR_OF_DIGITS);

    string decryptedMessage;

    for (int i = 0; i < encryptedMessage.length(); i += NR_OF_DIGITS) {
        double m = stod(encryptedMessage.substr(i, NR_OF_DIGITS)) * pow(10, -NR_OF_DIGITS + 1);
        m = round(fmod(pow(m, e), n));

        decryptedMessage += char(m);
    }


    return decryptedMessage;
}


