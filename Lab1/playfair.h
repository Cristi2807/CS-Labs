#include <utility>
#include <map>

using namespace std;

#ifndef CS_LABS_PLAYFAIR_H
#define CS_LABS_PLAYFAIR_H


class PlayfairCypher {
private:
    string keyWord;
    char alphabet[5][5];
    map<char, pair<int, int>> map_letters;

public:
    explicit PlayfairCypher(string keyWord);

    string encryptMessage(string message);

    string decryptMessage(string encryptedMessage);

    static string keyWordNoDuplic(string key);

    static int myModulo(int a, int b);

};

PlayfairCypher::PlayfairCypher(string keyWord) : keyWord(std::move(keyWord)) {

    size_t foundQ = keyWordNoDuplic(this->keyWord).find('Q');

    if (foundQ == -1) {
        string keyNoDuplicLetts = keyWordNoDuplic(this->keyWord);
        string remainingLetts;
        string alphabetPermutation;

        for (int i = 65; i < 91; ++i) {
            if (i != 81) {
                size_t found = keyNoDuplicLetts.find(char(i));
                if (found == -1) remainingLetts += char(i);
            }
        }

        alphabetPermutation = keyNoDuplicLetts + remainingLetts;

        for (int i = 0; i < alphabetPermutation.length(); ++i) {
            alphabet[i / 5][i % 5] = alphabetPermutation[i];
            map_letters[alphabetPermutation[i]] = make_pair(i / 5, i % 5);
        }


    } else {
        cout << "Letter Q detected in keyWord, which is not accepted in Playfair Cypher.";
        return;
    }

}

string PlayfairCypher::encryptMessage(string message) {
    string encryptedMessage;

    transform(message.begin(), message.end(), message.begin(), ::toupper);

    for (int i = 0; i < message.length() - 1; ++i) {
        if (message[i] == message[i + 1] && i % 2 == 0) message.insert(i + 1, "X");
    }

    if (message.length() % 2 == 1) message += 'Z';


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

    return encryptedMessage;
}

string PlayfairCypher::decryptMessage(string encryptedMessage) {
    string decryptedMessage;

    transform(encryptedMessage.begin(), encryptedMessage.end(), encryptedMessage.begin(), ::toupper);


    for (int i = 0; i < encryptedMessage.length(); i += 2) {

        if (map_letters[encryptedMessage[i]].second == map_letters[encryptedMessage[i + 1]].second) {

            decryptedMessage += alphabet[myModulo(map_letters[encryptedMessage[i]].first - 1, 5)]
            [map_letters[encryptedMessage[i]].second];

            decryptedMessage += alphabet[myModulo(map_letters[encryptedMessage[i + 1]].first - 1, 5)]
            [map_letters[encryptedMessage[i + 1]].second];

        } else if (map_letters[encryptedMessage[i]].first == map_letters[encryptedMessage[i + 1]].first) {

            decryptedMessage += alphabet[map_letters[encryptedMessage[i]].first]
            [myModulo(map_letters[encryptedMessage[i]].second - 1, 5)];

            decryptedMessage += alphabet[map_letters[encryptedMessage[i + 1]].first]
            [myModulo(map_letters[encryptedMessage[i + 1]].second - 1, 5)];

        } else {

            decryptedMessage += alphabet[map_letters[encryptedMessage[i]].first]
            [map_letters[encryptedMessage[i + 1]].second];

            decryptedMessage += alphabet[map_letters[encryptedMessage[i + 1]].first]
            [map_letters[encryptedMessage[i]].second];

        }
    }

    return decryptedMessage;
}

//Obtain the key without repeating letters in it.
string PlayfairCypher::keyWordNoDuplic(string key) {

    transform(key.begin(), key.end(), key.begin(), ::toupper);

    for (int i = 0; i < key.length() - 1; ++i) {
        replace(key.begin() + i + 1, key.end(), key[i], '*');
    }

    key.erase(remove(key.begin(), key.end(), '*'), key.end());

    return key;
}

//Modulo function that takes into account negative integers
int PlayfairCypher::myModulo(int a, int b) {
    return (b + (a % b)) % b;
}


#endif //CS_LABS_PLAYFAIR_H
