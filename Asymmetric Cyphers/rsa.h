#include <cmath>
#include <string>

#ifndef CS_LABS_RSA_H
#define CS_LABS_RSA_H

using namespace std;

class RSAMachine {
private:
    double d;

public:
    double n;
    double e;

    RSAMachine(double p, double q);

    [[nodiscard]] string encryptMessage(const string& message) const;

    [[nodiscard]] string decryptMessage(const string &encrpytedMessage) const;

    static int gcd(int a, int b);

};


#endif //CS_LABS_RSA_H