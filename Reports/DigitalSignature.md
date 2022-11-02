# Digital Signature and Hashing

### Course: Cryptography & Security

### Author: Boris Cristian

----

## Objectives:

* Implement RSA Private Key Encryption
* Implement Digital Signature

## Implementation description

### RSA Cipher

#### Encryption

Encryption in RSA was done by taking the char ASCII number, and raising it to the power of d,
which was calculated in constructor, it being the private key.

```
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
```

#### Decryption

The decryption proccess is taking each 17 digits from cipher, raises the number to power e
(the public key), and then finds the fmod of result with n.

``` 
  for (int i = 0; i < encryptedMessage.length(); i += NR_OF_DIGITS) {
        double m = stod(encryptedMessage.substr(i, NR_OF_DIGITS)) * pow(10, -NR_OF_DIGITS + 1);
        m = round(fmod(pow(m, e), n));

        decryptedMessage += char(m);
    }
```

## Conclusions / Screenshots / Results

The idea of the Digital Signature is comparing the hash message with the hash message obtained from
decrypting with Bob's public key. If they match, it means the message was indeed sent by Bob,
being encrypted with his private key.