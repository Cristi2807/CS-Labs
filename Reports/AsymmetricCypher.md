# Asymmetric Cyphers

### Course: Cryptography & Security

### Author: Boris Cristian

----

## Objectives:

* Implement RSA Stream Cipher

## Implementation description

### RSA Cipher

#### Encryption

Encryption in RSA was done by taking the char ASCII number, and raising it to the power of e,
which was calculated in constructor, it being the co-prime of phi.

```
 for (char i: message) {
        double c = pow(i, e);

        stringstream stream;
        stream << fixed << setprecision(0) << c;
        std::string ch = stream.str();

        while (ch.length() < 17) {
            ch = '0' + ch;
        }
```

#### Decryption

The decryption proccess is taking each 17 digits from cipher, raises the number to power d,
and then finds the fmod of result with n.

``` 
 for (int i = 0; i < encrpytedMessage.length(); i += 17) {
        double m = stod(encrpytedMessage.substr(i, 17));
        m = round(fmod(pow(m, d), n));

        decryptedMessage += char(m);
    }
```

## Conclusions / Screenshots / Results

All the results can be seen in the main.cpp program, where both cyphers have been tested by me. The results correspond
to the expected ones, as I was getting the same message after encryption and decryption. Also, all possible letters that
cypher can encrypt, encrypt and decrypt in the same letters.