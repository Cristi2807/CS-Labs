# The title of the work

### Course: Cryptography & Security
### Author: Boris Cristian

----

## Objectives:

* Implement simple Caesar Cypher
* Implement Caesar with a permutation of alphabet
* Implement Vigenere Cypher
* Implement PLayfair Cypher


## Implementation description

* Each cypher was implemented in dedicated header as a dedicated class with its' methods (encrypt,decrypt), which are the implementation of the cyphers.
* myModulo function was created to take into account the negative integers.


* ```class CaesarCypher {
private:
    int substitutionKey;

public:
    explicit CaesarCypher(int substitutionKey) : substitutionKey(substitutionKey) {}

    [[nodiscard]] string encryptMessage(const string &message) const;

    [[nodiscard]] string decryptMessage(const string &encryptedMessage) const;

    static int myModulo(int a, int b);
};
```



## Conclusions / Screenshots / Results
All the results can be seen in the main.cpp program, where all the cyphers have been tested by me.
The results correspond to the expected ones, as I was getting the same message after encryption and decryption.
Also, all possible letters that cypher can encrypt, encrypt and decrypt in the same letters.
