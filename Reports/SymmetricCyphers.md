# Symmetric Cyphers

### Course: Cryptography & Security

### Author: Boris Cristian

----

## Objectives:

* Implement RC4 Stream Cipher
* Implement Blowfish Block Cipher

## Implementation description

### RC4 Stream Cipher

#### Encryption

Basically, I was counting the permutation vector S once at initialization, and after this step
at encryption I was copying that vector, and then working with it, retrieving for each char in message the
corresponding keyStreamBYTE, used for XOR operation.

```
 int i = 0, j = 0;
    for (auto ch: message) {
        i = (i + 1) % 256;
        j = (j + S1[i]) % 256;
        swap(S1[i], S1[j]);
        int keyStreamBYTE = S1[(S1[i] + S1[j]) % 256];

        encryptedMessage += bitset<8>(ch xor keyStreamBYTE).to_string();
    }
```

In the code above, it is easy understandable that encryption process consists of taking each char from
message, and XORing it with the corresponding keyStreamBYTE.

#### Decryption

The decryption process is the same, as this is a Symmetric Cipher, taking each byte and XORing it with
the corresponding keyStreamByte. It is important to mention that

###### if msgByte XOR keyByte = cypherByte, then cypherByte XOR keyByte = msgByte.


### Blowfish Cypher

#### Encryption 

Blowfish cypher is encrypting 64-bit message chunks, and outputs 64 bits of cypher text.
First of all the values of S box are hardcoded, and at the initialization I take care of XORing each
32-bits of key with P[i] string array. 

Next step of encrypting are the 16 rounds through which the plain text goes.

``` 
for (int j = 0; j < 16; ++j) {
string n_r_side;
n_r_side = bitset<32>(bitset<32>(l_side) xor bitset<32>(P[j])).to_string();

            l_side = bitset<32>(bitset<32>(F(bitset<32>(bitset<32>(l_side) xor bitset<32>(P[j])).to_string()))
                                xor bitset<32>(r_side)).to_string();

            r_side = n_r_side;
        }
```

Basically, at each round the left 32-bits out of 64 , are XORed with corresponding P[i], introduced then
in F function , and the result is XORed with right 32-bits.

The new right 32-bits is the old left 32-bits XORed with corresponding P[i].

And, at the end there is the final XOR using the P[16] and P[17].
```
 encryptedMessage += bitset<32>(bitset<32>(r_side) xor bitset<32>(P[17])).to_string();
        encryptedMessage += bitset<32>(bitset<32>(l_side) xor bitset<32>(P[16])).to_string();
``` 


#### Decryption

As this is a symmetric Cypher, the decryption process is the same with the encryption, just that
the rounds go in reverse order, first round being the 17-one, and thus using the P[17] value first.

At the end, the final XOR is done using the P[1] and P[0].


## Conclusions / Screenshots / Results

All the results can be seen in the main.cpp program, where both cyphers have been tested by me. The results correspond
to the expected ones, as I was getting the same message after encryption and decryption. Also, all possible letters that
cypher can encrypt, encrypt and decrypt in the same letters.