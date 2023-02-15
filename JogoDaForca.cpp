#include <iostream>
#include <string>
using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";

bool string_char_find(char char_to_find, string string_to_search)
{
    // for (int i = 0; i < string_to_search.length(); i++) {
    //     if (string_to_search[i] == toupper(char_to_find)) {
    //         return true;
    //     }
    // }
    for (char letra : string_to_search) {
        if (letra == toupper(char_to_find)) {
            return true;
        }
    }
    return false;
}

int main()
{
    cout << PALAVRA_SECRETA << endl;

    bool acertou = false;
    bool enforcou = false;

    while (!acertou && !enforcou) {
        char chute;
        cin >> chute;

        if (string_char_find(chute, PALAVRA_SECRETA)) {
            cout << "Voce acertou! Seu chute esta na palavra." << endl;
        } else {
            cout << "Voce errou! Seu chute nao esta na palavra." << endl;
        }
    }
}