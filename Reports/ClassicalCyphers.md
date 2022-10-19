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

* Each cypher was implemented in dedicated header as a dedicated class with its' methods (encrypt,decrypt), which are
  the implementation of the cyphers.
* myModulo function was created to take into account the negative integers.

### Caesar Cypher

#### Encryption

Implementation of Caesar Cypher is pretty much simple,
encryption implementation consisting of:

* Omiting spaces when encrypting (line 2)
* Encrypt char, by adding to a letter the key and do (mod 26).The reason
  of substracting 65, is to obtain the count of letters from 0.

```
1.for (auto i: message) {
2.        if (i != 32) {
3.            encryptedMessage += char(myModulo(int(toupper(i) - 65 + substitutionKey), 26) + 65);
4.        }
5.    }
```

#### Decryption

Decryption is similar to encryption, the only difference being
that we substract from the encrypted letter the key and do (mod 26).

```
 for (auto i: encryptedMessage) {
        decryptedMessage += char(myModulo(int(i) - 65 - substitutionKey, 26) + 65);
    }
```

### Caesar Cypher with Alphabet Permutation

#### Encryption

First of all, we take the keyword, eliminate all letters that
are repeating in it, and after we add all the alphabet letters,
that were not added yet. Finally, we obtain the string alphabet,
which I have used, which is basically an alphabet permutation.
Finally, I perform the same logic as in simple Caesar Cypher,
Encrpyted letter is initial letter count number + key and (mod 26).

```
for (auto i: message) {
        if (i != 32) {
            encryptedMessage += alphabet[myModulo(int(alphabet.find(char(toupper(i)))) + substitutionKey, 26)];
        }
    }
```

#### Decrpytion

Decryption is the same as encrpytion, difference being that
we take the encrypted letter and substract the key.

```
for (auto i: encryptedMessage) {
decryptedMessage += alphabet[myModulo(int(alphabet.find(i)) - substitutionKey, 26)];
}
```

### Vigenere Cypher

#### Encryption

First of all, we remove spaces in the initial spaces.
Next, we take the each letter count from initial message,
add to it the corresponding letter from the keyWord and do
(mod 26). It is similar to Caesar Cypher, but each time we do
not add a constant key, but each corresponding keyWord's letter count.

```
 message.erase(remove_if(message.begin(), message.end(), ::isspace), message.end());

    for (int i = 0; i < message.length(); ++i) {
        encryptedMessage += char(myModulo(toupper(message[i]) - 65 +
                                          toupper(keyWord[myModulo(i, int(keyWord.length()))]) - 65, 26) + 65);
    }
```

#### Decryption

When decrypting, we take the encrypted letter and substract
the corresponding's keyWord letter and do (mod 26).

```
 for (int i = 0; i < encryptedMessage.length(); ++i) {
        decryptedMessage += char(myModulo(toupper(encryptedMessage[i]) -
                                          toupper(keyWord[myModulo(i, int(keyWord.length()))]), 26) + 65);
    }
```

### Playfair Cypher

#### Encryption

Firstly, we find letters that are the same when selecting them 2by2,
and add Xs. If the length of the message is odd ,we add Z at the end.
Next, we check letters 2 by 2, and implement the 3 cases, when
letters are in the same row, column , or none of the first 2 cases.
Important to mention is that alphabet matrix gives the letters
for given indexes AND map_letters gives the coresponding indexes
for given letter in the alphabet matrix.

```
for (int i = 0; i < message.length(); i += 2) {

        if (map_letters[message[i]].second == map_letters[message[i + 1]].second) {

            encryptedMessage += alphabet[myModulo(map_letters[message[i]].first + 1, 5)]
            [map_letters[message[i]].second];

            encryptedMessage += alphabet[myModulo(map_letters[message[i + 1]].first + 1, 5)]
            [map_letters[message[i + 1]].second];

        } else if (map_letters[message[i]].first == map_letters[message[i + 1]].first) {

            encryptedMessage += alphabet[map_letters[message[i]].first]
            [myModulo(map_letters[message[i]].second + 1, 5)];

            encryptedMessage += alphabet[map_letters[message[i + 1]].first]
            [myModulo(map_letters[message[i + 1]].second + 1, 5)];

        } else {

            encryptedMessage += alphabet[map_letters[message[i]].first]
            [map_letters[message[i + 1]].second];

            encryptedMessage += alphabet[map_letters[message[i + 1]].first]
            [map_letters[message[i]].second];

        }
    }
 ```

#### Decryption

Decryption is the same as encryption.

## Conclusions / Screenshots / Results

All the results can be seen in the main.cpp program, where all the cyphers have been tested by me.
The results correspond to the expected ones, as I was getting the same message after encryption and decryption.
Also, all possible letters that cypher can encrypt, encrypt and decrypt in the same letters.
